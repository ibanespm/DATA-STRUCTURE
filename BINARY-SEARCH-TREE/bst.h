#include "node.h"
#include <iostream>

using namespace std;

template<class T>
class BSTree{
    private:




    public:


    BSTree():root(nullptr){};                                 //constructor
    void insert(T value){insert(root,value);};          //instertar elemento
    bool find(T value){return find(root,value);};     //encuentra un elemento-bool
    void remove(T value){ remove(root,value);};     //remueve un elemento
    T minValue(){return  minValue(root);};             //retorna el min elemento
    T maxValue(){return maxValue(root);};            //retorna el  maximo elemento 
    
    //maneras de mostrar elementos(recorridos)

    string display_in_order(){};
    string display_pre_order(){};
    string display_post_order(){};      //
    string displayBFS(){};                  //recorrido de anchura
    string displayDFS(){}                   //recorrido de porfundidad



    int height(){};
    bool is_balanced(){};
    int size (){};
    bool is_full(){};

    T succesor(T value){};
    T  predecesor (T value);
    void value()();


    private:


    
    void insert(NodeBST*& node, T value){
        if(node == nullptr){node = new NodeBST(value);}
        else if (value <node->data){insert(node->left, value);}
        else if (value>node->data){insert(node->right,value);}
    };
    

    
    //encuestra el elemeto, si existe retunr true

    bool find(NodeBST * &node, T value){


        if(node==nullptr){return false;};
        else if (value<node->data){return find(node->left, value);};
        else if (value>node->data){return find(node->right,value);};

        return true;
    };


    
    void remove(NodeBST*&node, T value){
        
    }

    






};