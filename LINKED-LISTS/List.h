#ifndef LIST_H
#define LIST_H

//
// Created by IBAÑES on 30/10/2023.
//
#include <string>
using namespace std;

//CLASE PADRE DE LIKED LIST
template<class T>
class List{
public:
    virtual ~List(){};

    //con el 'virtual puro' hacemos que las clases derivadas puedan
    //sobre escribir sus metodos heredados.
    //'virtual puro' por que = 0

    //Métodos

    virtual T front() = 0;
    virtual T back() = 0;
    virtual void push_front(T) = 0;
    virtual void push_back(T) = 0;
    virtual T pop_front() = 0;
    virtual T pop_back() = 0;
    virtual T insert(T, int) = 0;
    virtual bool remove(int) = 0;
    virtual T& operator[](int) = 0;//debe ser declarado en cada clase hija
    virtual bool is_empty() = 0;
    virtual int size() = 0;
    virtual void clear() = 0;
    virtual void sort() = 0;
    virtual bool is_sorted() = 0;
    virtual void reverse() = 0;
    virtual std::string name() = 0;
    virtual std::string to_string() = 0;

    virtual int getNodes()= 0;

};

#endif // LIST_H