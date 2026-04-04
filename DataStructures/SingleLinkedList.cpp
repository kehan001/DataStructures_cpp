#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

//Constructor-Destructor
SingleLinkedList::SingleLinkedList() {
    head = new Node{0};
    size = 0;
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList& other) {
    head = new Node{ 0 };
    size = other.size;
    Node* curr = head;
    Node* currOther = other.head->next;
    while (currOther) {
        Node* newNode = new Node(currOther->data);
        curr->next = newNode;
        currOther = currOther->next;
        curr = curr->next;
    }
}

SingleLinkedList::~SingleLinkedList() {
    Node* curr = head;
    while (curr) {
        Node* temp = curr->next;
        delete curr;
        curr = temp;
    }
}

//-----------------------------------------------------------
void SingleLinkedList::append(int value) {
    Node* newNode = new Node{value};
    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = newNode;
    size++;
}


int SingleLinkedList::find(int value) const{
    Node* curr = head->next;
    int index = 0;
    while (curr) {
        if (curr->data == value) {
            return index;
        }
        curr = curr->next;
        index++;
    }
    return -1;
}

int SingleLinkedList::getSize() const{
    return size;
}

bool SingleLinkedList::remove(int pos) {
    if (pos < 0 || pos >= size) {
        return false;
    }
    Node* prev = head;
    
    for (int i = 0; i < pos; i++) {
        prev = prev->next;
    }

    Node* delNode = prev->next;
    prev->next = delNode->next;
    delete delNode;
    size--;

    return true;
}

bool SingleLinkedList::insert(int val, int pos) {
    if (pos < 0 || pos > size) {
        return false;
    }
    Node* newNode = new Node{ val };

    Node* prev = head;

    for (int i = 0; i < pos; i++) {
        prev = prev->next;
    }

    newNode->next = prev->next;
    prev->next = newNode;
    size++;

    return true;
}

//[start, end)
bool SingleLinkedList::reverse(int start, int end) {
    if (end == -1) {
        end = size;
    }
    if (start < 0 || start >= size) return false;
    if (end < 0 || end > size) return false;
    if (end <= start) return false;


    Node* prev = head;
    for (int i = 0; i < start; i++) {
        prev = prev->next;
    }
    Node* last = prev->next;

    int count = start;
    Node* first = nullptr;
    Node* second = prev->next;
    while (second && count < end) {
        Node* third = second->next;
        second->next = first;
        first = second;
        second = third;
        count++;
    }

    prev->next = first;
    last->next = second;

    return true;
}

void SingleLinkedList::print() const {
    Node* curr = head->next;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

//利用值传递直接拷贝一份，然后swap交换，得到现成深拷贝链表。方法结束后这个other副本也会自动被析构掉
SingleLinkedList& SingleLinkedList::operator=(SingleLinkedList other) {
    swap(head, other.head);
    swap(size, other.size);
    return *this;
}







