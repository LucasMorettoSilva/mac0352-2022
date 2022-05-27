#ifndef EP2_CREATE_USER_ACK_PACKAGE_H
#define EP2_CREATE_USER_ACK_PACKAGE_H

#include "../includes/util/types.h"
#include "../includes/util/packages.hpp"

class CreateUserAckPackage : public Package {

public:
    byte return_code;

    explicit CreateUserAckPackage(byte);

    explicit CreateUserAckPackage(ustring line);

    ssize_t toString(ustring line) override;
};

#endif //EP2_CREATE_USER_ACK_PACKAGE_H
