#ifndef PACKAGES_HPP
#define PACKAGES_HPP

#include <cstddef>
#include <string>

#include "../server-io.hpp"

#include "../includes/util/util.hpp"
#include "../includes/util/package-header.h"
#include "../includes/util/package-type.h"

class Package {
public:
    Package();

    PackageHeader header;

    virtual ssize_t toString(ustring line) = 0;
};

class CreateUserPackage : public Package {
public:
    CreateUserPackage(std::string, std::string);
    CreateUserPackage(ustring recvline);

    std::string username;
    std::string password;

    ssize_t toString(ustring line);
};

class CreateUserAckPackage : public Package {
public:
    byte return_code;

    CreateUserAckPackage(byte);
    CreateUserAckPackage(ustring line);

    ssize_t toString(ustring line);
};

class LoginPackage : public Package {
public:
    LoginPackage(std::string, std::string);
    LoginPackage(ustring recvline);

    std::string user_login;
    std::string user_password;

    ssize_t toString(ustring line);
};

class LoginAckPackage : public Package {
public:
    byte return_code;

    LoginAckPackage(byte);
    LoginAckPackage(ustring recvline);

    ssize_t toString(ustring line);
};

class LogoutPackage : public Package {
public:
    LogoutPackage();
    LogoutPackage(ustring recvline);

    ssize_t toString(ustring line);
};

class ChangePasswordPackage : public Package {
public:
    std::string cur_password;
    std::string new_password;

    ChangePasswordPackage(std::string, std::string);
    ChangePasswordPackage(ustring recvline);

    ssize_t toString(ustring line);
};

class ChangePasswordAckPackage : public Package {
public:
    byte return_code;

    ChangePasswordAckPackage(byte);
    ChangePasswordAckPackage(ustring recvline);

    ssize_t toString(ustring line);
};

class ReqConnectedUsersPackage : public Package {
public:
    ReqConnectedUsersPackage();
    ReqConnectedUsersPackage(ustring recvline);

    ssize_t toString(ustring line);
};

class ResConnectedUsersPackage : public Package {
public:
    ResConnectedUsersPackage();
    ResConnectedUsersPackage(ustring recvline);

    int num_users;
    user_t pkg_users[MAX_USERS];

    ssize_t toString(ustring line);
    void show_users();
};

class ReqClassificationsPackage : public Package {
public:
    ReqClassificationsPackage();
    ReqClassificationsPackage(ustring recvline);

    ssize_t toString(ustring line);
};

class ResClassificationsPackage : public Package {
public:
    ResClassificationsPackage();
    ResClassificationsPackage(ustring recvline);

    int num_users;
    user_t pkg_users[MAX_USERS];

    ssize_t toString(ustring line);
    void show_users();
};

class PingReqPackage : public Package {
public:
    PingReqPackage();
    ssize_t toString(ustring line);
};

class PingBackPackage : public Package {
public:
    PingBackPackage();
    ssize_t toString(ustring line);
};

class InviteOpponentPackage : public Package {
public:
    InviteOpponentPackage(std::string c);
    InviteOpponentPackage(ustring recvline);

    std::string cliente;

    ssize_t toString(ustring line);
};

class InviteOpponentAckPackage : public Package {
public:
    int resp;
    char *ip;
    int port;
    InviteOpponentAckPackage(int r);
    ssize_t toString(ustring line);
    void string_to_header(ustring recvline);
};

class SendMovePackage : public Package {
public:
    int r, c;
    SendMovePackage();
    SendMovePackage(int r, int c);
    ssize_t toString(ustring line);
    void string_to_header(ustring recvline);
};

class EndMatchPackage : public Package {
public:
    int pont;
    EndMatchPackage(int p);
    ssize_t toString(ustring line);
};

class ReconnectPackage : public Package {
public:
    ReconnectPackage(std::string username);
    ReconnectPackage(ustring recvline);

    std::string username;

    ssize_t toString(ustring line);
};

#endif /* ifndef PACKAGES_HPP */
