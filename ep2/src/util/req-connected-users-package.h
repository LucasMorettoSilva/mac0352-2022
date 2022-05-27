#ifndef EP2_REQ_CONNECTED_USERS_PACKAGE_H
#define EP2_REQ_CONNECTED_USERS_PACKAGE_H

#include "../includes/util/packages.hpp"

class ReqConnectedUsersPackage : public Package {
public:
    ReqConnectedUsersPackage();

    explicit ReqConnectedUsersPackage(ustring recvline);

    ssize_t toString(ustring line) override;
};

#endif //EP2_REQ_CONNECTED_USERS_PACKAGE_H
