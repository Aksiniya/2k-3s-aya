#include <fstream>
#include <string>
#include <iostream>

#include "yaml-cpp/yaml.h"

using namespace std;

struct Email {
    string nickname;
    string server;
};

struct Person {
    string  first_name;
    string  last_name;
    Email   email;
    size_t  age;
    string  phone;
};

void operator << (const YAML::Node& node, Email& e) {
    cout << node["nickname"];
    cout << node["server"];
}

int main(int argc, char** argv) {
    
    if( argc < 2){
        cout << "Ошибка - отсутствует передаваемый параметр." << endl;
        return 0;
    }
    
    string path = argv[1];
    
    ifstream fin(path);
  
    YAML::Node doc = YAML::LoadFile(path);

    cout << "First name: " << doc["First name"] << "\n";
    cout << "Last name:  " << doc["Last name"] << "\n";
    cout << "Email:" << "\n" << doc["Email"] << "\n";
    cout << "Phone:      " << doc["Phone"] << "\n";
    cout << "Age:        " << doc["Age"] << "\n";

    return 0;
}
