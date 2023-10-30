
#include "CircularArray.h" //Incluye la definición de la clase CircularArray

template<class T>
class Queue: public CircularArray<T>{ //Definicion de la clase Queue que hereda clase CircularArray
public:
    //Constructor que toma que toma el tamaño de la cola
    Queue<T>(int size);

    //Método para poder eliminar un elemento de la cola
    T dequeue();

    //Método para agregar un elemento a la cola
    void enqueue(T data);

    //Método para mostrar el contenido de la cola
    void display();
};



template<typename T>
Queue<T>::Queue(int size):CircularArray<T>(size) {}//constructor que llama el CircularArray



template<typename T>
T Queue<T>::dequeue() {CircularArray<T>::pop_front();}//elemina el frente de la cola

template<typename T>
void Queue<T>::enqueue(T data) {CircularArray<T>::push_back(data);}// Agregega un elemento a la cola.


template<typename T>
void Queue<T>::display() {CircularArray<T>::to_string();}//Muestra el contenido de la cola.



#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#endif //DATA_STRUCTURE_QUEUE_H
