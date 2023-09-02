#include <iostream>

template<class T>
class CircularArray{
private:
    T *array;
    int back;
    int front;
    int capacity;

public:
    CircularArray();
    CircularArray<T>(int _capacity=10){};



    void push_front(T data); //ok
    void push_back(T data);  //ok
    void insert(T data);
    bool is_empty();
    bool is_full();
    void resize();
    int size();



};

template<typename  T>
void CircularArray<T>::push_front(T data) {
    if(is_empty()){
        this->front=0;
        this->back=0;
        this->array[front]=data;
    }
    else if(is_full()){
        resize();
        if(back >= front){
            this->front=(capacity-front-1)%capacity;
            this->array[front]=data;

        }
        else if(front<back){
            this->front=this->front-1;
            this->array[front]=data;
        }
    }
    else{
        if(back <= front){
            this->front=(capacity-front-1)%capacity;
            this->array[front]=data;
        }
        else{
            this->front=front-1;
            this->array[front]=data;
        }
    }
}

template<typename T>
void CircularArray<T>::push_back(T data) {

    if(!is_empty() and !is_full()){
        this->back=back+1;
        this->array[back]=data;
    }
    else if(is_full()){
        resize();
        this->back=back+1;
        this->array[back]=data;
    }
    else if(is_empty()) {
        this->back = (back + 1) % capacity;
        this->array[back] = data;
    }

}


template<typename T>

void CircularArray<T>::insert(T data){

}
template<typemane T>
bool CircularArray<T>::is_empty(){

}

template <typename T>
class Circular<T>::is_full(){

}