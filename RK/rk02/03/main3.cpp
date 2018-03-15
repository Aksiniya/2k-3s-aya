#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node * next;
};

Node * reverse( Node * head ) {
    vector<Node*> vn_;
    
    //заполнение вектора указателей на узлы
    vn_.push_back(head);
    Node * n = head->next; // указатель на второй элемент
    do{
        vn_.push_back(n);
        n = n->next;
    } while (n->next != nullptr);
    vn_.push_back(n); // добавление последнего
    
    //обращаем порядок указателей
    vn_[0]->next = nullptr;
    for (auto it = vn_.begin() + 1; it < vn_.end(); ++it){
        auto earleit = it - 1;
        (*it)->next = (*earleit);
    }
    
    Node * ret = *(vn_.end()-1);
    
    return ret;
}

int main() {
    Node n1;
    n1.data = 1;
    Node n2;
    n2.data = 2;
    Node n3;
    n3.data = 3;
    
    n1.next = &n2;
    n2.next = &n3;
    n3.next = nullptr;
    
    cout << n1.data << "  " << n2.data << "  " << n3.data << "  " << endl;
    cout << n1.data << "  " << n1.next->data << "  " << n1.next->next->data << endl;
    
    Node n4 = *reverse(&n1);
    cout << n4.data << "  " << n4.next->data << "  " << n4.next->next->data << endl;
    
    return 0;
}
