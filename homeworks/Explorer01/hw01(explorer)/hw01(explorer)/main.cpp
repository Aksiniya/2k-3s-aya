/*  Вриант: 1
    Двоичное представление: 00001
    Комбинация: 1000
    A[0] = 1; A[1] = 0; A[2] = 0; A[3..4] = 0.
 
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    
    ofstream out;
    out.open("output.txt");
    
    
    for (int i = 0; i < argc; i++) {
        // Выводим список аргументов в цикле
        cout << "Argument " << i << " : " << argv[i] << endl;
    }
    return 0;
}