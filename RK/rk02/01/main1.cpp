#include <iostream>
#include <vector>
using namespace std;

//массивы отсортированы по возрастанию

template<typename type>
vector<type> Merge(vector<type>& v1, vector<type>& v2){
    
    size_t s = v1.size() + v2.size();
    vector<type> v3(s);
    
    //size_t maxSize = max(v1.size(), v2.size());
    
    int n = 0; // текущая позиция вектора 1
    int m = 0; // текущая позиция вектора 2
    int v3pos = 0;
    for (int i = 0; i != s; ++i){
        
        if ( n == v1.size() && m == v2.size()){
            break;
        }
        
        if ( n == v1.size()){
            v3[v3pos++] = v2[m++];
            continue;
        }
        else if ( m == v2.size()){
            v3[v3pos++] = v1[n++];
            continue;
        }
        
        if (v1[n] == v2[m]){
            v3[v3pos++] = v1[n++];
            v3[v3pos++] = v2[m++];
        }
        else if (v1[n] > v2[m]){
            v3[v3pos++] = v2[m++];
            
        }
        else if (v1[n] < v2[m]){
            v3[v3pos++] = v1[n++];
        }
    }
    
    return v3;
}

int main(int argc, const char * argv[]) {

    vector<int> v1 = {2,3,4,5,6,7,8};
    vector<int> v2 = {1,5,7,9,10,11,12,13};
    
    vector<int> v3 = Merge(v1, v2);
    for (int i = 0; i != v3.size(); i++){
        cout << v3[i] << " ";
    }
    
    cout << endl;
    return 0;
}
