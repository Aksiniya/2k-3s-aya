#include <iostream>
#include <vector>
#include "Stack.h"
using namespace std;

void IntStack(size_t);
void CharStack();
void VectorStack(size_t);

int main(){
    IntStack(10);
    CharStack();
    VectorStack(5);
    return 0;
}

void IntStack(size_t n){
    Stack<int> S; // int stack with 100 elements
    Stack<int> SN(n); // int stack with n elements
}

void CharStack(){
    Stack<char> C(20); // char stack with 20 elements
}

void VectorStack(size_t n){ // stack with n vectors
    try {
        Stack<vector<int>*> VecIntStack(n);
        vector<int> v1(5);
        v1.push_back(5);
        vector<int> v2(4);
        v2.push_back(4);
        
        VecIntStack.push(&v1);
        VecIntStack.push(&v2);
        
        vector<int>* v3 = VecIntStack.pop();
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
