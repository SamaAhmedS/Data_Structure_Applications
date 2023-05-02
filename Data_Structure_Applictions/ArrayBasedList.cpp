#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
class ArrayBasedList {
    T* lst;
    int Size = 0, capacity;
    int resize();        // Relocate to bigger space
public:
    ArrayBasedList(int cap = 5);
    ArrayBasedList(const ArrayBasedList& other);//Initialize with a copy
    ArrayBasedList& operator=(const ArrayBasedList<T>& other);
    ArrayBasedList& operator=(ArrayBasedList<T>&& other);// Move assignment
    void  insert(const T& element);// Add item to end of lst & Increase capacity if needed
    void insertAt(const T& element, const int& index);
    T retrieveAt(const int& index);
    void removeAt(const int& index);
    void replaceAt(const T& newElement, const int& index);
    bool isItemAtEqual(const T& element, const int& index) {
        return(element == retrieveAt(index));
    }
    int listSize() { return Size; }
    int maxListSize() { return capacity; }
    bool isEmpty() { return(Size == 0); }
    bool isFull() { return (Size == capacity); }
    void print();
    void clear();

    ~ArrayBasedList() { delete[] lst; }			// Delete allocated memory
};

template<class T>
int ArrayBasedList<T>::resize() {
    capacity = capacity * 2;
    T* arr = new T[capacity];
    for (int i = 0; i < Size + 1; ++i) {
        arr[i] = lst[i];
    }
    delete[] lst;
    lst = arr;
    arr = nullptr;
    return capacity;
}
template<class T>ArrayBasedList<T>::ArrayBasedList(int cap) {
    capacity = cap;
    lst = new T[cap];
}

template<class T> ArrayBasedList<T>::ArrayBasedList(const ArrayBasedList& other) {
    delete lst;
    Size = other.Size;
    capacity = other.capacity;
    lst = new T[capacity];
    for (int i = 0; i < Size; i++) {
        lst[i] = other.lst[i];
    }
}
template<class T>ArrayBasedList<T>& ArrayBasedList<T>:: operator=(const ArrayBasedList<T>& other) {
    if (this != &other) {
        delete lst;
        Size = other.Size;
        capacity = other.capacity;
        lst = new T[capacity];
        for (int i = 0; i < Size; i++) {
            lst[i] = other.lst[i];
        }
    }
    return *this;
}
template<class T>ArrayBasedList<T>& ArrayBasedList<T>:: operator=(ArrayBasedList<T>&& other) {
    delete lst;
    lst = other.lst;
    Size = other.Size;
    capacity = other.capacity;
    other.lst = nullptr;
    return *this;
}

template<class T>
void ArrayBasedList<T>::insertAt(const T& element, const int& index) {//index is zero based
    if (index > Size || index < 0)
        throw std::out_of_range("Index out of range");
    else if (Size > capacity - 1)
        this->resize();

    for (int i = Size; i > index; i--)
        lst[i] = std::move(lst[i - 1]);

    // Insert new element//we do this as the data in index is moved so we need to create it
    new (&lst[index]) T(element);
    ++Size;
}
template<class T>
void ArrayBasedList<T>::insert(const T& element) {
    if (Size > capacity - 1) {
        this->resize();
        lst[Size++] = element;
    }
    else {
        lst[Size++] = element;
    }

}
template<class T>
T ArrayBasedList<T>::retrieveAt(const int& index) {//index is zero based
    if (index >= Size || index < 0)
        throw std::out_of_range("Index out of range");
    return lst[index];
}
template<class T>
void ArrayBasedList<T>::removeAt(const int& index) {//index is zero based
    if (index >= Size || index < 0)
        throw std::out_of_range("Index out of range");
    --Size;
    for (int i = index; i < Size; i++)
        lst[i] = std::move(lst[i + 1]);

}
template<class T>
void ArrayBasedList<T>::replaceAt(const T& newElement, const int& index) {
    if (index >= Size || index < 0)
        throw std::out_of_range("Index out of range");

    lst[index] = newElement;
}
template<class T>
void ArrayBasedList<T>::clear() {
    for (size_t i = 0; i < Size; ++i)
        lst[i].~T();

    Size = 0;
}
template<class T>
void ArrayBasedList<T>::print() {
    if (!isEmpty()) {
        cout << "[";
        for (int i = 0; i < Size; i++) {
            cout << lst[i] << " ";
        }cout << "]\n";
    }
}















