#ifndef FINDTWOELEMENTSSUM_HPP
#define FINDTWOELEMENTSSUM_HPP

#include <iostream>
using namespace std;
template <typename Iterator, typename T>

// Iterator first - в данном случае однонаправленный (тут используется только в направлении ++)
auto find_two_elements_with_sum( Iterator first, Iterator last, T c ) -> pair<bool, pair<Iterator, Iterator>> {
    
    while (first != last){
        T sum;
        for(auto it = first + 1; it != last; ++it){
            sum = *first + *it;
            if(sum == c){
                return {true, {first, it}};
            }
        }
        ++first;
    };
    
    return {false, {}};
}

#endif
