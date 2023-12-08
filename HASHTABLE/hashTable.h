// En el archivo hashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

template<typename KEY, typename VALUE>
class HashTable {
public:
    virtual void insert(const KEY &key, const VALUE &value) = 0;
    virtual bool search(const KEY &key, VALUE &value) const = 0;
    virtual bool remove(const KEY &key, VALUE &value) = 0;
    virtual void display() const = 0;
    virtual ~HashTable() {}
};

#endif // HASHTABLE_H