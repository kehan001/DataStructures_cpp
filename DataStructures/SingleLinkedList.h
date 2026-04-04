#pragma once

class SingleLinkedList {
private:
	struct Node{
		int data;
		Node* next = nullptr;
	};

	Node* head;
	int size;

public:
	SingleLinkedList();
	SingleLinkedList(const SingleLinkedList& other);
	~SingleLinkedList();
	void append(int value);
	int find(int value) const;
	bool remove(int pos);
	int getSize() const;
	bool insert(int val, int pos);
	bool reverse(int start = 0, int end = -1);
	void print() const;
	SingleLinkedList& operator=(SingleLinkedList other);
};
