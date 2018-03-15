#ifndef REVERSE_HPP
#define REVERSE_HPP

#include <iostream>
#include <vector>
#include "node.h"
using namespace std;
Node * reverse( Node * head ) {
    vector<Node*> vn_;
    
    //заполнение вектора указателей на узлы
    vn_.push_back(head);
    Node * n = head->next; // указатель на второй элемент
    do{
        vn_.push_back(n);
        n = n->next;
    } while (n->next != nullptr);
    vn_.push_back(n); // добавление последнего
    
    //обращаем порядок указателей
    vn_[0]->next = nullptr;
    for (auto it = vn_.begin() + 1; it < vn_.end(); ++it){
        auto earleit = it - 1;
        (*it)->next = (*earleit);
    }
    
    Node * ret = *(vn_.end()-1);
    return ret;
}


#endif /* reverse_h */
