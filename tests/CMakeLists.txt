cmake_minimum_required(VERSION 3.2)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) 
conan_basic_setup(TARGETS)

add_executable(test_print_ip test_print_ip.cpp)

set_target_properties(
	test_print_ip
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_print_ip
    print_ip_lib
    CONAN_PKG::gtest
)


if (MSVC)
    target_compile_options(test_print_ip PRIVATE
        /W4 /MD
    )
else ()
    target_compile_options(test_print_ip PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

enable_testing()

add_test(test_print_ip "bin/test_print_ip")