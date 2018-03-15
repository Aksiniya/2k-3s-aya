/*  Вриант: 1
 Двоичное представление: 00001
 Комбинация: 1000
 A[0] = 1; A[1] = 0; A[2] = 0; A[3..4] = 0.
 
 Входной параметр: путь к файлу через параметры командной строки;
 Вывод: в файл, путь задается через переменную гломабльного окружения;
 Информация: полный путь, размер, права доступа;
 */

#include <iostream>
#include <boost/filesystem.hpp>
#include <stdlib.h> // getenv
#include <fstream>
#include <future>
#include <string>

using namespace std;
namespace bf = boost::filesystem;

vector<thread> threads;

bool writeInfo(string filename, string current_path);
void MakeOutputInfoThreads(int argc, char *argv[], string  current_pth);