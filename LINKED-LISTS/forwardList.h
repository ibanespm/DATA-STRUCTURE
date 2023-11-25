#include <iostream>
#include "List.h"
#include <string>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(){
        data = T();
        next = nullptr;
        prev = nullptr;
    }

    Node(T value){
        data = value;
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

    int nodes = 0; //Cantidad de nodos que deseamos tener

    Node<T>* get_tail() {
        auto tail = head;
        while (tail->next !=nullptr) {
            tail = tail->next;
        }
        return tail;
    }
    //accdemos al prev de node
    Node<T>* prev(Node<T>* node){
        auto current = head;
        while(current->next != node){
            current = current->next;
        }
        return current;
    }
    //retorna el nodo de la posicion que deseamos
    Node<T>*get_node(int position){
        Node<T>* node = head;
        for(int i = 0; i < position; i++ ){ 
            node = node ->next;
            }
        return node;
    }

    //retorna el node del medio

    Node<T>* get_middle(Node<T>* start) {
        Node<T>* middle = start;
        Node<T>* fast = start->next;
        while (fast && fast->next) {
            middle = middle->next;
            fast = fast->next->next;
        }
        return middle;
    }
    Node<T>* merge(Node<T>* left, Node<T>* right){

        auto dummyHead = new Node<T>();
        auto current = dummyHead;

        while(left and right){
            if (left->data <= right->data){
                current->next = left;
                left = left->next;
                current = current-> next;
            } else {
                current->next = right;
                right = right->next;
                current = current->next;
            }
        }

        while (left){
            current->next = left;
            left = left->next;
            current = current->next;
        }

        while (right){
            current->next = right;
            right = right->next;
            current = current->next;
        }

        return dummyHead->next;
    }

    Node<T>* merge_sort(Node<T>* start) {
        if (!start->next) return start;

        Node<T>* middle = get_middle(start);
        auto start_right = middle->next;

        middle->next = nullptr; // breaking the linked list into two parts

        Node<T>* left = merge_sort(start);
        Node<T>* right = merge_sort(start_right);

        return merge(left, right);
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

    int getNodes(){return this->nodes;};

    //view data
    string to_string();
};


template<typename T>//verificar por favor
T ForwardList<T>::front() {
    if(!is_empty()){
        T DataFront = head->data;
        Node<T>* temporal = head;
        head = head->next;
        delete temporal;
        nodes = nodes -1;

        return DataFront;

    }
    else{throw std::runtime_error("Forward list is empty");}
}

//devuelve data del ultimo nodo
template<typename T>
T ForwardList<T>::back() {
    if(!is_empty()){
        return get_tail()->data;
    }
    else{
        throw std::runtime_error("Forward list is empty");
    }
}

//agregamos por el frente
template<typename T>
void ForwardList<T>::push_front(T data) {
   Node<T> * node = new Node<T>(data);
   if(!is_empty()){

   node->next = head;
   this->head = node;
   this->nodes = this->nodes + 1;

   }
   else{
    node->next = head;
    this->head = node;
    this->nodes = this->nodes + 1;
    node->next = nullptr;
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
        nodes--;
        return deleteData;
    }
    else{
        throw std::runtime_error("forward list is empty");
    }

}


template<typename T>
T ForwardList<T>::pop_back() {
    if(!is_empty()){
        auto _tail = get_tail();
        auto prevTail =  prev(_tail);
        auto current = head;
        // while(!(current->next = ))
        Node<T>*newTail = prevTail;
        T back = _tail->data;
        delete _tail;
        newTail->next = nullptr;
        this->nodes = this->nodes - 1;
        return back;


    }
    else{
        throw std::runtime_error("Forward list is empty");
    }
}
template<typename T>
void ForwardList<T>::push_back(T data){
    if(is_empty())
        push_front(data);
    else {
        auto node = new Node<T>(data);
        auto tail = get_tail();
        tail->next = node;
        nodes=nodes+1;
        node->next = nullptr;
    }
    
}


//inser del elemento en la posicion indica
template<typename T>
T ForwardList<T>:: insert(T data, int pos){
    if((pos < 0) || (nodes <= pos)){
        throw std::runtime_error("rango not");
    };

    auto node = new Node<T>(data);
    auto prev_node = get_node(pos - 1);
    auto next_node = get_node(pos);

    prev_node->next = node;
    node->next = next_node;
    nodes++;

    return data;
}

template<typename T>
int ForwardList<T>::size() {return nodes;}

//verifica  si esta vacio
template<typename T>
bool ForwardList<T>::is_empty() {
    return  !nodes;
}

//elemina todos los nodos
template<typename T>
void ForwardList<T>::clear() {
    while(0 < nodes){
        pop_front();
    }
    head = nullptr;
}

//remover un nodo
template<typename T>
bool ForwardList<T>::remove(int pos) {
    if ((pos < 0) || (nodes <= pos)) {
        throw std::runtime_error("Forward list index out of range");

    };

    if (pos == 0) { pop_front(); }
    else if (pos == nodes - 1) pop_back();
    else {
        Node<T> *node = get_node(pos);
        Node<T> *prev_node = get_node(pos - 1);
        Node<T> *next_node = get_node(pos + 1);
        prev_node->next = next_node;
        delete node;
        nodes = nodes - 1;
    }
    return true;
}
//arncceder con indice[ ]
template<typename T>
T& ForwardList<T>::operator[](int position) {
    if ((position < 0) || (nodes <= position)){
        throw std::runtime_error("Not range");
    }
    else{
        Node<T>* node  = get_node(position);
        return node->data;
    }

}

//ordenamiento de los nodos
template<typename T>
void ForwardList<T>::sort() {
    head = merge_sort(head);

}

//verifica si esta ordenado
template<typename T>
bool ForwardList<T>::is_sorted() {
    if(nodes <= 1){return  true;}
    Node<T>* current = head;
        while(current->next != nullptr){
        if((current->data) > (current->next->data)){
            return false;
        }
        current = current->next;
    }
    return true;

}

//revierte los elementos
template<typename T>

void ForwardList<T>::reverse(){
    if(nodes <= 1) return;
    // It's all about updating tha link part of the nodes and head pointer
    auto current = head;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;

    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
//devueve el nombre de la clase
template<typename T>
string ForwardList<T>::name() {
    return "Forward List";

}
template<typename T>
string ForwardList<T>::to_string() {
    string result = "";
    auto node = head;
    while (node)  {
        result += " " + std::to_string(node->data); // Convierte T a cadena
        node = node->next;
    }
    return result;
}


#ifndef DATA_STRUCTURE_FORWARDLIST_H
#define DATA_STRUCTURE_FORWARDLIST_H

#endif //DATA_STRUCTURE_FORWARDLIST_H
