#include "create-user-ack-package.h"

CreateUserAckPackage::CreateUserAckPackage(byte return_code) {
    this->header.package_type = CREATE_USER_ACK_PACKAGE;
    this->header.remaning_length = 1;
    this->return_code = return_code;
}

CreateUserAckPackage::CreateUserAckPackage(ustring recvline) {
    int pos = 3;
    this->header = PackageHeader(recvline);
    this->return_code = recvline[pos];
}

ssize_t CreateUserAckPackage::toString(ustring line) {
    this->header.package_type = CREATE_USER_ACK_PACKAGE;
    this->header.remaning_length = 1;

    int pos;
    this->header.write(line, pos);
    line[pos++] = this->return_code;

    return pos;
}
