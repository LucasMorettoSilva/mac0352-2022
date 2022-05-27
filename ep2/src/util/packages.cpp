#ifndef PACKAGES_CPP
#define PACKAGES_CPP

#include "../../includes/util/packages.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>

// PACKAGE TEMPLATE
Package::Package() { }

// LOGIN PACKAGE


//  LOGIN ACK PACKAGE


// LOGOUT PACKAGE


// CHANGE PASSWORD PACKAGE


// CHANGE PASSWORD ACK PACKAGE


// REQUEST ALL CONNECTED USERS PACKAGE


// RESPONSE ALL CONNECTED USERS PACKAGE
ResConnectedUsersPackage::ResConnectedUsersPackage() { }
ResConnectedUsersPackage::ResConnectedUsersPackage(ustring recvline) {
    int pos = 3;
    this->header = PackageHeader(recvline);

    this->num_users = recvline[pos++];

    for (int i = 0; i < this->num_users; i++) {
        int len = byte_str_to_int(recvline, pos);
        pos += 2;
        this->pkg_users[i].name = (char *) malloc(len * sizeof(char));
        for (int j = 0; j < len; j++)
            this->pkg_users[i].name[j] = (char) recvline[pos++];
        this->pkg_users[i].name[len] = 0;
        this->pkg_users[i].score = recvline[pos++];
        this->pkg_users[i].connected = recvline[pos++];
        this->pkg_users[i].in_match = recvline[pos++];
    }
}
// ResConnectedUsersPackage::~ResConnectedUsersPackage() { }

ssize_t ResConnectedUsersPackage::toString(ustring line) {
    int total_len = 1;
    for (int i = 0; i < *total_users; i++) {
        total_len += strlen(users[i]->name) + 2 + 3;
    }

    this->header.package_type = RESPONSE_ALL_CONNECTED_USERS_PACKAGE;
    this->header.remaning_length = total_len;

    int pos = 0;
    this->header.write(line, pos);
    line[pos++] = *total_users;

    for (int i = 0; i < *total_users; i++) {
        int len = strlen(users[i]->name);
        ustring strlen = int_to_2byte_str(len);
        line[pos++] = strlen[0];
        line[pos++] = strlen[1];
        free(strlen);
        for (int j = 0; j < len; ++j) { line[pos++] = users[i]->name[j]; }
        line[pos++] = users[i]->score;
        line[pos++] = users[i]->connected;
        line[pos++] = users[i]->in_match;
    }

    return pos;
}

void ResConnectedUsersPackage::show_users() {
    for (int i = 0; i < this->num_users; i++) {
        std::cout << "User [" << this->pkg_users[i].name << "]:" << std::endl
                  << "\tScore: " << this->pkg_users[i].score << std::endl
                  << "\tConnected: " << this->pkg_users[i].connected
                  << std::endl
                  << "\tPlaying: " << this->pkg_users[i].in_match << std::endl
                  << std::endl;
    }
}

// REQUEST CLASSIFICATIONS PACKAGE
ReqClassificationsPackage::ReqClassificationsPackage() { }
ReqClassificationsPackage::ReqClassificationsPackage(ustring recvline) {
    this->header = PackageHeader(recvline);
}

ssize_t ReqClassificationsPackage::toString(ustring line) {
    this->header.package_type = REQUEST_CLASSIFICATIONS_PACKAGE;
    this->header.remaning_length = 0;

    int pos = 0;
    this->header.write(line, pos);

    return pos;
}

// RESPONSE CLASSIFICATIONS PACKAGE
ResClassificationsPackage::ResClassificationsPackage() { }
ResClassificationsPackage::ResClassificationsPackage(ustring recvline) {
    int pos = 3;
    this->header = PackageHeader(recvline);

    this->num_users = recvline[pos++];

    for (int i = 0; i < this->num_users; i++) {
        int len = byte_str_to_int(recvline, pos);
        pos += 2;
        this->pkg_users[i].name = (char *) malloc(len * sizeof(char));
        for (int j = 0; j < len; j++)
            this->pkg_users[i].name[j] = (char) recvline[pos++];
        this->pkg_users[i].name[len] = 0;
        this->pkg_users[i].score = recvline[pos++];
    }
}

