#include <iostream>
using namespace std;
template<class T>
struct dNode {
    T value;
    dNode* next, * previous;
    dNode(T element) {
        value = element;
        next = previous = nullptr;
    }
};
template<class T>
class DoublyLinkedList {
    dNode<T>* first, * last;
    int size;
public:
    DoublyLinkedList() {
        size = 0;
        first = last = nullptr;
    }
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T elm, int index);
    void insertAfter(dNode<T>* prev_node, T data);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void swap(int firstItemIdx, int secondItemIdx);  // swap two nodes without swapping data.
    void reverse();  //reverse the data in the double linked list
    bool isEmpty() { return size == 0; }
    int doubleLinkedListSize() { return size; }
    void clear();
    void forwardTraversal();//Print from head to tail
    void backwardTraversal();  //Print from tail to head
    ~DoublyLinkedList() { clear(); }
    dNode<T>* get_First() {
        return first;

    }
};
template<class T>
void DoublyLinkedList<T>::insertAtHead(T element) {
    dNode<T>* current = new dNode<T>(element);
    if (size == 0) {
        first = last = current;
        size++;
        return;
    }size++;
    first->previous = current;
    current->next = first;
    first = current;
}
template<class T>
void DoublyLinkedList<T>::insertAtTail(T element) {
    if (size == 0) {
        insertAtHead(element);
        return;
    }
    dNode<T>* current = new dNode<T>(element);
    current->previous = last;
    last->next = current;
    last = current;
    size++;
}
template<class T>
void DoublyLinkedList<T>::insertAt(T elm, int index) {
    dNode<T>* newNode = new dNode<T>(elm);
    if (index == 0) {
        insertAtHead(elm);
        return;
    }
    if (index > size or index < 0) {
        throw std::out_of_range("out of range");

    }
    if (index == size) {
        insertAtTail(elm);
        return;
    }
    else {
        dNode<T>* Cur = first;
        int c = 0;
        while (c < index) {
            Cur = Cur->next;
            c++;
        }

        newNode->next = Cur;
        newNode->previous = Cur->previous;
        Cur->previous->next = newNode;
        Cur->previous = newNode;
        size++;
        return;
    }
}
template<class T>
void DoublyLinkedList<T>::insertAfter(dNode<T>* prev_node, T data) {
    if (prev_node == nullptr) {
        cerr << "Invalid,as the pointer of previous node is nullptr";
        return;
    }
    //Following is for checking whether the previous node exists in the list 
    bool prevNodeExist = 0;
    dNode<T>* current = first;
    while (current != nullptr) {
        if (current == prev_node) {
            prevNodeExist = 1; break;
        }
        current = current->next;
    }
    if (!prevNodeExist) {
        cerr << "Invalid,as the pointer of previous node is not in this list";
        return;
    }
    current = new dNode<T>(data);
    current->next = prev_node->next;
    current->previous = prev_node;
    if (prev_node->next != nullptr)
        prev_node->next->previous = current;
    prev_node->next = current;
    size++;
}
template<class T>
void DoublyLinkedList<T>::removeAtHead() {
    if (isEmpty()) {
        throw std::out_of_range("Since the list is empty, there are no elements that can be removed");
    }
    else if (size == 1) {
        last = nullptr;
        delete first;
        first = nullptr;
        size--;
        return;
    }
    dNode<T>* elementToBeRem = first;
    first = first->next;
    first->previous = nullptr;
    delete elementToBeRem;
    size--;
}
template<class T>
void DoublyLinkedList<T>::removeAtTail() {
    if (isEmpty()) {
        throw std::out_of_range("Since the list is empty, there are no elements that can be removed");
    }
    else if (size == 1) {
        first = nullptr;
        delete last;
        last = nullptr;
        size--;
        return;
    }
    dNode<T>* elementToBeRem = last;
    last = last->previous;
    last->next = nullptr;
    delete elementToBeRem;
    size--;
}
template<class T>
void DoublyLinkedList<T>::removeAt(int index) {
    if (isEmpty()) {
        cerr << "Since the list is empty, there are no elements that can be removed\n";
        return;
    }
    else if (index >= size || index < 0) {
        cerr << "Error: Index out of bounds\n";
        return;
    }
    else if (size == 1 || index == 0) {
        removeAtHead();
        return;
    }
    else if (index == size - 1) {
        removeAtTail();
        return;
    }
    dNode<T>* current = first, * elementToBeRem;
    int counter = 0;
    while (counter < index - 1) {
        current = current->next;
        counter++;
    }
    elementToBeRem = current->next;
    current->next = current->next->next;
    current->next->previous = current;
    elementToBeRem->next = elementToBeRem->previous = nullptr;
    delete elementToBeRem;
    size--;
}

