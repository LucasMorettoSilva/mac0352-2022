cmake_minimum_required(VERSION 3.21)
project(ep2)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(ep2
        includes/util/create-user-package.h
        src/util/create-user-package.cpp
        src/client-functionality.cpp
        includes/client-functionality.hpp
        src/ep2-client.cpp
        src/ep2-server.cpp
        src/util/packages.cpp
        includes/util/packages.hpp
        includes/util/package-type.h
        src/server-functionality.cpp
        includes/server-functionality.hpp
        src/server-io.cpp
        includes/server-io.hpp
        src/game-board.cpp
        includes/game-board.hpp
        src/util/util.cpp
        includes/util/util.hpp src/util/create-user-ack-package.cpp src/util/create-user-ack-package.h src/util/login-package.cpp src/util/login-package.h src/util/login-ack-package.cpp src/util/login-ack-package.h src/util/logout-package.cpp src/util/logout-package.h src/util/change-password-package.cpp src/util/change-password-package.h src/util/change-password-ack-package.cpp src/util/change-password-ack-package.h src/util/req-connected-users-package.cpp src/util/req-connected-users-package.h)
