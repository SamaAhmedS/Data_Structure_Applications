#pragma once
#include <iostream>
using namespace std;
#include <regex>
#include<vector>
#include<set>
#include <stdexcept>
#define ll long long
template<class T>
struct node {
    T value;
    node* next;
    node() {
        next = nullptr;
    }
    node(T element) {
        value = element;
        next = nullptr;
    }
};
template<class T>
class singleLinkedList {
    int size;
    node<T>* first, * last;
public:
    singleLinkedList() {
        size = 0;
        first = nullptr; last = nullptr;
    }
    singleLinkedList& operator=(singleLinkedList<T> other);
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);//assume that index is one based
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void swap(int idx1, int idx2); // swap two nodes withoutswapping data.
    bool isEmpty() {
        return(size == 0);
    }
    int linkedListSize() { return size; }
    void clear();
    void print();

    ~singleLinkedList() {
        clear();
    }
    node<T>* get_First() {
        return first;

    }

};