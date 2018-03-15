/* Реализовать функцию слияния двух отсортированных массивов. Указать категорию итераторов.
 template <typename Iterator1, typename Iterator2>
 auto merge( Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output ) -> Iterator2 */

#include <vector>
#include "merge.h"
using namespace std;

int main() {
    // массивы отсортированы по возрастанию
    vector<int> vint1 = { 1, 3, 5, 7 };
    vector<int> vint2 = { 2, 4, 5, 6, 8, 9, 10, 11, 12 };
    vector<int> vintUnion(vint1.size() + vint2.size());
    merge(vint1.begin(), vint1.end(), vint2.begin(), vint2.end(), vintUnion.begin());
    for ( auto i : vintUnion){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
