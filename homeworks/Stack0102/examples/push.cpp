#include <iostream>
#include "Stack.h"
using namespace std;

void CharStack();

int main(){
    CharStack();
    return 0;
}

void CharStack(){
    try {
        Stack<char> CS(3);
        CS.push('a');
        CS.push('b');
        CS.push('c');
        CS.push('d'); // Stack::reinitializeMemory() is called here
        cout << "Elements in stack: " << CS.count() << endl; // Stack::count()
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
