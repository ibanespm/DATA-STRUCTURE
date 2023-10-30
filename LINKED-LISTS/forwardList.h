#include <iostream>


template<class T>
struct Node{
    T data;
    Node<T>*next;
    Node<T>*prev;

    //construtores

    Node(){
        data = T(); //asegurar valor T(), y no contenido basura
        next= nullptr;
        prev = nullptr;
    }

    //constructor con data
    Node(T data){
        this->data = data ;
        next = nullptr;
        prev = nullptr;
    }

    void killSelf(){
        delete this;
    }

    ~Node(){
        next = nullptr;
        prev = nullptr;
    }

};

template<class T>
class forwardList{
private:

    Node<T> * head;
    int nodes;
    Node<T>* getTail(){
        Node<T>* tail = head;
        while(tail->next){ //mientras que no se nullptr se ejecuta
            tail = tail->next;
        }
        return tail;
    }

    Node<T>*prev(Node<T>*node){
        Node<T>* current = head;
        while
    }



public:

};




#ifndef DATA_STRUCTURE_FORWARDLIST_H
#define DATA_STRUCTURE_FORWARDLIST_H

#endif //DATA_STRUCTURE_FORWARDLIST_H
