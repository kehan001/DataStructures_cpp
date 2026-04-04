#include "Stack.h"

Stack::Stack(int cap) {
	capacity = cap;
	size = 0;
	stack = new int[capacity];
}

Stack::Stack(const Stack& other) {
	capacity = other.capacity;
	size = other.size;
	stack = new int[capacity];
	for (int i = 0; i < size; i++) {
		stack[i] = other.stack[i];
	}
}

Stack::~Stack() {
	delete[] stack;
}

bool Stack::push(int data) {
	if (size == capacity) {
		extend();
	}

	stack[size++] = data;
	return true;
}

bool Stack::pop() {
	if (size == 0) {
		return false;
	}
	size--;
	return true;
}

int Stack::getSize() const{
	return size;
}

void Stack::extend() {
	int newCap = capacity * 2;
	int* temp = new int[newCap];

	for (int i = 0; i < size; i++) {
		temp[i] = stack[i];
	}

	delete[] stack;
	stack = temp;
	capacity = newCap;
}

int Stack::top() const{
	return stack[size - 1];
}

bool Stack::isEmpty() const{
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Stack::clear() {
	size = 0;
	return true;
}

Stack& Stack::operator=(const Stack& other) {
	if (this == &other) {
		return *this;
	}

	delete[] stack;

	capacity = other.capacity;
	size = other.size;
	stack = new int[capacity];
	for (int i = 0; i < size; i++) {
		stack[i] = other.stack[i];
	}

	return *this;
}