#ifndef TUPLEPRINTER_H
#define TUPLEPRINTER_H
#include <tuple>
/*!
*\file
*\brief Supplementary struct to extract ip data from tuples and format it.
* Uses recursive templates.
*/

/// \brief Supplementary struct to extract ip data from tuples and format it.
/// Recursive template specialization.
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

/// \brief Supplementary struct to extract ip data from tuples and format it.
/// Template specialization to end the recursion.
template<class Tuple>
struct TuplePrinter<Tuple, 1> {
    static std::string to_string(const Tuple& t)
    {
        return std::to_string(std::get<0>(t));
    }
};

#endif //TUPLEPRINTER_H
