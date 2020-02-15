#ifndef PRINT_IP_H
#define PRINT_IP_H
#include <iostream>
#include <string>
#include <type_traits>
#include "TuplePrinter.h"

/// \brief Template function to get and format ip from input.
/// \details This is integer specialization.
template<typename T>
typename std::enable_if_t<std::is_integral_v<T>, std::string> extract_ip(const T& value) {
    std::string result;
    for(int i = sizeof(T)-1; i >= 0; --i){
        result += std::to_string(((value >> (8 * i)) & 0XFF));
        if (i != 0){
            result += ".";
        }
    }
    return result;
}

/// \brief Template function to get and format ip from input.
/// \details This is specialization for containers.
template<typename T>
decltype(begin(std::declval<T>()), end(std::declval<T>()), std::string()) extract_ip(const T& container) {
    std::string result;
    auto last_elem = end(container);
    for(auto elem = begin(container); elem != last_elem;){
        result += std::to_string(*elem);
        if (++elem != last_elem){
            result += ".";
        }
    }
    return result;
}

/// \brief Template function to get and format ip from input.
/// \details This is specialization for tuple.
template<typename...Args>
std::string extract_ip(const std::tuple<Args...>& t) {

    return TuplePrinter<decltype(t), sizeof...(Args)>::to_string(t);;
}

/// \brief Template function to get and format ip from input.
/// \details This is specialization for strings.
std::string extract_ip(const std::string& value) {
    return value;
}

/// \brief Template function to print ip.
/// \details Uses extract_ip to format data.
template <typename T>
void print_ip(T value){
    std::cout << extract_ip(value) << std::endl;
}

#endif //_PRINT_IP_H
