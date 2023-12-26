#ifndef CIRCULAR_Haa
#define CIRCULAR_Haa
#pragma once

#include <iostream>
#include "list.h"


// CLASS DOUBLE LIST
/*Implementacion de class doublue list, con los metodos que estan en la parte publica de la clase
   */



template<class T>
struct CircularNodeDoubleList {
    CircularNodeDoubleList<T>* prev;
    T data;
    CircularNodeDoubleList<T>* next;

    CircularNodeDoubleList() : prev(nullptr), data(T()), next(nullptr) {}
    CircularNodeDoubleList(T value) : prev(nullptr), data(value), next(nullptr) {}
    ~CircularNodeDoubleList() {}
};

template <typename T>
class CircularList : public List<T> {
private:
    CircularNodeDoubleList<T>* head; // sentinel
    int nodes;

public:
    CircularList() : List<T>() {
        head = new CircularNodeDoubleList<T>();
        head->next = head;
        head->prev = head;
        nodes = 0;
    }

    ~CircularList() {
        clear();  // Llama al método clear para eliminar todos los nodos antes de eliminar head.
        delete head;
    }

    T front() {
        if (is_empty()) {
            throw std::runtime_error("Circular list is empty");
        }
        return head->next->data;
    }

    T back() {
        if (is_empty()) {
            throw std::runtime_error("Circular list is empty");
        }
        return head->prev->data;
    }

    void push_front(T data) {
        auto node_new = new CircularNodeDoubleList<T>(data);
        node_new->next = head->next;
        node_new->prev = head;

        head->next->prev = node_new;
        head->next = node_new;
        nodes++;
    }

    void push_back(T data) {
        auto node = new CircularNodeDoubleList<T>(data);
        node->next = head;
        node->prev = head->prev;

        head->prev->next = node;
        head->prev = node;
        nodes++;
    }

    T pop_front() {
        if (is_empty()) {
            throw std::runtime_error("Circular list is empty");
        }
        auto front = head->next;
        T data = front->data;

        head->next = front->next;
        front->next->prev = head;
        delete front;
        nodes--;
        return data;
    }

    T pop_back() {
        if (is_empty()) {
            throw std::runtime_error("Circular list is empty");
        }
        auto back = head->prev;
        T data = back->data;

        head->prev = back->prev;
        back->prev->next = head;
        delete back;
        nodes--;
        return data;
    }

    T insert(T data, int pos) {
        if (pos < 0 || pos > nodes) {
            throw std::runtime_error("Circular list index out of range");
        }

        auto previous = head;
        while (pos--) {
            previous = previous->next;
        }

        auto node = new CircularNodeDoubleList<T>(data);
        node->prev = previous;
        node->next = previous->next;

        previous->next->prev = node;
        previous->next = node;

        ++nodes;

        return data;
    }

    bool remove(int pos) {
        if (pos < 0 || pos > nodes) {
            throw std::runtime_error("Circular list index out of range");
            return false;
        }
        auto p = head;
        while (pos--) {
            p = p->next;
        }
        auto current = p->next;

        p->next = current->next;
        current->next->prev = p;
        delete current;
        return true;
    }

    T& operator[](int pos) {
        if (pos < 0 || nodes <= pos) {
            throw std::runtime_error("Forward list index out of range");
        }
        auto current = head->next;
        while (pos--) {
            current = current->next;
        }
        return current->data;
    }

    bool is_empty() {
        return !nodes;
    }

    int size() {
        return nodes;
    }

    void clear() {
        while (nodes > 0) {
            pop_front();
        }
    }

    void sort() {
        merge_sort();
    }

    bool is_sorted() {
        if (nodes <= 1) {
            return true;
        }

        auto a = head->next;
        while (a != head->prev) {
            if (a->data > a->next->data) {
                return false;
            }
            a = a->next;
        }
        return true;
    }

    void reverse() {
        if (nodes <= 1) return;

        CircularNodeDoubleList<T>* current = head->next;
        CircularNodeDoubleList<T>* temporal;

        while (current != head) {
            temporal = current->prev;
            current->prev = current->next;
            current->next = temporal;
            current = current->prev;
        }
        temporal = head->prev;
        head->prev = head->next;
        head->next = temporal;
    }

    std::string name() {
        return "CircularList";
    }

    void display(std::ostream& os) {
        auto k = head->next;
        os << "head ⇄ ";
        while (k != head) {
            os << k->data << " ⇄ ";
            k = k->next;
        }
        os << "head\n";
    };

    int getNodes() { return nodes; };

    std::string to_string() {
        return "";  // Implementa la conversión a cadena según sea necesario.
    }

private:
    void merge_sort();
    void merge(CircularList<T>&, CircularList<T>&);
    CircularNodeDoubleList<T>* get_middle();
    void split_list(CircularNodeDoubleList<T>*, CircularList<T>&, CircularList<T>&);
};

template <typename T>
void CircularList<T>::merge_sort() {
    if (nodes <= 1) return;

    auto middle = get_middle();
    CircularList<T> leftList, rightList;

    split_list(middle, leftList, rightList);

    leftList.merge_sort();

    rightList.merge_sort();

    merge(leftList, rightList);
}

template <typename T>
CircularNodeDoubleList<T>* CircularList<T>::get_middle() {
    auto slow = head->next;
    auto fast = head->next;
    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
void CircularList<T>::split_list(CircularNodeDoubleList<T>* middle, CircularList<T>& leftList, CircularList<T>& rightList) {
    auto current = head->next;
    while (current != middle) {
        leftList.push_back(current->data);
        current = current->next;
    }
    while (current != head) {
        rightList.push_back(current->data);
        current = current->next;
    }
}

template <typename T>
void CircularList<T>::merge(CircularList<T>& leftList, CircularList<T>& rightList) {
    auto leftCurrent = leftList.head->next;
    auto rightCurrent = rightList.head->next;

    while (leftCurrent != leftList.head && rightCurrent != rightList.head) {
        if (leftCurrent->data < rightCurrent->data) {
            push_back(leftCurrent->data);
            leftCurrent = leftCurrent->next;
        } else {
            push_back(rightCurrent->data);
            rightCurrent = rightCurrent->next;
        }
        pop_front();
    }

    while (leftCurrent != leftList.head) {
        push_back(leftCurrent->data);
        pop_front();
        leftCurrent = leftCurrent->next;
    }

    while (rightCurrent != rightList.head) {
        push_back(rightCurrent->data);
        pop_front();
        rightCurrent = rightCurrent->next;
    }
}

#endif // CIRCULAR_Haa
