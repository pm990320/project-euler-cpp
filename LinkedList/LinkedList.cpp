#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> elements)
{
	head->data = elements.begin()[0];
}

template<typename T>
T LinkedList<T>::operator[](int index) {
	unique_ptr< Node<T> > curr = head;

	for (int i = 0; i != index; i++) {
		curr = curr->next;
	}

	return curr->data;
}
