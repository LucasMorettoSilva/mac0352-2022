#include "change-password-package.h"

ChangePasswordPackage::ChangePasswordPackage(std::string cur_password,
                                             std::string new_password) {
    this->cur_password = cur_password;
    this->new_password = new_password;
}

ChangePasswordPackage::ChangePasswordPackage(ustring recvline) {
    int pos = 3;
    this->header = PackageHeader(recvline);
    read_string(recvline, pos, this->cur_password);
    read_string(recvline, pos, this->new_password);
}

ssize_t ChangePasswordPackage::toString(ustring line) {
    int cur_password_len = this->cur_password.size();
    int new_password_len = this->new_password.size();
    int total_len = cur_password_len + new_password_len + 4;

    this->header.package_type = CHANGE_PASSWORD_PACKAGE;
    this->header.remaning_length = total_len;

    int pos = 0;
    this->header.write(line, pos);
    write_string(line, pos, this->cur_password);
    write_string(line, pos, this->new_password);

    return pos;
}
