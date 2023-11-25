#include <iostream>
#include "ARRAY-CIRCULAR/CircularArray.h"
#include "ARRAY-CIRCULAR/tester.h"

using namespace std;

struct node{
    int data;
    string nombre;
    node* next;
    node* prev;

    //constructor
    node(int data,string nombre){
        this->data = data;
        this->nombre = nombre;
        next = nullptr;
        prev = nullptr;
    }
    string to_string(){
        return this->nombre;
    }
    int getdata(){
        return this->data;
    }
};

class vamos{
protected:
    int nodes;
    node *head;

};

int main() {
    node* new_node = new node(34, "ibañes");
    node* s = new_node;
    cout<<new_node<<endl;
    cout<<s->data;


    return 0;
}
