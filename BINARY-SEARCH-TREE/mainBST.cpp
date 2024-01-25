#include <iostream>
#include <stdlib.h> 
#include "bst.h"
#include "tester.h"

using namespace std;

int main()
{
    BSTree<int> *bstree = new BSTree<int>();
    bstree->insert(8);
    bstree->insert(3);
    bstree->insert(1);
    bstree->insert(6);
    bstree->insert(4);
    bstree->insert(7);
    bstree->insert(10);
    bstree->insert(14);
    bstree->insert(13);

    ASSERT(bstree->isBalanced() == false, "The function isBalanced is not working", 1);
    ASSERT(bstree->displayInOrder() == "1 3 4 6 7 8 10 13 14 ", "The function displayInOrder is not working", 1);
    ASSERT(bstree->displayBFS() == "8 3 10 1 6 14 4 7 13 ", "The function displayBFS is not working", 1);
    ASSERT(bstree->height() == 3, "The function height is not working", 1);
    ASSERT(bstree->minValue() == 1, "The function minValue is not working", 1);
    ASSERT(bstree->maxValue() == 14, "The function maxValue is not working", 1);
    ASSERT(bstree->size() == 9, "The function size is not working", 1);
    ASSERT(bstree->successor(3) == 4, "The function successor is not working", 1);
    ASSERT(bstree->successor(4) == 6, "The function successor is not working", 1);
    ASSERT(bstree->successor(7) == 8, "The function successor is not working", 1);
    ASSERT(bstree->successor(13) == 14, "The function successor is not working", 1);
    ASSERT(bstree->predecessor(4) == 3, "The function predecessor is not working", 1);
    ASSERT(bstree->predecessor(8) == 7, "The function predecessor is not working", 1);
    ASSERT(bstree->predecessor(10) == 8, "The function predecessor is not working", 1);
    ASSERT(bstree->predecessor(13) == 10, "The function predecessor is not working", 1);
    
    /*-----------------------iterator---------------------------------*/
    string result = "";
    BSTree<int>::iterator ite = bstree->begin(BSTIterator<int>::Type::PreOrder);
    while(ite != bstree->end()) {
        result += std::to_string(*ite) + " ";
        ++ite;
    }
    ASSERT(result == "8 3 1 6 4 7 10 14 13 ", "The PreOrder iterator is not working",3);
    
    result = "";
    ite = bstree->begin(BSTIterator<int>::Type::PostOrder);
    while(ite != bstree->end()) {
        result += std::to_string(*ite) + " ";
        ++ite;
    }
    ASSERT(result == "1 4 7 6 3 13 14 10 8 ", "The PostOrder iterator is not working",3);
    /*---------------------------------------------------------------*/


    bstree->remove(10);
    ASSERT(bstree->successor(8) == 13, "The function successor is not working", 1);
    ASSERT(bstree->predecessor(13) == 8, "The function predecessor is not working", 1);
    bstree->remove(8);
    ASSERT(bstree->successor(7) == 13, "The function successor is not working", 1);
    ASSERT(bstree->predecessor(13) == 7, "The function predecessor is not working", 1);
    ASSERT(bstree->displayInOrder() == "1 3 4 6 7 13 14 ", "The function remove is not working",1);
    bstree->clear();
    bstree->insert(8);
    ASSERT(bstree->size() == 1, "The function clear is not working",1);
    



    /*-----------------------BST from ordered array---------------------------------*/
    int array[] = {1,5,7,8,9,11,12,13,15,18,20,22,25,26};
    bstree->clear();
    bstree->buildFromOrderedArray(array, 14);    
    ASSERT(bstree->minValue() == 1, "The function minValue is not working", 1);
    ASSERT(bstree->maxValue() == 26, "The function maxValue is not working", 1);
    ASSERT(bstree->successor(8) == 9, "The function successor is not working", 1);
    ASSERT(bstree->predecessor(8) == 7, "The function predecessor is not working", 1);
    ASSERT(bstree->successor(15) == 18, "The function successor is not working", 1);
    ASSERT(bstree->predecessor(15) == 13, "The function predecessor is not working", 1);
    ASSERT(bstree->isBalanced() == true, "The function buildFromOrderedArray is not working",1);
    /*---------------------------------------------------------------*/

    return 0;
}