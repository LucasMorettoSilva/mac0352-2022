#include <package-header.h>

PackageHeader::PackageHeader() { }

PackageHeader::PackageHeader(ustring recvline) {
    this->package_type = recvline[0];
    this->remaning_length = byte_str_to_int(recvline, 1);
}

ustring PackageHeader::toString() {
    ustring fixed_header_str;
    fixed_header_str = (ustring) malloc(3 * sizeof(uchar));
    fixed_header_str[0] = this->package_type;
    ustring temp = int_to_2byte_str(this->remaning_length);
    fixed_header_str[1] = temp[0];
    fixed_header_str[2] = temp[1];
    free(temp);

    return fixed_header_str;
}

void PackageHeader::write(ustring line, int &pos) {
    ustring temp = toString();
    for (pos = 0; pos < 3; ++pos) line[pos] = temp[pos];
    free(temp);
}
