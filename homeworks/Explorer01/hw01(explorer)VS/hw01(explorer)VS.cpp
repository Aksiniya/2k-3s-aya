// hw01(explorer)VS.cpp : Defines the entry point for the console application.
//

/*  Вриант: 1
Двоичное представление: 00001
Комбинация: 1000
A[0] = 1; A[1] = 0; A[2] = 0; A[3..4] = 0.

*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char *argv[]) {

	//	ofstream out;
	//	out.open("output.txt");

	cout << "Hello" << endl;

	for (int i = 0; i < argc; i++) {
		// Выводим список аргументов в цикле
		cout << "Argument " << i << " : " << argv[i] << endl;
	}
	int systempause;
	cin >> systempause;
	return 0;
}
