#include "logout-package.h"

LogoutPackage::LogoutPackage() {}

LogoutPackage::LogoutPackage(ustring recvline) {
    this->header = PackageHeader(recvline);
}

ssize_t LogoutPackage::toString(ustring line) {
    this->header.package_type = LOGOUT_PACKAGE;
    this->header.remaning_length = 0;

    int pos = 0;
    this->header.write(line, pos);

    return pos;
}
