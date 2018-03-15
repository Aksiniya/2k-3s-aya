## Homework I
Данная домашняя работа посвящена изучению шаблонов и работой с классами.

## Tasks
- [x] 1.Реализовать шаблонный класс `stack`, со следующим интерфейсом:

## Tutorial

```ShellSession
template <typename T>
class stack
{
public:
    stack();
    size_t count() const;
    void push(T const &);
    T pop();
private:
    T * array_;
    size_t array_size_;
    size_t count_;
};
```
## Result
```ShellSession
Latest element in IntStack is: 3
Ошибка при удалении элемента: стек пуст
hello
8 7 6 5 4 3 2 1 
```
## Homework II

## Tasks
- [x] 1. Необходимо добавить метод empty для класа stack.
- [x] 2. Необходимо добавить примеры для всех методов.
- [x] 3. Необходимо добавить конфигурационный файл CMakeLists.txt
- [x] 4. Обеспечить сборку с примерами и сборку без примеров

## Tutorial

```ShellSession
examples/
- init.cpp
- push.cpp
- pop.cpp
- empty.cpp
include/
- stack.hpp
sources/
- main.cpp
CMakeLists.txt
README.md
```

push.cpp result:
```ShellSession
Elements in stack: 4
```

pop.cpp result:
```ShellSession
pop example
```

empty.cpp result:
```ShellSession
6 5 4 3 2 1 0 
```
