cmake_minimum_required(VERSION 3.2)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) 
#conan_basic_setup(TARGETS)

add_library(print_ip_lib STATIC src/print_ip.cpp)

set_target_properties(
	print_ip_lib
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(print_ip_lib PUBLIC ./include)

if (MSVC)
    target_compile_options(print_ip_lib PRIVATE
        /W4 /MD
    )
else ()
    target_compile_options(print_ip_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()