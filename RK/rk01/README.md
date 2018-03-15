## РК 1 по предмету "Алгоритмические языки"

## Task 1 
- [x] Написать функцию разворота списка
```
struct Node {
  int data;
  Node * next;
};

Node * reverse( Node * head ) {
}
```

# Task 2
- [x] Дана неубывающая посследовательность чисел, нужно найти 2 числа этой последовательности, сумма которых равна определенному числу. Указать категорию итераторов.
```
template <typename Iterator, typename T>
auto find_two_elements_with_sum( Iterator first, Iterator last, T c )
-> std::pair<bool, std::pair<Iterator, Iterator>>
```

# Task 3
- [x] Реализовать функцию слияния двух отсортированных массивов. Указать категорию итераторов.
```
template <typename Iterator1, typename Iterator2>
auto merge( Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output ) -> Iterator2
```

# Task 4
- [ ] Реализовать функцию сортировки массива, **использующую** дополнительную память. Указать категорию итераторов.
```
template <typename Iterator1, typename Iterator2>
void merge_sort( Iterator1 first, Iterator1 last, Iterator2 memory )
```

# Task 5
- [ ] Реализовать функцию сортировки массива, **не использующую** дополнительную память. Указать категорию итераторов.
```
template <typename Iterator>
void merge_sort( Iterator first, Iterator last )
```

# Output
# Task 1
```ShellSession
1  2  3  
1  2  3
3  2  1
```
# Task 2
```ShellSession
В векторе vint существует два элемента, сумма которых равна 7
1 + 6 = 7
```
# Task 3
```ShellSession
1 2 3 4 5 5 6 7 8 9 10 11 12 
```
