#ifndef EP2_PACKAGE_HEADER_H
#define EP2_PACKAGE_HEADER_H

#include <cstddef>
#include <string>

#include <util.h>

class PackageHeader {

public:
    byte package_type;

    int remaning_length;

    PackageHeader();

    explicit PackageHeader(ustring recvline);

    ustring toString();

    void write(ustring line, int &pos);
};

#endif //EP2_PACKAGE_HEADER_H
