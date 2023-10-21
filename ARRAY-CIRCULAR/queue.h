
#include "CircularArray.h"

template<class T>
class Queue: public CircularArray<T>{
public:
    Queue<T>(int size);
    T dequeue();
    void enqueue(T data);
    void display();
};

template<typename T>
Queue<T>::Queue(int size):CircularArray<T>(size) {}


template<typename T>
T Queue<T>::dequeue() {CircularArray<T>::pop_front();}

template<typename T>
void Queue<T>::enqueue(T data) {CircularArray<T>::push_back(data);}


template<typename T>
void Queue<T>::display() {CircularArray<T>::to_string();}


#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#endif //DATA_STRUCTURE_QUEUE_H
