#ifndef EP2_CREATE_USER_PACKAGE_H
#define EP2_CREATE_USER_PACKAGE_H

#include "packages.hpp"

class CreateUserPackage : public Package {

public:
    CreateUserPackage(std::string, std::string);
    explicit CreateUserPackage(ustring recvline);

    std::string username;
    std::string password;

    ssize_t toString(ustring line) override;
};

#endif //EP2_CREATE_USER_PACKAGE_H
