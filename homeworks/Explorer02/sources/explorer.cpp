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

void writeInfo(string, string);

int main(int argc, char *argv[]) {
    
    if(argc < 2){
        cout << "Отсутствует передаваемый параметр - нет информации о файле" << endl;
        return 0;
    }
    
    string filename = argv[1]; // имя файла, информацию о котором необходимо вывести
    
    if(!getenv("EXPLORER_LOG_PATH")){
        cout << "Отсутствует переменная окружения - путь к файлу EXPLORER_LOG_PATH" << endl;
        return 0;
    }
    
    string direction = getenv("EXPLORER_LOG_PATH"); // путь к файлу (куда выводить информацию)
    
    bf::path currentPath(bf::current_path());
    string directionToCurrentDirInfoTxt = currentPath.string() + "/info.txt";
    
    future<void> async1{ std::async(writeInfo, filename, direction) };
    future<void> async2{ std::async(writeInfo, filename, directionToCurrentDirInfoTxt) };
    
    async1.get();
    async2.get();
    return 0;
}

void writeInfo(string filename, string direction){
    try{
        
        ofstream fout;
        fout.open(direction);
        
        bf::path p(filename);
        
        bf::perms prm = bf::status(p).permissions();
        
        fout << "Полный путь: " << bf::absolute(p) << endl;
        fout << "Размер файла: " << bf::file_size(p) << "байт" << endl;
        fout << "Права доступа: " << endl << "Владелец файла ";
        fout << ((prm & bf::perms::owner_all) != bf::perms::no_perms ? "может " : "не может ");
        fout << "читать, записывать, выполнять файл" << endl;
        fout << "Группа пользователей файла ";
        fout << ((prm & bf::perms::group_all) != bf::perms::no_perms ? "может " : "не может ");
        fout << "читать, записывать, выполнять файл" << endl;
        fout << "Другие пользователи ";
        fout << ((prm & bf::perms::others_all) != bf::perms::no_perms ? "могут " : "не могут ");
        fout << "читать, записывать, выполнять файл" << endl;
        
        fout.close();
    }
    catch(bf::filesystem_error& e){
        cout << e.what() << endl;
    }
}