#include "../includes/util/create-user-package.h"

CreateUserPackage::CreateUserPackage(std::string username,
                                     std::string password) {
    this->username = username;
    this->password = password;
}

CreateUserPackage::CreateUserPackage(ustring recvline) {
    int pos = 3;
    this->header = PackageHeader(recvline);
    read_string(recvline, pos, this->username);
    read_string(recvline, pos, this->password);
}

ssize_t CreateUserPackage::toString(ustring line) {
    int name_len = this->username.size();
    int pwd_len = this->password.size();
    int total_len = name_len + pwd_len + 4;

    this->header.package_type = CREATE_USER_PACKAGE;
    this->header.remaning_length = total_len;

    int pos;
    this->header.write(line, pos);
    write_string(line, pos, this->username);
    write_string(line, pos, this->password);

    return pos;
}
