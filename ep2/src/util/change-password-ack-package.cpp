#include "change-password-ack-package.h"

ChangePasswordAckPackage::ChangePasswordAckPackage(byte return_code) {
    this->return_code = return_code;
}

ChangePasswordAckPackage::ChangePasswordAckPackage(ustring recvline) {
    int pos = 3;
    this->header = PackageHeader(recvline);
    this->return_code = recvline[pos++];
}

ssize_t ChangePasswordAckPackage::toString(ustring line) {
    this->header.package_type = CHANGE_PASSWORD_ACK_PACKAGE;
    this->header.remaning_length = 1;

    int pos = 0;
    this->header.write(line, pos);
    line[pos++] = this->return_code;

    return pos;
}
