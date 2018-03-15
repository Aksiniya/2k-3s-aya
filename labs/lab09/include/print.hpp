/*!
\file
\brief Header-file с перегруженной функцией print со входными параметрами: строка и поток вывода
*/
#include <string>
#include <fstream>
#include <iostream>
/*!
Вывод в поток ostream
\param text Выводимая строка
\param out Куда осуществляется вывод. В данном случае - поток ostream, cout - объект класса ostream
\code
#include <print.hpp>

int main(int argc, char** argv) {
  print("hello");
}
\endcode 
*/
void print(const std::string& text, std::ostream& out = std::cout);
/*!
Вывод в поток ofstream
\param text Выводимая строка
\param out Куда осуществляется ввод. В данном случае - вывод в файл
\code
#include <fstream>
#include <print.hpp>

int main(int argc, char** argv) {
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
\endcode
*/
void print(const std::string& text, std::ofstream& out);
