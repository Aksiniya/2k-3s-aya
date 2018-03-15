#include <iostream>
#include "Stack.h"
using namespace std;

void IntStack();
void CharStack();
void OverwriteIntStack();

int main(){
    IntStack();
    CharStack();
    OverwriteIntStack();
    return 0;
}

void IntStack(){
    try{
        Stack<int> IntStack(10);
        IntStack.push(1);
        IntStack.push(3);
        cout << "Latest element in IntStack is: " << IntStack.pop() << endl;
        IntStack.pop();
        IntStack.pop(); // ошибка! -> в блок catch
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
}

void CharStack(){
    try{
        Stack<char> CharStack(5);
        CharStack.push('o');
        CharStack.push('l');
        CharStack.push('l');
        CharStack.push('e');
        CharStack.push('h');
        size_t stackSize = CharStack.count();
        for (size_t i = 0; i != stackSize; ++i){
            cout << CharStack.pop();
        }
        cout << endl;
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
}

void OverwriteIntStack(){
    try {
        Stack<int> IntS(3); // выделяем память всего под 3 ячейки
        for (int i = 1; i !=9; ++i){ // а заполняем - 8 -> выделение новой памяти ( два раза: сначала под 6 ячеек, потом - под 12
            IntS.push(i);
        }
        size_t k = IntS.count();
        for (int i = 0; i < k; i++){ // вывод
            cout << IntS.pop() << " ";
        }
        cout << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}
