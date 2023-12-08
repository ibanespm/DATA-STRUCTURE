#include <iostream>
#include "OpenAddressingHashTable.h"

int main() {
    // Ejemplo de uso con open addressing
    OpenAddressingHashTable<int, std::string> newTable(10);
    newTable.insert(1, "One");
    newTable.insert(11, "Eleven");
    newTable.insert(21, "Twenty-One");
    newTable.display();

    return 0;
}
