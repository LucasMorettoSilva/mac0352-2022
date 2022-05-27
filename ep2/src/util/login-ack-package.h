#ifndef EP2_LOGIN_ACK_PACKAGE_H
#define EP2_LOGIN_ACK_PACKAGE_H

#include "../includes/util/packages.hpp"

class LoginAckPackage : public Package {

public:
    byte return_code;

    explicit LoginAckPackage(byte);

    explicit LoginAckPackage(ustring recvline);

    ssize_t toString(ustring line) override;
};

#endif //EP2_LOGIN_ACK_PACKAGE_H
