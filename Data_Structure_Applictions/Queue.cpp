#ifndef SINGLE_LINKED_lIST_H
#define SINGLE_LINKED_lIST_H
#include"Single Linked List.h"
#endif 
template<class T>
class  Queue {
    singleLinkedList<T> q;
public:
    void enqueue(T element) {
        q.insertAtTail(element);
    }
    T dequeue() {//return the first element and remove it.
        if (q.isEmpty()) {
            cerr << "queue is empty\n";
            exit(1);
        }
        T element = q.retrieveAt(0);
        q.removeAtHead();
        return element;
    }
    T  first() {//return the first element without removing it.
        if (q.isEmpty()) {
            cerr << "queue is empty\n";
            exit(1);
        }
        return q.retrieveAt(0);
    }
    bool isEmpty() {
        return q.isEmpty();
    }
    int queueSize() { return q.linkedListSize(); }
    void clear() { q.clear(); }
    void print() {
        q.print();
    }
};

