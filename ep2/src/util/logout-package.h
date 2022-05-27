#ifndef EP2_LOGOUT_PACKAGE_H
#define EP2_LOGOUT_PACKAGE_H

#include "../includes/util/packages.hpp"

class LogoutPackage : public Package {

public:
    LogoutPackage();

    explicit LogoutPackage(ustring recvline);

    ssize_t toString(ustring line) override;
};

#endif //EP2_LOGOUT_PACKAGE_H
