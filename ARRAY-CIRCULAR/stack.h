#include "CircularArray.h"

template <class T>
class Stack:public CircularArray<T>{ //Creación de la clase Stack heredando la clase CircularArray
public:
    Stack<T>(int size);
    void push(T data);
    T pop();
    void display();

};

template<typename T>
Stack<T>::Stack(int size) :CircularArray<T>(size){};//constructor que llama al CircularArray y define el tamaño de la lista.

template<typename T>
void Stack<T>::push(T data){CircularArray<T>::push_back(data);}//agregamos elemento al stack

template<typename T>
T Stack<T>::pop() { CircularArray<T>::pop_back();}//Elimina el top del stack

template<typename T>
void Stack<T>::display() {CircularArray<T>::to_string();}//Muestra el contenido del stack




#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#endif //DATA_STRUCTURE_STACK_H
