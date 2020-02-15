#ifndef PRINT_IP_H
#define PRINT_IP_H
#include <iostream>
#include <string>
#include <type_traits>

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

template<typename...Args>
std::string extract_ip(const std::tuple<Args...>& t) {

    return TuplePrinter<decltype(t), sizeof...(Args)>::to_string(t);;
}


std::string extract_ip(const std::string& value) {
    return value;
}

template <typename T>
void print_ip(T value){
    std::cout << extract_ip(value) << std::endl;
}

template<class Tuple, std::size_t N>
struct TuplePrinter {
    static std::string to_string(const Tuple& t)
    {
        std::string result;
        result += TuplePrinter<Tuple, N-1>::to_string(t);
        result += ".";
        result += std::to_string(std::get<N-1>(t));
        return result;
    }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
    static std::string to_string(const Tuple& t)
    {
        return std::to_string(std::get<0>(t));
    }
};



#endif //_PRINT_IP_H
