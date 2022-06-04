#include <util.h>

#include <errno.h>
#include <stdio.h>
#include <sys/mman.h>

#include <iostream> //temp

int cmd_str_to_int(const std::string& cmd) {
    if (cmd == "new") return NEW;
    if (cmd == "pass") return PASS;
    if (cmd == "in") return IN;
    if (cmd == "halloffame") return HALLOFFAME;
    if (cmd == "l") return LIST;
    if (cmd == "call") return CALL;
    if (cmd == "play") return PLAY;
    if (cmd == "delay") return DELAY;
    if (cmd == "over") return OVER;
    if (cmd == "out") return OUT;
    if (cmd == "yes") return YES;
    if (cmd == "no") return NO;
    if (cmd == "bye") return BYE;
    return -1;
}

void print_in_hex(ustring s, int len) {
    fprintf(stdout, "'");
    for (int i = 0; i < len; ++i) fprintf(stdout, "%02x ", s[i]);
    fprintf(stdout, "'\n\n");
}

void *custom_malloc(size_t size) {
    void *allocated_bytes = mmap(NULL, size, PROT_READ | PROT_WRITE,
                                 MAP_SHARED | MAP_ANONYMOUS, 0, 0);

    if (allocated_bytes == MAP_FAILED) {
        fprintf(stderr,
                "Failed to allocate the bytes with mmap.\nErrno = "
                "%d.\nExiting...\n",
                errno);
        exit(errno);
    }

    return allocated_bytes;
}

void custom_free(void *addr, size_t size) {
    int err = munmap(addr, size);

    if (err != 0) {
        fprintf(stderr, "Um erro ocorreu ao tentar desalocar um mmap\n");
        exit(errno);
    }
}

void set_str(char *istr, std::string ostr) {
    unsigned long int n = ostr.size();
    for (unsigned long int j = 0; j < n; ++j) { istr[j] = ostr[j]; }
    istr[n] = 0;
}

ustring int_to_2byte_str(int value) {
    ustring ret_str;
    byte b1, b2;
    ret_str = (ustring) malloc(2 * sizeof(uchar));
    b1 = value % (1 << 8);
    b2 = value / (1 << 8);
    ret_str[0] = b1;
    ret_str[1] = b2;
    return ret_str;
}

int byte_str_to_int(ustring recvline, int pos) {
    int value;
    byte b1, b2;
    b1 = recvline[pos];
    b2 = recvline[pos + 1];
    value = b1 + (1 << 8) * b2;
    return value;
}

void write_string(ustring outstr, int &pos, std::string str_to_write) {
    int len = str_to_write.size();
    ustring strlen = int_to_2byte_str(len);
    outstr[pos++] = strlen[0];
    outstr[pos++] = strlen[1];
    free(strlen);
    for (int i = 0; i < len; ++i) { outstr[pos++] = str_to_write[i]; }
}

void read_string(ustring instr, int &pos, std::string &str_to_read) {
    int len = byte_str_to_int(instr, pos);
    pos += 2;
    str_to_read = std::string(len, ' ');
    for (int i = 0; i < len; i++) { str_to_read[i] = (char) instr[pos++]; }
}
