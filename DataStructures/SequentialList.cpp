#include "SequentialList.h"

//Constructors
SequentialList::SequentialList(int cap) {
    capacity = cap;
    size = 0;
    data = new int[capacity];
}

SequentialList::SequentialList(const SequentialList& other) {
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

//Destructor
SequentialList::~SequentialList() {
    delete[] data;
}

//Append
bool SequentialList::appendVal(int value) {
    if (size == capacity) {
        expand();
    }

    data[size] = value;
    size++;
    return true;
}

//Insert
bool SequentialList::insertVal(int value, int pos) {
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
bool SequentialList::deletePos(int pos) {
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
int SequentialList::findVal(int value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

//Expand
void SequentialList::expand() {
    int newCapacity = capacity * 2;
    int* newData = new int[newCapacity];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

//Overload Operator =
SequentialList& SequentialList::operator=(const SequentialList& other) {
    if (this == &other) {
        return *this;
    }
    size = other.size;
    capacity = other.capacity;
    int* newData = new int[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = other.data[i];
    }
    delete[] data;
    data = newData;
    return *this;
}
