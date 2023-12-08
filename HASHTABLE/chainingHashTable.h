#ifndef CHAININGHASHTABLE_H
#define CHAININGHASHTABLE_H

#include "hashTable.h"
#include <list>

template<typename KEY, typename VALUE>
class ChainingHashTable : public HashTable<KEY, VALUE> {
private:
    std::vector<std::list<std::pair<KEY, VALUE>>> tableHash;
    int capacity;

public:
    ChainingHashTable(int capacity);
    void insert(const KEY &key, const VALUE &value) override;
    bool search(const KEY &key, VALUE &value) const override;
    bool remove(const KEY &key, VALUE &value) override;
    void display() const override;
    ~ChainingHashTable() {};
};

template<typename KEY, typename VALUE>
ChainingHashTable<KEY, VALUE>::ChainingHashTable(int capacity) : capacity(capacity), tableHash(capacity) {}

template<typename KEY, typename VALUE>
void ChainingHashTable<KEY, VALUE>::insert(const KEY &key, const VALUE &value) {
    int index = key % this->capacity;
    tableHash[index].emplace_back(key, value);
}

template<typename KEY, typename VALUE>
bool ChainingHashTable<KEY, VALUE>::search(const KEY &key, VALUE &value) const {
    int index = key % capacity;

    for (const auto &entry : tableHash[index]) {
        if (entry.first == key) {
            value = entry.second;
            return true;
        }
    }

    return false;
}

template<typename KEY, typename VALUE>
bool ChainingHashTable<KEY, VALUE>::remove(const KEY &key, VALUE &value) {
    int index = key % capacity;

    for (auto it = tableHash[index].begin(); it != tableHash[index].end(); ++it) {
        if (it->first == key) {
            value = it->second;
            tableHash[index].erase(it);
            return true;
        }
    }

    return false;
}

template<typename KEY, typename VALUE>
void ChainingHashTable<KEY, VALUE>::display() const {
    for (int i = 0; i < capacity; ++i) {
        std::cout << i << ": ";
        for (const auto &entry : tableHash[i]) {
            std::cout << "(" << entry.first << ", " << entry.second << ") ";
        }
        std::cout << std::endl;
    }
}

#endif // CHAININGHASHTABLE_H
