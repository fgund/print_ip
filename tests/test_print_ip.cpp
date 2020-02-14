#include "print_ip.h"
#include <gtest/gtest.h>

TEST(print_integer, print_char)
{

    ASSERT_EQ(print_ip(int8_t {-1}), "255");
    ASSERT_EQ(print_ip(uint8_t {10}), "10");
}
TEST(print_integer, print_short)
{

    ASSERT_EQ(print_ip(int16_t {0}), "0.0");
    ASSERT_EQ(print_ip(uint16_t {0}), "0.0");
}
TEST(print_integer, print_int)
{

    ASSERT_EQ(print_ip(int32_t {2130706433}), "127.0.0.1");
    ASSERT_EQ(print_ip(uint32_t {2130706433}), "127.0.0.1");
}
TEST(print_integer, print_long)
{

    ASSERT_EQ(print_ip(int64_t {8875824491850138409}), "123.45.67.89.101.112.131.41");
    ASSERT_EQ(print_ip(uint64_t {8875824491850138409}), "123.45.67.89.101.112.131.41");
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}