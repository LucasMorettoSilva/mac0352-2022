cmake_minimum_required(VERSION 3.21)
project(ep2)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(ep2
        src/client-functionality.cpp
        includes/client-functionality.hpp
        src/ep2-client.cpp
        src/ep2-server.cpp
        src/packages.cpp
        includes/packages.hpp
        src/server-functionality.cpp
        includes/server-functionality.hpp
        src/server-io.cpp
        includes/server-io.hpp
        src/game-board.cpp
        includes/game-board.hpp
        src/util.cpp
        includes/util.hpp)
