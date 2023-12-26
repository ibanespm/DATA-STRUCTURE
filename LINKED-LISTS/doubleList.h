#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include "List.h"





template<class T>
struct  NodeDoubleList{
    NodeDoubleList<T>* prev;
    T data;
    NodeDoubleList<T>* next;

    NodeDoubleList(){
        prev = nullptr;
        data = T();
        next = nullptr;
    }
    NodeDoubleList(T value){
        prev = nullptr;
        data = value;
        next = nullptr;
    }
    void killSelf(){
        delete this;
    }
    ~NodeDoubleList(){
        next = nullptr;
        prev = nullptr;
    }
};

template< class T>
class DoubleList:public List<T>{
    protected:
    NodeDoubleList<T>* head;
    NodeDoubleList<T>* tail;
    int nodes = 0;

    NodeDoubleList<T>* node_at(int post) {
        auto* temporalHead = head;
        if ((post > nodes) || (post < 0)) {
            throw std::invalid_argument("Can not access given index.");
        }
        for (int i = 0; i < post; ++i) {
            temporalHead = temporalHead->next;
        }
        return temporalHead;
    }


    public:
    DoubleList() : List<T>() {
        nodes = 0;
        head = nullptr;
        tail = nullptr;
    }
    ~DoubleList() {
        this->clear();
    }

    T front(){};
    T back(){};
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
    int getNodes(){return nodes;}

    //view data
    string to_string();
};

//push front{}
template<typename T>
void DoubleList<T>::push_front(T data ){
    NodeDoubleList<T>* new_node = new NodeDoubleList<T>(data);
    if(!is_empty()){
        new_node->next = head;
        head->prev = new_node;
        new_node->prev = nullptr;
        head = new_node;
    }
    else{
        head = new_node;
        tail = new_node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
    }
    this->nodes = this->nodes + 1;
};

template<typename T>
void DoubleList<T>::push_back(T data){
    NodeDoubleList<T>* new_node = new NodeDoubleList<T>(data);

    if(!is_empty()){
        new_node->prev = tail;
        tail->next = new_node;
        new_node->next = nullptr;
        tail = new_node;
    }
    else{
        head = new_node;
        tail = new_node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
    } 
    this->nodes = this->nodes +1 ;   


}



//is empty 
template<typename T>
bool DoubleList<T>::is_empty(){
    return nodes == 0 ? true: false;}


template<typename T>
string DoubleList<T>::name(){
    return "Double List";
}


//display data 
template <typename T>
string DoubleList<T>::to_string(){
    string result = "";
    auto current = head;
    while(current != nullptr){

        result +=" " + std::to_string(current->data);
        current = current->next; 
    }
    return result;
}

template<typename T>
T DoubleList<T>::pop_front(){
     T data_delete = head->data;
    if(!is_empty()){
        if(nodes > 1){
            NodeDoubleList<T>* temp = head;
            head= head->next;
            head->prev = nullptr;
            delete temp;
        }
        else if (nodes == 1){
            head= nullptr;
            tail = nullptr;}
        this->nodes = this->nodes - 1;  
    }
    else{
        throw std::runtime_error("Double list is empty");
    }
    return  data_delete;
};


template<typename T>
T DoubleList<T>::pop_back(){
    T data_delete = tail->data;
    if (!is_empty())
    {
        if(nodes == 1){
            tail = nullptr;
            head = nullptr;
            
        }
        else{
            NodeDoubleList<T>* temp = tail;
            tail = tail->prev;
            tail->next=nullptr;
            delete temp;
        }
        this->nodes = this->nodes -1 ;
    }
    return data_delete;
};

template<typename T>
T DoubleList<T>::insert(T data, int position){
    NodeDoubleList<T> *new_node = new NodeDoubleList<T>(data);
    
    if (position >= 1 && position <= nodes + 1) {
        if (position == 1) {
            new_node->next = head;
            if (head != nullptr) {
                head->prev = new_node;
            }
            head = new_node;
            
            if (tail == nullptr) {
                tail = new_node;
            }
        } else if (position == nodes + 1) {
            new_node->prev = tail;
            if (tail != nullptr) {
                tail->next = new_node;
            }
            tail = new_node;
            
            if (head == nullptr) {
                head = new_node;
            }
        } else {
            auto prev_current = head;
            auto next_current = head->next;

            for (int i = 0; i < (position - 2); i++) {
                prev_current = prev_current->next;
                next_current = next_current->next;
            }

            prev_current->next = new_node;
            new_node->prev = prev_current;
            next_current->prev = new_node;
            new_node->next = next_current;
        }

        this->nodes++;
    } else {
        throw std::runtime_error("Posición fuera de rango");
    }
};

template<typename T>
bool DoubleList<T>::remove(int position) {
    if (position >= 1 && position <= nodes) {
        NodeDoubleList<T>* current = head;

        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }

        // Adjust pointers to remove the node
        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next; // If removing the first node, update head
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev; // If removing the last node, update tail
        }

        delete current;
        --nodes;

        return true;
    } else {
        throw std::runtime_error("Position out of range");
    }
}

template<typename T>
T& DoubleList<T>::operator[](int position) {
        NodeDoubleList<T>* tmp_node = head;
        if ((position >= nodes) || (position < 0)) {
            throw std::invalid_argument("Can not access given index.");
        }
        for (int i = 1; i < position; ++i) {
            tmp_node = tmp_node->next;
        }
        return tmp_node->data;

}




//return size
template<class T>
int DoubleList<T>::size(){return this->nodes;}

//implementation the clear
template<class T>
void DoubleList<T>::clear(){
    while (head != nullptr) {
            auto* temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
        nodes = 0;
}

//sort implementation
template<typename T>
void DoubleList<T>::sort(){
        for (int iter = 0; iter < nodes - 1; ++iter) {
            for (int i = 0; i < nodes - iter - 1; ++i) {
                NodeDoubleList<T>* h = this->node_at(i);
                if (h->data > h->next->data) {
                    T temp = h->data;
                    h->data = h->next->data;
                    h->next->data = temp;
                }
            }
        }
    }
template<typename T>
bool DoubleList<T>:: is_sorted() {
        for (int i = 0; i < nodes - 1; ++i) {
            if ((*this)[i] > (*this)[i + 1]) {
                return false;
            }
        }
        return true;
}

template<typename T>
void DoubleList<T>::reverse(){
        auto* list_reverse = new DoubleList<T>();
        int coun_nodes = this->nodes;
        for (int iter = 0; iter < coun_nodes; ++iter) {
            list_reverse->push_front(this->pop_front());
        }
        this->clear();
        *this = *list_reverse;
}



#endif // DOUBLELIST_H