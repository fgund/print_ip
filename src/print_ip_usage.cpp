/*!
*\file
*\brief print_ip usage example.
*/
#include "print_ip.h"
#include <vector>
#include <string>
#include <list>
int main()
{
    print_ip(char{-1});
    print_ip(short{0});
    print_ip(int{2130706433});
    print_ip<long long>(8875824491850138409);
    print_ip(std::string{"trololo"});
    print_ip(std::vector{0, 1, 2, 3});
    print_ip(std::list{10, 20, 30, 40});
    print_ip(std::make_tuple(0, 1, 2, 3));
    return 0;
}