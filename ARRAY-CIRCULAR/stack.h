#include "CircularArray.h"

template <class T>
class Stack:public CircularArray<T>{
public:
    Stack<T>(int size);
    void push(T data);
    T pop();
    void display();

};

template<typename T>
Stack<T>::Stack(int size) :CircularArray<T>(size){};

template<typename T>
void Stack<T>::push(T data){CircularArray<T>::push_back(data);}

template<typename T>
T Stack<T>::pop() { CircularArray<T>::pop_back();}



template<typename T>
void Stack<T>::display() {CircularArray<T>::to_string();}




#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#endif //DATA_STRUCTURE_STACK_H
