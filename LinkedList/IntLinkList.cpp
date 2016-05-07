// LinkedList Class Implementation
#include "IntLinkList.h"

IntLinkedList::Node::Node(int dat) {
	data = dat;
}


IntLinkedList::IntLinkedList() { 
	IntLinkedList::head = nullptr;
}


IntLinkedList::IntLinkedList(std::initializer_list<int> elements) {
	size = elements.size();
	head = new Node(elements.begin()[0]);

	Node* prev = head;

	for (int i = 1; i < elements.size(); i++) {
		prev->next = new Node(elements.begin()[i]);
		prev = prev->next;
	}
}


int IntLinkedList::operator[](int index) {
	Node* curr = head;
	for (int i = 0; i != index; i++) {
		curr = curr->next;
	}

	return curr->data;
}


void IntLinkedList::Insert(int newData, int pos) {
	if (pos >= size) {
		throw std::exception{"Out of bounds!"};
	}

	if (pos == 0) {
		Node* temp = head;
		head = new Node(newData);
		head->next = temp;
	}
	else if (pos == size - 1) {
		Node* newNode = new Node(newData);
		Node* curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
	else {
		Node* newNode = new Node(newData);

		Node* beforeInserted = head;
		Node* afterInserted = nullptr;

		for (int i = 1; i < pos; i++) {
			beforeInserted = beforeInserted->next;
		}
		afterInserted = beforeInserted->next;

		beforeInserted->next = newNode;
		newNode->next = afterInserted;
	}
}

void IntLinkedList::Delete(int pos) {
	if (pos >= size) {
		throw std::exception{"Out of bounds!"};
	}
	
	if (pos == 0) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	else {
		Node* curr = head;
		for (int i = 0; i < pos - 1; i++) {
			curr = curr->next;
		}

		if (curr->next->next != nullptr) {
			delete curr->next;
			curr->next = curr->next->next;
		} else {
			delete curr->next;
			curr->next = nullptr;
		}
	}
}

void IntLinkedList::DeleteSub(Node* node) {
	if (node->next != nullptr) {
		DeleteSub(node->next);
	}
	delete node;
}

void IntLinkedList::Swap(int first, int second) {
	Node* firstNode = nullptr;
	Node* secondNode = nullptr;

	Node* curr = head;
	for (int i = 0; i < first; i++) {
		curr = curr->next;
	}
	firstNode = curr;
	curr = head;
	for (int i = 0; i < second; i++) {
		curr = curr->next;
	}
	secondNode = curr;

	int temp = firstNode->data;
	firstNode->data = secondNode->data;
	secondNode->data = temp;
}

void IntLinkedList::BubbleSort() {
	int highest = 0;
	int iofH = 0;
	Node* curr = head;

	for (int i = size-1; i >= 0; i--) {
		curr = head;
		for (int j = 0; j < i; j++) {
			if (curr->data > highest) {
				highest = curr->data;
				iofH = j;
			}
			curr = curr->next;
		}
		Swap(iofH, i);
	}
}


void IntLinkedList::ReverseSub(Node* node) {
	if (node->next != nullptr) {
		ReverseSub(node->next);
		Node* temp = node->next;
		temp->next = node;
		node->next = nullptr;
	}
	else {
		head = node;
	}
}


void IntLinkedList::Reverse(){
	ReverseSub(head);
}


IntLinkedList::~IntLinkedList() {
	DeleteSub(head);
}