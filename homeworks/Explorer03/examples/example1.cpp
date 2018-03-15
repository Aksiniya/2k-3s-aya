#include <explorer.hpp>

int main(int argc, char *argv[]) {
    
    if(argc < 2){
        cout << "Отсутствует передаваемый параметр - нет информации о файле" << endl;
        return 0;
    }
    
    bf::path currentPath(bf::current_path());
    string curr_p = currentPath.string();
    
    MakeOutputInfoThreads(argc, argv[], curr_p);
    Start_thr();
    
//    for (int i = 1; i < argc; ++i) {
//        string filename = argv[i];
//        
//        packaged_task<bool(string, string)> task(writeInfo); // set up packaged_task
//        auto result = task.get_future();
//        
//        thread new_thr(move(writeInfo), filename, curr_p);
//        new_thr.detach();
//        
//        cout << "Данные взяты: " << { result.get() ? "true": "false" } << endl;
//        cout << new_thr.get_id() << " is join" << endl;
//    }
    
    return 0;
}