template<class T>
T DoublyLinkedList<T>::retrieveAt(int index) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    else if (index == size - 1)
        return last->value;
    int counter = 0;
    dNode<T>* current = first;
    while (counter < index) {
        current = current->next;
        counter++;
    }
    return current->value;
}
template<class T>
bool DoublyLinkedList<T>::isItemAtEqual(T element, int index) {
    return (element == retrieveAt(index));
}
template<class T>
void DoublyLinkedList<T>::replaceAt(T newElement, int index) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    dNode<T>* current = first;
    int counter = 0;
    while (counter < index) {
        current = current->next;
        counter++;
    }
    current->value = newElement;
}
template<class T>
bool DoublyLinkedList<T>::isExist(T element) {
    dNode<T>* current = first;
    while (current != nullptr) {
        if (current->value == element)
            return true;
        current = current->next;
    }
    return false;
}
template<class T>
void DoublyLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx == secondItemIdx) {
        return;
    }
    if (firstItemIdx > secondItemIdx) {
        swap(secondItemIdx, firstItemIdx);
        return;
    }
    if (firstItemIdx < 0 || secondItemIdx >= size) {
        cout << "out of index" << endl;
        return;
    }


    dNode<T>* Cur = first;
    dNode<T>* Node1 = new dNode<T>(0);
    dNode<T>* Node2 = new dNode<T>(0);


    for (int i = 0; i < size; i++) {
        if (i == firstItemIdx) {
            Node1 = Cur;
        }
        if (i == secondItemIdx) {
            Node2 = Cur;
        }
        Cur = Cur->next;
    }


    if (firstItemIdx != 0) {
        Node1->previous->next = Node2;
    }
    if (secondItemIdx != size - 1) {
        Node2->next->previous = Node1;
    }
    if (secondItemIdx != firstItemIdx + 1) {
        Node2->previous->next = Node1;
        Node1->next->previous = Node2;


        dNode<T>* temp = Node2->previous;
        Node2->previous = Node1->previous;
        Node1->previous = temp;

        temp = Node2->next;
        Node2->next = Node1->next;
        Node1->next = temp;
    }
    else {

        dNode<T>* temp = Node1->previous;
        Node1->previous = Node2;
        Node2->previous = temp;

        temp = Node2->next;
        Node1->next = temp;
        Node2->next = Node1;

    }

    if (firstItemIdx == 0) {
        first = Node2;
    }
    if (secondItemIdx == size - 1) {
        last = Node1;
    }

}
template<class T>
void DoublyLinkedList<T>::reverse() {
    if (size < 2)return;
    for (int i = 0; i < (size / 2); i++) {
        swap(0 + i, size - i - 1);
    }
}

template<class T>
void DoublyLinkedList<T>::clear() {
    last = nullptr; size = 0;
    dNode<T>* current = first;
    while (current != nullptr) {
        first = current->next;
        current->next = nullptr;
        if (first != nullptr) first->previous = nullptr;
        delete current;
        current = first;
    }
}

template<class T>
void DoublyLinkedList<T>::forwardTraversal() {
    dNode<T>* current = first;
    while (current != nullptr) {
        cout << current->value << ' ';
        current = current->next;
    }cout << "\n";
}
template<class T>
void DoublyLinkedList<T>::backwardTraversal() {
    dNode<T>* current = last;
    while (current != nullptr) {
        cout << current->value << ' ';
        current = current->previous;
    }cout << "\n";
}









