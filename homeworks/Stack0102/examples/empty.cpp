#include <iostream>
#include "Stack.h"
using namespace std;

void SizeTStack(size_t);

int main(){
    SizeTStack(7);
    return 0;
}

void SizeTStack(size_t n){
    try{
        Stack<size_t> IntS(n);
        for (size_t i = 0; i != n; ++i){
            IntS.push(i);
        }
        
        do{
            cout << IntS.pop() << " ";
        }
        while (!IntS.empty());
        cout << endl;
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
}
