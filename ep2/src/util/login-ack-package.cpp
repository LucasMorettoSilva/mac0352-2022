#include "login-ack-package.h"

LoginAckPackage::LoginAckPackage(byte return_code) {
    this->return_code = return_code;
}

LoginAckPackage::LoginAckPackage(ustring recvline) {
    int pos = 3;
    this->header = PackageHeader(recvline);
    this->return_code = recvline[pos++];
}

ssize_t LoginAckPackage::toString(ustring line) {
    this->header.package_type = LOGIN_ACK_PACKAGE;
    this->header.remaning_length = 1;

    int pos;
    this->header.write(line, pos);
    line[pos++] = this->return_code;
    return pos;
}
