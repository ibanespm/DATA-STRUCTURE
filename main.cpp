#include <iostream>
#include "ARRAY-CIRCULAR/CircularArray.h"

int main() {
    CircularArray<int> *arra = new CircularArray<int>(7);
    arra->push_back(1);
    arra->push_back(2);
    arra->push_back(3);
    arra->push_back(4);
    arra->push_back(5);

    // Imprime el resultado de la función to_string
    std::cout << "Contenido: " << arra->to_string(" ") << std::endl;

    return 0;
}

