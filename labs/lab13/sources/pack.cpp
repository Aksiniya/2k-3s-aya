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

YAML::Emitter& operator << (YAML::Emitter& out, const Email& e) {
    out << YAML::BeginSeq << e.nickname << e.server << YAML::EndSeq;
    return out;
}

YAML::Emitter& operator << (YAML::Emitter& out, const Person& p) {
    out << YAML::BeginMap;
    out << YAML::Key << "First name" << YAML::Value << p.first_name;
    out << YAML::Key << "Last name"  << YAML::Value << p.last_name;
    out << YAML::Key << "Email"      << YAML::Value << p.email;
    out << YAML::Key << "Phone"      << YAML::Value << p.phone;
    out << YAML::Key << "Age"        << YAML::Value << p.age;

    out << YAML::EndMap;
    return out;
}

Email parseCommandLineForEmail();
Person parseCommandLineForPerson();

int main(int argc, char** argv) {

    if( argc < 2){
        cout << "Ошибка - отсутствует передаваемый параметр." << endl;
        return 0;
    }
    
    string path = argv[1];
    
    Email e = parseCommandLineForEmail();
    Person p = parseCommandLineForPerson();
    p.email = e;
    
    YAML::Emitter emitter;
    
    emitter << p;
    
    ofstream fout(path);
    fout << emitter.c_str();
    
    return 0;
}

Email parseCommandLineForEmail(){
    Email e;
    cout << "Введите имя почтового ящика до \"@\" :" << endl;
    cin >> e.nickname;
    cout << "Введите сервер почтового ящика начиная с @ (example: @mail.ru):" << endl;
    cin >> e.server;

    return e;
}

Person parseCommandLineForPerson(){
    Person p;
    cout << "Введите имя:" << endl;
    cin >> p.first_name;
    cout << "Введите фамилию:" << endl;
    cin >> p.last_name;
    cout << "Введите возраст:" << endl;
    cin >> p.age;
    cout << "Введите номер телефона:" << endl;
    cin >> p.phone;
    
    return p;
}
