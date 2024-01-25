#ifndef NODE_H
#define NODE_H

using namespace std;


//STRUCT NODE 

template<typename T>
struct NodeBST {
    T data;
    NodeBST* left;
    NodeBST* right;
    NodeBST(){
        this->left = nullptr;
        this->right = nullptr;
    };
    NodeBST(T value){
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    };
    
    void Killseft(NodeBST * node){
        if(node == nullptr) return void();
        Killseft(node->left);
        Killseft(node->right);
        delete node;
    };


    void KillSelt(){
        KillSelt(left);
        Killseft(right);
    };

};

#endif