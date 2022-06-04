cmake_minimum_required(VERSION 3.21)
project(ep2)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(includes)

add_executable(ep2
        src/client-helper.cpp
        includes/client-helper.h
        src/client.cpp
        src/server.cpp
        src/packages.cpp
        includes/packages.h
        includes/package-type.h
        src/server-helper.cpp
        includes/server-helper.h
        src/log.cpp
        includes/log.h
        src/game-board.cpp
        includes/game-board.h
        src/util.cpp
        includes/util.h)
