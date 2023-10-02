#include <iostream>
#include "ARRAY-CIRCULAR/CircularArray.h"
#include <typeinfo>
using namespace std;



int main() {
    CircularArray<int> *arra = new CircularArray<int>(6);

    std::cout <<"is full:"<<arra->is_full()<<endl;
    std::cout<<"is empty:"<<arra->is_empty()<<endl;
    std::cout<<"is size : "<<arra->size()<<endl;
    std::cout << "Contenido: " << arra->to_string(" ") << std::endl;
    std::cout << "Capacidad: " << arra->getcapacity() << std::endl;
    std::cout<<endl;
    arra->push_back(1);
    arra->push_back(2);
    arra->push_back(3);
    arra->push_back(4);
    arra->push_back(5);
    arra->push_back(6);
    std::cout <<"is full:"<<arra->is_full()<<endl;
    std::cout<<"is empty:"<<arra->is_empty()<<endl;
    std::cout<<"is size : "<<arra->size()<<endl;
    std::cout << "Contenido: " << arra->to_string(" ") << std::endl;
    std::cout << "Capacidad: " << arra->getcapacity() << std::endl;
    std::cout<<endl;
    arra->push_front(10);
    arra->push_front(20);
    arra->push_front(30);
    arra->push_front(40);
    arra->push_front(50);
    arra->push_front(60);
    std::cout<<endl;
    std::cout <<"is full:"<<arra->is_full()<<endl;
    std::cout<<"is empty:"<<arra->is_empty()<<endl;
    std::cout<<"is size : "<<(arra->size())<<endl;
    std::cout << "Contenido: " << arra->to_string(" ") << std::endl;
    std::cout << "Capacidad: " << arra->getcapacity() << std::endl;
    arra->pop_front();
    std::cout << "Contenido: " << arra->to_string(" ") << std::endl;

    //arra->pop_back();










    std::cout<<6%7<<endl;
    CircularArray<char> *arr=new CircularArray<char>(5);
    arr->push_front('a');
    arr->push_front('b');
    arr->push_front('c');
    arr->push_front('d');
    std::cout << "Contenido: " << arr->to_string(" ") << std::endl;
    arr->pop_front();
    std::cout << "Contenido: " << arr->to_string(" ") << std::endl;


// Comprueba que el primer elemento 'X' se ha eliminado y que front se ha ajustado para rebobinar circularmente.

     std::cout<<std::to_string('s');
     return 0;
}

