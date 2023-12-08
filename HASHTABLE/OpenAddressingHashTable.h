// En el archivo OpenAddressingHashTable.h
#ifndef OPENADDRESSINGHASHTABLE_H
#define OPENADDRESSINGHASHTABLE_H

#include "hashTable.h"
#include <vector>

template<typename KEY, typename VALUE>
class OpenAddressingHashTable : public HashTable<KEY, VALUE> {
private:
    std::vector<std::pair<KEY, VALUE>> tableHash;
    int capacity;

public:
    OpenAddressingHashTable(int capacity);
    void insert(const KEY &key, const VALUE &value) override; 
    bool search(const KEY &key, VALUE &value) const override;
    bool remove(const KEY &key, VALUE &value) override;
    void display() const override;
    ~OpenAddressingHashTable() {};
};




template<typename KEY, typename VALUE>
OpenAddressingHashTable<KEY, VALUE>::OpenAddressingHashTable(int capacity) : capacity(capacity), tableHash(capacity, std::make_pair(KEY(), VALUE())) {}

template<typename KEY, typename VALUE>
void OpenAddressingHashTable<KEY, VALUE>::insert(const KEY &key, const VALUE &value) {
    int index = key % this->capacity;
    while (tableHash[index].first != KEY() && tableHash[index].first != key) {
        index = (index + 1) % capacity;
    }
    tableHash[index] = std::make_pair(key, value);
}

template<typename KEY, typename VALUE>
bool OpenAddressingHashTable<KEY, VALUE>::search(const KEY &key, VALUE &value) const {
    int index = key % capacity;

    while (tableHash[index].first != KEY()) {
        if (tableHash[index].first == key) {
            value = tableHash[index].second;
            return true;
        }
        index = (index + 1) % capacity;
    }

    return false;
}

template<typename KEY, typename VALUE>
bool OpenAddressingHashTable<KEY, VALUE>::remove(const KEY &key, VALUE &value) {
    int index = key % capacity;

    while (tableHash[index].first != KEY()) {
        if (tableHash[index].first == key) {
            tableHash[index] = std::make_pair(KEY(), VALUE());
            return true;
        }
        index = (index + 1) % capacity;
    }

    return false;
}

template<typename KEY, typename VALUE>
void OpenAddressingHashTable<KEY, VALUE>::display() const {
    for (const auto &entry : tableHash) {
        if (entry.first != KEY()) {
            std::cout << "(" << entry.first << "," << entry.second << ") ";
        } else {
            std::cout << "-- EMPTY --";
        }
    }
    std::cout << std::endl;


}
#endif // OPENADDRESSINGHASHTABLE_H
