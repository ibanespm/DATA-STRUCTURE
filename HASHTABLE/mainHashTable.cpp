#include <iostream>
#include "OpenAddressingHashTable.h"
#include "chainingHashTable.h"

int main() {
    // Ejemplo de uso con open addressing
    OpenAddressingHashTable<int, std::string> newTable(10);
    newTable.insert(1, "One");
    newTable.insert(11, "Eleven");
    newTable.insert(21, "Twenty-One");
        // Necesitas variables para almacenar los resultados
    std::string value;
    bool found;

    // Correcto: pasa referencias a las variables
    found = newTable.search(1, value);
    if (found) {
        std::cout << "Found: " << value << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    // Correcto: pasa referencias a las variables
    newTable.remove(21, value);
    newTable.display();


    // Ejemplo de uso con chaining
    ChainingHashTable<int, std::string> _newTable(10);
    _newTable.insert(1, "One");
    _newTable.insert(11, "Eleven");
    _newTable.insert(21, "Twenty-One");
    _newTable.insert(8,"four");
    _newTable.insert(3,"five");
    _newTable.insert(7,"fivee");
    _newTable.insert(5,"fiveee");


    _newTable.display();

    return 0;
}
