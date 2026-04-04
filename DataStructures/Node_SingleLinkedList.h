#ifndef NODE_SINGLELINKEDLIST
#define NODE_SINGLELINKEDLIST

class Node_SingleLinkedList {
private:
	int value;
	Node_SingleLinkedList* next;
public:
	Node_SingleLinkedList(int data, Node_SingleLinkedList* nextNode = NULL);
};

#endif