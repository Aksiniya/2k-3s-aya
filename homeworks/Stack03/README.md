[![Build Status](https://travis-ci.org/Aksiniya/2k-3s-aya-hw03.svg?branch=master)](https://travis-ci.org/Aksiniya/2k-3s-aya-hw03)

## HomeWork III (Stack)

## Tasks

- [x] 1. Для шаблонного класса stack реализовать:
       - конструктор с параметром (размер выделяемого массива)
       - конструктор копирования
       - конструктор перемещения
       - оператор присваивания с семантикой копирования
       - оператор присваивания с семантикой перемещения
- [x] 2.Сделать класс stack безопасным относительно исключений (обеспечивающим строгую гарантию), заменив метод `pop` на два соответствующих pop и top.
- [x] 3.Пометить все методы одной из трех меток
       - /*basic*/
       - /*strong*/
       - /*noexcept*/
- [x] 4.Настроить интеграцию с сервисом Travis CI.

## Output:

example1.cpp
```ShellSession
 Stack<int> sint1
 sint1 : { }
 Stack<int> sint2(10, 5, new int[5]{1,2,3,4,5})
 sint2 : { 1 2 3 4 5 }
 Stack<int> sint3(sint2)
 sint2 : { 1 2 3 4 5 }
 sint3 : { 1 2 3 4 5 }  // copy from sit2
 Stack<int> sint4(move(sint2))
 sint2 : { }
 sint3 : { 1 2 3 4 5 }
 sint4 : { 1 2 3 4 5 }  // move from sint2
 Stack<int> sint5 = sint4
 sint2 : { }
 sint3 : { 1 2 3 4 5 }
 sint4 : { 1 2 3 4 5 }
 sint5 : { 1 2 3 4 5 }  // copy with = from sint4
 Stack<int> sint6 = move(sint4)
 sint2 : { }
 sint3 : { 1 2 3 4 5 }
 sint4 : { }
 sint5 : { 1 2 3 4 5 }
 sint6 : { 1 2 3 4 5 }  // move with = from sint4
```
