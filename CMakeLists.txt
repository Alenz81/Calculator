cmake_minimum_required(VERSION 3.23)
project(Calculator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp PostFix.cpp PostFix.h Application.cpp Application.h Button.cpp Button.h ButtonBoard.cpp ButtonBoard.h Display.cpp Display.h Engine.cpp Engine.h Helper.cpp Helper.h CalcBody.cpp CalcBody.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(Calculator WIN32 ${SOURCE_FILES})
else ()
    add_executable(Calculator ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.6.0-windows-gcc-13.1.0-mingw-32-bit/SFML-2.6.0)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH C:/Users/super/CLionProjects/cmake_modules)
set(SFML_DIR C:/SFML/SFML-2.6.0/lib/cmake/SFML)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Calculator ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

# cmake_minimum_required(VERSION 3.23)
# project (Calculator)

# set(CMAKE_CXX_STANDARD 14)

# add_executable(Calculator main.cpp)