#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    size_t array_size_; // размер массива
    T* array_; // указатель на первый элемент
    size_t count_ = 0; // сколько элементов в стеке
public:
    Stack() :   array_size_{100},
                array_{new T[array_size_]} {}
    
    Stack(size_t n) :   array_size_{n},
                        array_{new T[n]}{}
    
    size_t count() const{ // так как метод только возвращает количество элементов в стеке, а не изменяет его поля, делаем его const
        return count_;
    }
    
    void push(T const &value){ // принимает константный параметр, чтобы случайно не изменить значение переменной по ссылке
        reinitializeMemory();
        array_[count_] = value;
        ++count_;
    }
    
    void reinitializeMemory(){
        // c точки зрения логики блок if должен находиться в push, но так как данная функция сделана для того, чтобы избавиться от большой вложенности, я помещаю ее сюда
        if (count_ == array_size_){
            T* new_array_ = new T[2*array_size_]; // перераспределение памяти (выделение новой)
            for (size_t i = 0; i != array_size_; ++i){
                new_array_[i] = array_[i]; // перезапись из старого массива в новый
            }
            delete[] array_; // удаление старого массива
            array_ = new_array_; // теперь указатель указывает на новый массив
        }
    }
    
    T pop(){
        if (count_ == 0){
            throw runtime_error{ "Ошибка при удалении элемента: стек пуст" };
        }
        --count_;
        return array_[count_];
    }
    
    bool empty(){
        return count_ == 0; // if stack has 0 elements, return true. Else more - false.
    }
    
    ~Stack<T>(){
        delete[] array_; //освобождение памяти
    }
};

#endif /* STACK_HPP */
