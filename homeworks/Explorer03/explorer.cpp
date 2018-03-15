
using namespace std;
namespace bf = boost::filesystem;

bool writeInfo(string, string);

int main(int argc, char *argv[]) {
    
    if(argc < 2){
        cout << "Отсутствует передаваемый параметр - нет информации о файле" << endl;
        return 0;
    }
    
    bf::path currentPath(bf::current_path());
    string curr_p = currentPath.string();
    
    for (int i = 1; i < argc; ++i) {
        string filename = argv[i];
        
        packaged_task<bool(string, string)> task(writeInfo); // set up packaged_task
        auto result = task.get_future();
        
        thread new_thr(move(writeInfo), filename, curr_p);
        new_thr.detach();
        
        cout << "Данные взяты: " << { result.get() ? "true": "false" } << endl;
        cout << new_thr.get_id() << " is join" << endl;
    }

    return 0;
}

bool writeInfo(string filename, string current_path){
    try{
        
        // создается новый файл типа "/info_<file_name>.txt" в текущей директории, куда записывается информация о файле filename
        
        size_t nameSlPositionInFN = 0; // последняя позиция "слеша / "
        size_t nameDtPositionInFN = 0; // последняя позиция точки .
        
        for ( size_t i = filename.size(); i != 0; --i){
            
            if (filename[i] == '.'){
                nameDtPositionInFN = i;
            }
            
            if (filename[i] == '/'){
                nameSlPositionInFN = i;
                break;
            }
        }
        
        string name;
        name.append(filename, nameSlPositionInFN+1, nameDtPositionInFN-nameSlPositionInFN-1);
        
        cout << name << endl;
        
        string direction = current_path + "/info_" + name + ".txt";
    
        cout << direction << endl;
        
        ofstream fout;
//      fout.open(direction, ios_base::app);
        fout.open(direction);
        if (!fout.is_open()) // если файл не открылся
        {
            cout << "Файл не может быть открыт или создан" << endl;
            return false;
        }
        
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
        fout << endl;
        fout.close();
        return true;
    }
    catch(bf::filesystem_error& e){
        cout << e.what() << endl;
        return false;
    }
}
