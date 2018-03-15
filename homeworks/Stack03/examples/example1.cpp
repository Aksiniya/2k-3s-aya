#include <iostream>
#include <stack.hpp>

using namespace std;

int main(){
    
    Stack<int> sint1;
    cout << "Stack<int> sint1" << endl;
    cout << "sint1 : " << sint1 << endl; // по умолчанию - стек из 100 элементов, пустой
    
    Stack<int> sint2(10, 5, new int[5]{1,2,3,4,5});
    cout << "Stack<int> sint2(10, 5, new int[5]{1,2,3,4,5})" << endl;
    cout << "sint2 : " << sint2 << endl;
    
    Stack<int> sint3(sint2);
    cout << "Stack<int> sint3(sint2)" << endl;
    cout << "sint2 : " << sint2 << endl;
    cout << "sint3 : " << sint3 << "  // copy from sit2" << endl;
    
    Stack<int> sint4(move(sint2));
    cout << "Stack<int> sint4(move(sint2))" << endl;
    cout << "sint2 : " << sint2 << endl;
    cout << "sint3 : " << sint3 << endl;
    cout << "sint4 : " << sint4 << "  // move from sint2" << endl;
    
    Stack<int> sint5 = sint4;
    cout << "Stack<int> sint5 = sint4" << endl;
    cout << "sint2 : " << sint2 << endl;
    cout << "sint3 : " << sint3 << endl;
    cout << "sint4 : " << sint4 << endl;
    cout << "sint5 : " << sint5 << "  // copy with = from sint4" << endl;
    
    Stack<int> sint6 = move(sint4);
    cout << "Stack<int> sint6 = move(sint4)" << endl;
    cout << "sint2 : " << sint2 << endl;
    cout << "sint3 : " << sint3 << endl;
    cout << "sint4 : " << sint4 << endl;
    cout << "sint5 : " << sint5 << endl;
    cout << "sint6 : " << sint6 << "  // move with = from sint4" << endl;
    return 0;
}
