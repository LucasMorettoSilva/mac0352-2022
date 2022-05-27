#include "req-connected-users-package.h"

ReqConnectedUsersPackage::ReqConnectedUsersPackage() {}

ReqConnectedUsersPackage::ReqConnectedUsersPackage(ustring recvline) {
    this->header = PackageHeader(recvline);
}

ssize_t ReqConnectedUsersPackage::toString(ustring line) {
    this->header.package_type = REQUEST_ALL_CONNECTED_USERS_PACKAGE;
    this->header.remaning_length = 0;

    int pos = 0;
    this->header.write(line, pos);

    return pos;
}
