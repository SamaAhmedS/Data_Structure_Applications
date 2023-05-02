#ifndef SINGLE_LINKED_lIST_H
#define SINGLE_LINKED_lIST_H
#include"Single Linked List.h"
#endif 
template<class T>
singleLinkedList<T>& singleLinkedList<T>:: operator=(singleLinkedList<T> other) {
    if (this != &other) {
        clear(); 
        for (int i = 0; i < other.linkedListSize(); i++) {
            this->insertAtTail(other.retrieveAt(i));
        }
    }
    return *this;
}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void singleLinkedList<T>::insertAtHead(T element) {
    node<T>* cur = first;
    first = new node<T>(element);
    first->next = cur;
    if (size == 0) {
        last = first;
    }
    size++;
}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void singleLinkedList<T>::insertAtTail(T element) {
    size++;
    if (last == nullptr) {
        last = new node<T>(element);
        first = last;
        return;
    }
    last->next = new node<T>(element);
    last = last->next;

}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void singleLinkedList<T>::insertAt(T element, int index) {//assume index is zero based
    if (index > size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    else {
        if (index == 0) {
            insertAtHead(element);
            return;
        }
        else if (index == size) {
            insertAtTail(element);
            return;
        }
        size++;
        int count = 0;
        node<T>* cur = first;
        while (count < index - 1) {
            cur = cur->next;
            count++;
        }
        node<T>* insertedEle = new node<T>(element);
        insertedEle->next = cur->next;
        cur->next = insertedEle;

    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void singleLinkedList<T>::removeAtHead() {
    if (isEmpty()) {
        cerr << "Since the list is empty, there are no elements that can be removed\n";
        return;
    }
    else if (first != nullptr) {
        node<T>* elementToBeRemoved = first;
        first = first->next;
        elementToBeRemoved->next = nullptr;
        delete elementToBeRemoved;
        if (size == 1)last = nullptr;
        size--;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void singleLinkedList<T>::removeAtTail() {
    if (isEmpty()) {
        cerr << "Since the list is empty, there are no elements that can be removed\n";
        return;
    }
    else if (last != nullptr) {
        node<T>* elementToBeRemoved = last;
        int counter = 1;
        last = first;
        while (counter < size - 1) {
            last = last->next;
            counter++;
        }
        if (last != nullptr)last->next = nullptr;
        delete elementToBeRemoved;
        if (size == 1)first = nullptr;
        size--;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void singleLinkedList<T>::removeAt(int index) {//assume index zero based
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
    node<T>* current = first, * elementToBeRemoved;
    int counter = 0;
    while (counter < index - 1) {
        current = current->next;
        counter++;
    }
    elementToBeRemoved = current->next;
    current->next = current->next->next;
    delete elementToBeRemoved;
    size--;
}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T singleLinkedList<T>::retrieveAt(int index) {//assume index is zero base
    if (index >= size || index < 0) {
        cout << "size = " << size << endl;
        cout << index << endl;
        throw std::out_of_range("Index out of range");
    }
    else if (index == size - 1 && last != nullptr) {
        return last->value;
    }
    node<T>* current = first;
    int counter = 0;
    while (counter < index) {
        current = current->next;
        counter++;
    }
    return current->value;
}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool singleLinkedList<T>::isExist(T element) {
    node<T>* current = first;
    while (current != nullptr) {
        if (current->value == element)
            return true;
        current = current->next;
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool singleLinkedList<T>::isItemAtEqual(T element, int index) {// assume index is zero based
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    int counter = 0;
    node<T>* current = first;
    while (counter < index) {
        current = current->next;
        counter++;
    }
    if (current != nullptr && current->value == element) {
        return true;
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void singleLinkedList<T>::swap(int idx1, int idx2) {
    if (idx1 == idx2) {
        return;
    }
    if (idx1 > idx2) {
        swap(idx2, idx1);
        return;
    }
    if (idx1 < 0 || idx2 >= size) {
        cout << "out of index" << endl;
        return;
    }

    node<T>* Cur = first;
    node<T>* Node1 = new node<T>;
    node<T>* Node2 = new node<T>;
    node<T>* PrevNode1 = new node<T>;
    node<T>* PrevNode2 = new node<T>;

    for (int i = 0; i < size; i++) {
        if (i == idx1) {
            Node1 = Cur;
        }
        if (i == idx1 - 1) {
            PrevNode1 = Cur;
        }
        if (i == idx2) {
            Node2 = Cur;
        }
        if (i == idx2 - 1) {
            PrevNode2 = Cur;
        }
        Cur = Cur->next;
    }




    if (idx1 != 0) {
        PrevNode1->next = Node2;
    }
    if (idx2 != idx1 + 1) {
        PrevNode2->next = Node1;


        node<T>* temp = Node2->next;
        Node2->next = Node1->next;
        Node1->next = temp;

    }
    else {

        node<T>* temp = Node2->next;
        Node1->next = temp;
        Node2->next = Node1;
    }




    if (idx1 == 0) {
        first = Node2;
    }
    if (idx2 == size - 1) {
        last = Node1;
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void singleLinkedList<T>::replaceAt(T newElement, int index) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    node<T>* current = first;
    int counter = 0;
    while (counter < index && current->next != nullptr) {
        current = current->next; counter++;
    }
    current->value = newElement;
}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void singleLinkedList<T>::clear() {
    node<T>* current = first;

    while (first != nullptr) {
        current = first;
        first = first->next;
        delete current;
    }
    first = nullptr; last = nullptr; size = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void singleLinkedList<T>::print() {
    node<T>* cur = first;
    int counter = size; cout << "[";
    while (counter > 0 && cur != nullptr) {
        cout << cur->value << ((counter == 1) ? "" : ", ");
        cur = cur->next;
        counter--;
    }cout << "]\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------
/*
 a linked list containing a sequence of integers separated by 0s.
 The value presented at the linked list's beginning and end is 0.
 Merge all nodes between any two consecutive 0s into a single node whose value is the
     total of all the merged nodes.
There are no two consecutive nodes with value == 0.
 There should be no 0s in the new list.
//If Input list is {0,1,2,3,0,9,0,5,6,0}
//return list will be {6,9,11}
*/
template<class T>
singleLinkedList<T> CombineNodesBetZeros(singleLinkedList<T> l) {
    bool fstZ = 0, secZ = 0; int sum = 0, count = 1;
    if (l.linkedListSize() < 3) {
        cerr << "nodes are not between zeros\n";
        exit(1);
    }
    while (l.linkedListSize() - count) {
        if (l.retrieveAt(0) == 0) {
            l.removeAtHead();
        }
        else {
            cerr << "nodes are not between zeros\n";
            exit(1);
        }
        while (l.retrieveAt(0) != 0)
        {
            sum += l.retrieveAt(0);
            l.removeAtHead();
        }
        l.insertAtTail(sum);
        count++; sum = 0;
    }
    l.removeAtHead();
    singleLinkedList<T> ans = l; ans.print();
    return ans;
}
//--------------------------------------------------------------------------------------------------------------

// merge K Linked List
template <typename T>
singleLinkedList<T> Merge(vector<node<T>*> k) {
    //This function takes vectore of pointers. Each pointer points to the first element in his linked list 
    singleLinkedList<T> new_list;
    for (int i = 0; i < k.size(); i++) {
        node<T>* cur = k[i]; 
        while (cur != nullptr) {
            if (!new_list.isEmpty() && cur->value <= new_list.retrieveAt(0)) {
                new_list.insertAtHead(cur->value);
            }
            else if (!new_list.isEmpty() && cur->value >= new_list.retrieveAt(new_list.linkedListSize() - 1)) {
                new_list.insertAtTail(cur->value);
            }
            else {
                bool inserted = 0; int sz = new_list.linkedListSize();
                for (int j = 1; j < sz; j++) {
                    if (new_list.retrieveAt(j) > cur->value) {
                        new_list.insertAt(cur->value, j);
                        inserted = 1; break;
                    }
                }
                if (!inserted) {
                    new_list.insertAtTail(cur->value);
                }
            }

            cur = cur->next;
        }

    }
    new_list.print();
    return new_list;
};




