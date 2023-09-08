#include <iostream>

using namespace std;

template<class T>
class CircularArray{
private:
    T *array;
    int back;
    int front;
    int capacity;

public:
    CircularArray();
    CircularArray<T>(int _capacity=10);



    void push_front(T data); //ok
    void push_back(T data);  //ok
    void insert(T data);
    bool is_empty();
    bool is_full();
    void resize();
    int size();
    void clear(); // listo
    T& operator[](int);
    void sort();
    bool is_sorted();
    void reverse();


    string to_string(string sep=" ");



};
template<typename T>
CircularArray<T>::CircularArray(int capacity){
    this->capacity=capacity;
    this->front=this->back=-1;
    this->array= new T[capacity];
};


template<typename  T>
void CircularArray<T>::push_front(T data) {
    if(is_empty()){
        this->front=0;
        this->back=0;
        this->array[front]=data;
    }

    else{
        if(is_full()){
            resize();
        }

        if(back <= front){
            this->front=(capacity-front-1)%capacity;
        }
        else{
            this->front=front-1;
        }
        this->array[front]=data;
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


//template<typename T>
//
//void CircularArray<T>::insert(T data){
//
//}


template<typename T>
bool CircularArray<T>::is_empty(){
    if(size()!=0){
        return false;
    }
    else{
    return true;}

}

template <typename T>
bool CircularArray<T>::is_full(){
    if((back+1)%this->capacity == size()){
        return true;
    }
    return false;

}

template <typename T>
int CircularArray<T>::size(){

    if(this->back > this->front){

        return (this->back - this->front + 1);
    }
    else if (this->front > this->back){

        return (this->capacity - (this->front - this->back));
    }
    else if (this->front == this ->back){
        return 0;
    }
}
template<typename T>

void CircularArray<T>::resize(){
    T *temp= new T[capacity*2];
    int i=0;
    int j=front;
    while (i != size()){
        temp[i]=array[i];
        i++;
        j=(j+1) % capacity;

    }
    delete[] array ;
    this->array=temp;
    this->capacity = this->capacity*2;
    this->front=0;

}


template<typename T>
string CircularArray<T>::to_string(string sep) {
    string result="";
    if (!is_empty()){
    for(auto i=0;i<size();i++){
        result += std::to_string(array[i]) + sep;
    }
    }
    return result;
}