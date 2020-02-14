#include "print_ip.h"
#include <iostream>
int main()
{
    std::cout << print_ip<char>(-1) << std::endl;
    std::cout << print_ip(int{2130706433}) << std::endl;
    std::cout << print_ip<long long>(8875824491850138409) << std::endl;
    return 0;
}