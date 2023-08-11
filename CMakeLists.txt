cmake_minimum_required(VERSION 3.15)
project(fsd
        VERSION 3.99.1
        LANGUAGES CXX)

add_executable(fsd
        src/certificate.cpp
        src/client.cpp
        src/clinterface.cpp
        src/cluser.cpp
        src/config.cpp
        src/fsd.cpp
        src/interface.cpp
        src/main.cpp
        src/manage.cpp
        src/mm.cpp
        src/process.cpp
        src/server.cpp
        src/servinterface.cpp
        src/servuser.cpp
        src/support.cpp
        src/sysinterface.cpp
        src/sysuser.cpp
        src/user.cpp
        src/wprofile.cpp)

find_package(PkgConfig REQUIRED)
pkg_search_module(SQLITE3 REQUIRED sqlite3)
pkg_search_module(JSONCPP REQUIRED jsoncpp)
include_directories(${SQLITE3_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS})
target_link_libraries(fsd ${SQLITE3_LIBRARIES} ${JSONCPP_LIBRARIES})
target_include_directories(fsd PRIVATE ${SQLITE3_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS})
set_property(TARGET fsd PROPERTY CMAKE_CXX_STANDARD 17)
set_property(TARGET fsd PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)
