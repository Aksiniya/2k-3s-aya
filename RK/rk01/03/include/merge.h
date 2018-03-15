//
//  merge.h
//  test0103
//
//  Created by macbook on 09.10.17.
//  Copyright © 2017 macbook. All rights reserved.
//

#ifndef MERGE_HPP
#define MERGE_HPP

#include <iostream>

// функция объединяет два массива вне зависимости от их длины
// однонаправленные итераторы (++)
template <typename Iterator1, typename Iterator2>
auto merge( Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output ) -> Iterator2{
    
    Iterator2 It2return = output;
    
    while(first1 != last1 && first2 != last2){
        
        if(*first1 >= *first2){
            *output++ = *first2++;
            *output++ = *first1++;
        }
        else if(*first1 < *first2){
            *output++ = *first1++;
            *output++ = *first2++;
        }
    }
    
    //ввод оставшихся элементов (если массивы разной длины)
    if(first1 == last1){
        while(first2 != last2){
            *output++ = *first2++;
        }
    }
    else if (first2 == last2){
        while(first1 != last1){
            *output++ = *first1++;
        }
    }
    return It2return;
}

#endif
