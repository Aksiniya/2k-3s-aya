#include <iostream>
#include "Stack.h"
using namespace std;

void StringStack();

int main(){
    StringStack();
    return 0;
}

void StringStack(){
    try{
    Stack<string> SS(1);
    string s = "pop example";
    SS.push(s);
    cout << SS.pop() << endl;
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
}