ssize_t ResClassificationsPackage::toString(ustring line) {
    int total_len = 1;
    for (int i = 0; i < *total_users; i++) {
        total_len += strlen(users[i]->name) + 2 + 1;
    }

    this->header.package_type = RESPONSE_CLASSIFICATIONS_PACKAGE;
    this->header.remaning_length = total_len;

    int pos = 0;
    this->header.write(line, pos);
    line[pos++] = *total_users;

    for (int i = 0; i < *total_users; i++) {
        int len = strlen(users[i]->name);
        ustring strlen = int_to_2byte_str(len);
        line[pos++] = strlen[0];
        line[pos++] = strlen[1];
        free(strlen);
        for (int j = 0; j < len; ++j) { line[pos++] = users[i]->name[j]; }
        line[pos++] = users[i]->score;
    }

    return pos;
}
void ResClassificationsPackage::show_users() {
    auto great = [](user_t a, user_t b) { return a.score > b.score; };
    std::sort(this->pkg_users, this->pkg_users + this->num_users, great);

    for (int i = 0; i < this->num_users; i++) {
        std::cout << "User [" << this->pkg_users[i].name << "]:" << std::endl
                  << "\tScore: " << this->pkg_users[i].score << std::endl
                  << "\tClassification: " << i + 1 << std::endl
                  << std::endl;
    }
}

ssize_t PingReqPackage::toString(ustring line) {
    line[0] = this->header.package_type;
    line[1] = line[2] = 0;
    return 3;
}
PingReqPackage::PingReqPackage() { header.package_type = PINGREQ_PACKAGE; }

ssize_t PingBackPackage::toString(ustring line) {
    line[0] = this->header.package_type;
    line[1] = line[2] = 0;
    return 3;
}
PingBackPackage::PingBackPackage() {
    header.package_type = PINGBACK_PACKAGE;
}

ssize_t InviteOpponentPackage::toString(ustring line) {
    int pos = 0;
    this->header.write(line, pos);
    write_string(line, pos, this->cliente);
    return pos;
}
InviteOpponentPackage::InviteOpponentPackage(std::string c) {
    this->cliente = c;
    this->header.package_type = (byte) INVITE_OPPONENT_PACKAGE;
    this->header.remaning_length = this->cliente.size() + 2;
}
InviteOpponentPackage::InviteOpponentPackage(ustring recvline) {
    int pos = 3;
    this->header = PackageHeader(recvline);
    read_string(recvline, pos, this->cliente);
}

ssize_t InviteOpponentAckPackage::toString(ustring line) {
    line[0] = this->header.package_type;
    line[3] = (byte) resp;
    if (resp == 0) {
        line[1] = 0;
        line[2] = 1;
        return 4;
    } else {
        int tam = 4;
        line[tam++] = port / (1 << 8);
        line[tam++] = port % (1 << 8);
        line[tam++] = (byte) strlen(ip);
        for (int j = 0; j < (int) strlen(ip); j++) {
            line[tam++] = (byte) ip[j];
        }
        line[1] = tam / (1 << 8);
        line[2] = tam % (1 << 8);
        return tam;
    }
}

void InviteOpponentAckPackage::string_to_header(ustring recvline) {
    resp = (int) recvline[3];
    port = (int) recvline[4] * (1 << 8) + (int) recvline[5];
    int tam = (int) recvline[6];
    ip = (char *) malloc((tam) * sizeof(char));
    for (ssize_t j = 7; j < 7 + tam; j++) { ip[j - 7] = (char) recvline[j]; }
}

InviteOpponentAckPackage::InviteOpponentAckPackage(int r) {
    resp = r;
    port = 0;
    ip = (char *) malloc(sizeof(char));
    header.package_type = (byte) INVITE_OPPONENT_ACK_PACKAGE;
}

ssize_t SendMovePackage::toString(ustring line) {
    line[0] = this->header.package_type;
    line[1] = (byte) r;
    line[2] = (byte) c;
    return 3;
}

void SendMovePackage::string_to_header(ustring recvline) {
    r = (int) recvline[1];
    c = (int) recvline[2];
}

SendMovePackage::SendMovePackage(int r, int c) {
    this->r = r, this->c = c;
    header.package_type = (byte) SEND_MOVE_PACKAGE;
}
SendMovePackage::SendMovePackage() {
    this->r = 0, this->c = 0;
    header.package_type = (byte) SEND_MOVE_PACKAGE;
}

ssize_t EndMatchPackage::toString(ustring line) {
    line[0] = this->header.package_type;
    line[1] = pont;
    return 2;
}
EndMatchPackage::EndMatchPackage(int p) {
    pont = p;
    header.package_type = (byte) END_MATCH_PACKAGE;
}

ReconnectPackage::ReconnectPackage(std::string username) {
    this->username = username;
}

ReconnectPackage::ReconnectPackage(ustring recvline) {
    int pos = 3;
    this->header = PackageHeader(recvline);
    read_string(recvline, pos, this->username);
}


ssize_t ReconnectPackage::toString(ustring line) {
    this->header.package_type = RECONNECT_PACKAGE;
    this->header.remaning_length = 2 + this->username.size();

    int pos = 0;
    this->header.write(line, pos);
    write_string(line, pos, this->username);

    return pos;
}

#endif /* ifndef PACKAGES_CPP */
