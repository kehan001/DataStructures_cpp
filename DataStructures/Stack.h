#pragma once

class Stack {
private:
	int* stack;
	int size;
	int capacity;
	void extend();
public:
	Stack(int cap = 10);
	Stack(const Stack& other);
	~Stack();
	bool push(int data);
	bool pop();
	int getSize() const;
	int top() const;
	bool isEmpty() const;
	bool clear();
	Stack& operator=(const Stack& other);
};