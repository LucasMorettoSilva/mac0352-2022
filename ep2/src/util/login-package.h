#ifndef EP2_LOGIN_PACKAGE_H
#define EP2_LOGIN_PACKAGE_H

#include "../includes/util/packages.hpp"

class LoginPackage : public Package {

public:
    LoginPackage(std::string, std::string);

    explicit LoginPackage(ustring recvline);

    std::string user_login;
    std::string user_password;

    ssize_t toString(ustring line) override;
};

#endif //EP2_LOGIN_PACKAGE_H
