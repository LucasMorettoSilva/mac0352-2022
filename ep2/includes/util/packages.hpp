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

class ResConnectedUsersPackage : public Package {
public:
    ResConnectedUsersPackage();

    explicit ResConnectedUsersPackage(ustring recvline);

    int num_users;
    user_t pkg_users[MAX_USERS];

    ssize_t toString(ustring line) override;

    void show_users();
};

class ReqClassificationsPackage : public Package {
public:
    ReqClassificationsPackage();

    explicit ReqClassificationsPackage(ustring recvline);

    ssize_t toString(ustring line);
};

class ResClassificationsPackage : public Package {
public:
    ResClassificationsPackage();

    explicit ResClassificationsPackage(ustring recvline);

    int num_users;
    user_t pkg_users[MAX_USERS];

    ssize_t toString(ustring line) override;

    void show_users();
};

class PingReqPackage : public Package {
public:
    PingReqPackage();

    ssize_t toString(ustring line) override;
};

class PingBackPackage : public Package {
public:
    PingBackPackage();

    ssize_t toString(ustring line) override;
};

class InviteOpponentPackage : public Package {
public:
    explicit InviteOpponentPackage(std::string c);

    explicit InviteOpponentPackage(ustring recvline);

    std::string cliente;

    ssize_t toString(ustring line) override;
};

class InviteOpponentAckPackage : public Package {
public:
    int resp;
    char *ip;
    int port;

    explicit InviteOpponentAckPackage(int r);

    ssize_t toString(ustring line) override;

    void string_to_header(ustring recvline);
};

class SendMovePackage : public Package {
public:
    int r, c;

    SendMovePackage();

    SendMovePackage(int r, int c);

    ssize_t toString(ustring line) override;

    void string_to_header(ustring recvline);
};

class EndMatchPackage : public Package {
public:
    int pont;

    explicit EndMatchPackage(int p);

    ssize_t toString(ustring line) override;
};

class ReconnectPackage : public Package {
public:
    explicit ReconnectPackage(std::string username);

    explicit ReconnectPackage(ustring recvline);

    std::string username;

    ssize_t toString(ustring line) override;
};

#endif /* ifndef PACKAGES_HPP */
