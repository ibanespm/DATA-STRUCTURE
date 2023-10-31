#include <iostream>
#include "List.h"
#include <string>
using namespace std;

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
class ForwardList: public List<T>{
protected:

    Node<T> * head; //la cabeza de forward list

    int nodes; //Cantidad de nodos que deseamos tener

    Node<T>* getTail(){
        Node<T>* tail = head;
        while(tail->next){   //mientras que no se nullptr se ejecuta
            tail = tail->next;
        }
        return tail;
    }

    //accdemos al prev de node
    Node<T>*prev(Node<T>*node){
        Node<T>* current = head; //iniciamos en la cabeza
        while(current->next = node){
            current = current->next;
        }

        return current;
    }

    //retorna el nodo de la posicion que deseamos
    Node<T>*get_node(int position){
        Node<T>* node = head;
        for(int i = 0; i < position; i++ ){ node ->next;}
        return node;
    }

    //retorna el node del medio

    Node <T> get_middle(Node<T>* start ){
        Node<T>* middle = start;
        Node<T>* fast = start->next;
        while(fast && fast->next){
            middle = middle->next;
            fast = fast->next->next;
        }
        return middle;
    }

public:
    ForwardList(): List<T>(){}

    ~ForwardList(){
        clear();
        delete head;
    };

    T front();
    T back();
    void push_front(T  data);
    void push_back(T data);
    T pop_front();
    T pop_back();
    T insert(T data, int posi);
    bool remove(int position);
    T& operator[](int position);
    bool is_empty();
    int size();
    void clear();
    void sort ();
    bool is_sorted();
    void reverse();
    string name();
};


template<typename T>//verificar por favor
T ForwardList<T>::front() {
    if(!is_empty()){
        T DataFront = head->data;
        Node<T>* temporal = head;
        head = head->next;
        delete temporal;
        --nodes;
        return DataFront;

    }
    else{throw std::runtime_error("Forward list is empty");}
}

//devuelve data del ultimo nodo
template<typename T>
T ForwardList<T>::back() {
    if(!is_empty()){
        return getTail()->data;
    }
    else{
        throw std::runtime_error("Forward list is empty");
    }
}

//agregamos por el frente
template<typename T>
void ForwardList<T>::push_front(T data) {
    Node<T>* node = new Node<T>(data);
    node->next = this->head;
    this->head = node;
    this->nodes = this->nodes + 1 ;
}

template<class T>
void ForwardList<T>::push_back(T data) {
    if(!is_empty()){
        Node<T>*node  = new Node<T>(data);
        Node<T>*tail = getTail();
        tail->next = node;
        this->nodes = nodes + 1 ;



    }
    else{
        push_front(data);
    }
}

//Eliminamos el nodo del frente(front) y luego retornamos el data eleminado
template <typename T>
T ForwardList<T>::pop_front() {
    if(!is_empty()){
        T deleteData = head->data;
       Node<T>* temporal = head;
       head = head ->next;
       delete temporal;
       this->nodes = this->nodes - 1;
        return deleteData;
    }
    else{
        throw std::runtime_error("forward list is empty");
    }

}

//Elimina el node ultimo(back) y luego retornamo el data eliminado
template<typename T>
T ForwardList<T>::pop_back() {
    if(!is_empty()){
        Node<T>* tail = getTail();
        Node<T>*newTail = tail->prev;
        T back = tail->data;
        delete tail;
        newTail->next = nullptr;
        nodes = nodes - 1 ;
        return back;
    }
    else{
        throw std::runtime_error("Forward list is empty");
    }
}


//inser del elemento en la posicion indica
template<typename T>
T ForwardList<T>::insert(T data, int position) {
    if(!(position < 0) or !(nodes <=position)){
        Node<T>* node = new Node<T>(data);
        Node<T>* nextNode = get_node(position);
        Node<T>* prevNode = get_node(position-1);

        prevNode->next = node;
        node->next = nextNode;
        this->nodes = this->nodes + 1;
    }
    else{
        throw std::runtime_error("position out of range");
    }
}

template<typename T>
int ForwardList<T>::size() {return this->nodes;}

//verifica  si esta vacio
template<typename T>
bool ForwardList<T>::is_empty() {
    return  !nodes;
}

//elemina todos los nodos
template<typename T>
void ForwardList<T>::clear() {
    while(0 < this->nodes){
        this->pop_front();
    }
    head = nullptr;
}


#ifndef DATA_STRUCTURE_FORWARDLIST_H
#define DATA_STRUCTURE_FORWARDLIST_H

#endif //DATA_STRUCTURE_FORWARDLIST_H
