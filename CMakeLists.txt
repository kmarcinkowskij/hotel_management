cmake_minimum_required(VERSION 3.28)
project(hotel_management)

set(CMAKE_CXX_STANDARD 20)

add_executable(hotel_management src/main.cpp
        src/Classes/Hotel_account.hpp
        src/Classes/User_account.cpp
        src/Classes/User_account.hpp
        src/Classes/App.cpp
        src/Classes/App.hpp)

target_link_libraries(hotel_management
        PRIVATE
)

include_directories(src/Classes)
