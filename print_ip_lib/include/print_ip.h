#ifndef PRINT_IP_H
#define PRINT_IP_H
#include <iostream>
#include <string>
template<typename T>
std::string print_ip(T value) {
    std::string result;
    for(int i = sizeof(T)-1; i >= 0; i--){
        result += std::to_string(((value >> (8 * i)) & 0XFF));
        if (i != 0){
            result += ".";
        }
    }
    return result;
}


#endif //_PRINT_IP_H
