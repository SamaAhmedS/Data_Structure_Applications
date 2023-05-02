#ifndef SINGLE_LINKED_lIST_H
#define SINGLE_LINKED_lIST_H
#include"Single Linked List.h"
#endif 
template<class T>
class Stack {
    singleLinkedList<T> s;
public:
    void push(T element) {
        s.insertAtTail(element);
    }
    T pop() {//return the first element and remove it.
        if (s.isEmpty()) {
            cerr << "stack is empty can not pop\n";
            exit(1);
        }

        T element = s.retrieveAt(s.linkedListSize() - 1);

        s.removeAtTail();

        return element;
    }
    T top() {//return the first element without removing it.
        if (s.isEmpty()) {
            cerr << "stack is empty\n";
            exit(1);
        }
        return s.retrieveAt(s.linkedListSize() - 1);
    }
    bool isEmpty() { return s.isEmpty(); }
    int stackSize() { return s.linkedListSize(); }
    void clear() { s.clear(); }
    void print() { s.print(); }
};

//---------------------------------------------------------------------------------------------------------------------------
