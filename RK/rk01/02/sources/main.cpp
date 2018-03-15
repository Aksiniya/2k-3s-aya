/* Дана неубывающая посследовательность чисел, нужно найти 2 числа этой последовательности, сумма которых равна определенному числу. Указать категорию итераторов. */

/*  template <typename Iterator, typename T>
 auto find_two_elements_with_sum( Iterator first, Iterator last, T c )
 -> std::pair<bool, std::pair<Iterator, Iterator>>  */

#include <vector>
#include "findTwoElementsSum.h"

int main() {
    vector<int> vint = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto p = find_two_elements_with_sum(vint.begin(), vint.end(), 7);
    if (p.first){
        cout << "В векторе vint существует два элемента, сумма которых равна 7" << endl;
        
        cout << *p.second.first << " + " << *p.second.second << " = 7" << endl;
    }
    else {
        cout << "В векторе vint не существует двух элементов, сумма которых равна 7" << endl;
    }
    return 0;
}
