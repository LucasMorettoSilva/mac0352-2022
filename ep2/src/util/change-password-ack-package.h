#ifndef EP2_CHANGE_PASSWORD_ACK_PACKAGE_H
#define EP2_CHANGE_PASSWORD_ACK_PACKAGE_H

#include "../includes/util/packages.hpp"

class ChangePasswordAckPackage : public Package {
public:
    byte return_code;

    explicit ChangePasswordAckPackage(byte);

    explicit ChangePasswordAckPackage(ustring recvline);

    ssize_t toString(ustring line) override;
};

#endif //EP2_CHANGE_PASSWORD_ACK_PACKAGE_H
