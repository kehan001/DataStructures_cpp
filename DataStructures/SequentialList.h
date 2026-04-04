#ifndef SEQUENTIALLIST_H
#define SEQUENTIALLIST_H

class SequentialList {
private:
    int* data;
    int size;
    int capacity;

public:
    SequentialList(int cap = 10);
    SequentialList(const SequentialList& other);
    ~SequentialList();
    bool appendVal(int value);
    bool insertVal(int value, int pos);
    bool deletePos(int pos);
    int findVal(int value);
    void expand();
    SequentialList& operator=(const SequentialList& other);

};

#endif