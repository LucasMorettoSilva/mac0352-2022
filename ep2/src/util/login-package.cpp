#include "login-package.h"

LoginPackage::LoginPackage(std::string user_login, std::string user_password) {
    this->user_login = user_login;
    this->user_password = user_password;
}

LoginPackage::LoginPackage(ustring recvline) {
    int pos = 3;
    this->header = PackageHeader(recvline);
    read_string(recvline, pos, this->user_login);
    read_string(recvline, pos, this->user_password);
}

ssize_t LoginPackage::toString(ustring line) {
    int login_len = this->user_login.size();
    int password_len = this->user_password.size();
    int total_len = login_len + password_len + 4;

    this->header.package_type = LOGIN_PACKAGE;
    this->header.remaning_length = total_len;

    int pos;
    this->header.write(line, pos);
    write_string(line, pos, this->user_login);
    write_string(line, pos, this->user_password);

    return pos;
}
