#pragma once
#include <initializer_list>
#include <exception>

class IntLinkedList {
	struct Node {
		int data{};
		Node* next{ nullptr };

		Node(int);
	};

	Node* head;
	
	void DeleteSub(Node*);
	void ReverseSub(Node*);
	void Swap(int, int);
public:
	int size{ 0 };
	IntLinkedList(); //default empty list
	IntLinkedList(std::initializer_list<int>); // initialiser list constructor

	void Insert(int, int);
	void Delete(int);
	int operator[](int);

	void BubbleSort();
	void Reverse();

	~IntLinkedList();
};