#include "print_ip.h"
#include <gtest/gtest.h>
#include <list>
#include <tuple>

TEST(print_integer, print_char)
{

    ASSERT_EQ(extract_ip(int8_t{-1}), "255");
    ASSERT_EQ(extract_ip(uint8_t{10}), "10");
}
TEST(print_integer, print_short)
{

    ASSERT_EQ(extract_ip(int16_t{0}), "0.0");
    ASSERT_EQ(extract_ip(uint16_t{0}), "0.0");
}
TEST(print_integer, print_int)
{

    ASSERT_EQ(extract_ip(int32_t{2130706433}), "127.0.0.1");
    ASSERT_EQ(extract_ip(uint32_t{2130706433}), "127.0.0.1");
    ASSERT_EQ(extract_ip(int{1234}), "0.0.4.210");
}
TEST(print_integer, print_long)
{

    ASSERT_EQ(extract_ip(int64_t{8875824491850138409}), "123.45.67.89.101.112.131.41");
    ASSERT_EQ(extract_ip(uint64_t{8875824491850138409}), "123.45.67.89.101.112.131.41");
}

TEST(print_string, print_string)
{
    ASSERT_EQ(extract_ip(std::string{"trololo"}), "trololo");
}

TEST(print_container, print_vector)
{
    ASSERT_EQ(extract_ip(std::vector{0, 1, 2, 3}), "0.1.2.3");
}
TEST(print_container, print_list)
{
    ASSERT_EQ(extract_ip(std::list{10, 20, 30, 40}), "10.20.30.40");
}

TEST(print_tuple, print_tuple)
{
    ASSERT_EQ(extract_ip(std::make_tuple(0, 1, 2, 3)), "0.1.2.3");
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}