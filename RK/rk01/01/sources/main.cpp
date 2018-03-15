#include <iostream>
#include <vector>
#include "reverse.h"
using namespace std;

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
