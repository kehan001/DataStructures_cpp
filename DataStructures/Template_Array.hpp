#pragma once

template <class T>
class SequentialList {
private:
    T* data;
    int size;
    int capacity;

public:
    SequentialList(int cap = 10);
    SequentialList(const SequentialList& other);
    ~SequentialList();
    bool appendVal(T value);
    bool insertVal(T value, int pos);
    bool deletePos(int pos);
    int findVal(T value);
    void expand();
    SequentialList& operator=(const SequentialList& other);

};



//Constructors
template <class T>
SequentialList<T>::SequentialList(int cap) {
    capacity = cap;
    size = 0;
    data = new T[capacity];
}

template <class T>
SequentialList<T>::SequentialList(const SequentialList<T>& other) {
    capacity = other.capacity;
    size = other.size;
    data = new T[capacity];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

//Destructor
template <class T>
SequentialList<T>::~SequentialList() {
    delete[] data;
}

//Append
template <class T>
bool SequentialList<T>::appendVal(T value) {
    if (size == capacity) {
        expand();
    }

    data[size] = value;
    size++;
    return true;
}

//Insert
template <class T>
bool SequentialList<T>::insertVal(T value, int pos) {
    if (pos < 0 || pos > size) {
        return false;
    }
    if (size == capacity) {
        expand();
    }
    for (int i = size; i > pos; i--) {
        data[i] = data[i - 1];
    }
    data[pos] = value;
    size++;
    return true;
}

//Delete
template <class T>
bool SequentialList<T>::deletePos(int pos) {
    if (pos >= size || pos < 0) {
        return false;
    }

    for (int i = pos; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    return true;
}

//Find
template <class T>
int SequentialList<T>::findVal(T value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

//Expand
template <class T>
void SequentialList<T>::expand() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

//Overload Operator =
template <class T>
SequentialList<T>& SequentialList<T>::operator=(const SequentialList<T>& other) {
    if (this == &other) {
        return *this;
    }

    T* newData = new T[other.capacity];
    for (int i = 0; i < other.size; i++) {
        newData[i] = other.data[i];
    }
    delete[] data;
    data = newData;

    size = other.size;
    capacity = other.capacity;
    return *this;
}