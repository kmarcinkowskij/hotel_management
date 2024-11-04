cmake_minimum_required(VERSION 3.28)
project(hotel_management)

set(CMAKE_CXX_STANDARD 26)

add_executable(hotel_management src/main.cpp
        src/Classes/Hotel_account.cpp
        src/Classes/Hotel_account.hpp
        src/Classes/User_account.cpp
        src/Classes/User_account.hpp)
