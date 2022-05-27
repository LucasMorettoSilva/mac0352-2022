#ifndef EP2_CHANGE_PASSWORD_PACKAGE_H
#define EP2_CHANGE_PASSWORD_PACKAGE_H

#include "../includes/util/packages.hpp"

class ChangePasswordPackage : public Package {

public:
    std::string cur_password;
    std::string new_password;

    ChangePasswordPackage(std::string, std::string);

    explicit ChangePasswordPackage(ustring recvline);

    ssize_t toString(ustring line) override;
};

#endif //EP2_CHANGE_PASSWORD_PACKAGE_H
