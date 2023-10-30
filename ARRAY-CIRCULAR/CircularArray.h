#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Definición de una clase plantilla (template) CircularArray
template<class T>
class CircularArray{
private:
    T *array;
    int back;
    int front;
    int capacity;

public:
    // Constructor predeterminado
    CircularArray();

    // Constructor con capacidad específica (tamaño)
    CircularArray<T>(int _capacity = 10);

    // Inserta un elemento al frente de la cola
    void push_front(T data);

    // Inserta un elemento al final de la cola
    void push_back(T data);

    // Elimina el elemento del frente de la cola
    void pop_front();

    // Elimina el elemento del final de la cola
    void pop_back();

    // Inserta un elemento en una posición específica (no funcional)
    void insert(T data, int position);

    // Verifica si la cola está vacía
    bool is_empty();

    // Verifica si la cola está llena
    bool is_full();

    // Aumenta la capacidad de la cola (redimensiona)
    void resize();

    // Obtiene el tamaño actual de la cola
    int size();

    // Limpia la cola y restaura su capacidad
    void clear();

    // Sobrecarga del operador [] para acceder a elementos por posición
    T& operator[](const int position);

    // Ordena los elementos de la cola
    void sort();

    // Verifica si la cola está ordenada
    bool is_sorted();

    // Invierte el orden de los elementos en la cola
    void reverse();

    // Obtiene la capacidad actual de la cola
    int getcapacity() { return capacity; }

    // Convierte la cola a una cadena de texto con separador opcional
    string to_string(string sep = " ");

private:
    // Calcula el siguiente índice circular
    int next(int);

    // Calcula el índice circular previo
    int prev(int);

    // Métodos de ordenamiento
    void merge(int left, int middle, int right);
    void mergeSort(int left, int right);
};


template<typename T>
CircularArray<T>::CircularArray(int capacity){
    this->capacity=capacity;
    this->front=this->back=-1;
    this->array= new T[capacity];
};


template<typename  T>
void CircularArray<T>::push_front(T data) {
    if(!is_empty() and !is_full()){
        this->front=(front+capacity-1)%capacity;
        this->array[front]=data;
    }
    else if(is_empty()){
        this->front=0;
        this->back=0;
        this->array[front]=data;

    }
    else if(is_full()){
         resize();
         this->front=(capacity +front -1)%capacity;
         this->array[front]=data;


    }
}


template<typename T>
void CircularArray<T>::push_back(T data) {

    if(!is_empty() && !is_full()){
        back = (back + 1) % capacity;
        this->array[back] = data;

    }
    else if(is_full()){
        resize();
        this->back=back+1;
        this->array[back]=data;

    }
    else if(is_empty()) {
        this->back = (back + 1) % capacity;
        this->front=0;
        this->array[back] = data;

    }
}


template<typename T>
void CircularArray<T>::pop_front(){
    if(!is_empty()){
        if(front ==this->capacity-1) {
            this->front = 0;
        }
        else if (front == back) {
            this->front = this->back = -1;
        }
        else {
            this->front = front + 1;
        }
    }
    else {
        cout << "Is empty Array Circular" << endl;
    }
}


template<typename T>
void CircularArray<T>::pop_back(){

    if(!is_empty()){
        if(front == back) {
            this->front = this->back = -1;

        }
        else if(back==0 and front!=0) {
            this->back = capacity - 1;
        }
        else{
            back=back-1;
        }
    }
    else{
        std::cout<<"The arraycircular is empty"<<endl;
    }
}
template<typename T>
void CircularArray<T>::insert(T data, int position){
    if (position < 0 || position > capacity)
        cout<<"Entrate posicion invalida"<<endl;

    if (is_full()) {
        resize();
    }

    if (position == 0) {
        push_front(data);

    }
    else if (position == size()) {
        push_back(data);
    }
    else {
        for (int i = size(); i > position; i--) {
            array[next(i)] = array[i - 1];
        }
        this->array[next(position)] = data;
        this->back = next(back);
    }
}


template<typename T>
bool CircularArray<T>::is_empty(){
    if(size()!=0){
        return false;
    }

    return true;

}

template <typename T>
bool CircularArray<T>::is_full(){
    if(capacity == size()){
        return true;
    }
    return false;

}

template <typename T>
int CircularArray<T>::size() {
    if((front == -1) and (back== -1)) {
        return 0;
    }

    else if(front > back){
        return (capacity -(front - back)+1);
    }

    else if(back> front){
        return (back-front + 1);
    }

    else if(front==0 and back==0){
        return 1;
    }

    else{
        cout<<"algo esta mal front:"<<front<<" back"<<back<<endl;
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
void CircularArray<T>::clear() {
    if(!is_empty()){
        delete[] array;
        this->front = -1;
        this->back = -1;
        this-> capacity = 10;
        array = new T[capacity];
        cout<<"You removed all the elements"<<endl;
    }
    else{
        cout<<"This arraycircular is empty"<<endl;
    }
}


template<typename T >
T& CircularArray<T>::operator[](const int position){
    if( (position < 0)  ||  ( position >=capacity )) cout<<"No valido [ ]"<<endl;
    else{
        int index = front;
        for(auto i=0; i<position; i++){
            index = next(index);
        }
        return  array[index];
    }

}


template<typename T>
void CircularArray<T>::reverse(){
    if(!is_empty()){
        int start = front;
        int end = back;

        while(start != end){
            std::swap(this->array[start] , this->array[end]);
            start = next(start);
            end = prev( end);
        }

    }
}



template<class T>
int CircularArray<T>::prev(int pos) {
    if (pos == 0)
        return capacity-1;
    return pos-1;
}

template<class T>
int CircularArray<T>::next(int pos) {
    if (pos == (capacity-1))
        return 0;
    return pos+1;
}


template<typename T>
void CircularArray<T>::sort() {
    if (!is_empty()) {
        std::vector<T> temp(size());

        for (int i = 0; i < size(); i++) {
            temp[i] = this->array[(front + i) % capacity];
        }
        std::sort(temp.begin(), temp.end());

        for (int i = 0; i < size(); i++) {
            this->array[(front + i) % capacity] = temp[i];
        }
    }
}

template<typename T>
bool CircularArray<T>::is_sorted() {
    if (is_empty() || size() == 1) {
        return true;
    }

    int current = front;
    int next_element = next(current);

    for (int i = 0; i < size() - 1; i++) {
        if (array[current] > array[next_element]) {
            return false;
        }

        current = next_element;
        next_element = next(current);
    }
    return true;
}



template<typename T>
string CircularArray<T>::to_string(string sep) {
    /**
   const int *p = nullptr     p is a pointer to a const int(p es un puntero a un int constante)
   constexpr int *q =nullptr      q is a conts pointer to int(p es un puntero constante a un int  */

    string final_string = "";
    int pos = this->front;

    if(!is_empty()) {
        for(int i = 0; i < size(); i++) {
            if constexpr (std::is_same_v<T, char>) { // el is_same_v verifica que el tipo T sea de char y
                                                     // el stactic_cast se asegura que el tipo char se el correcto

                final_string += static_cast<char>(array[pos]) + sep;
            } else {
                final_string += std::to_string(array[pos]) + sep;
            }
            pos = next(pos);
        }
    }

    return final_string;
}
