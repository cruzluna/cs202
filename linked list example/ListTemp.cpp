#include "ListTemp.h"

template <class T>
List<T>::List()
{
	head = NULL;
}

template <class T>
void List<T>::Insert(T new_data)
{
	//Make a new Node
	Node<T>* newNode(new_data);

	//If our list is empty
	if (head == NULL)
		head = newNode;
	else
	{
		Node<T>* current = head;
		while (current->next != NULL)
			current = current->next;

		current->next = newNode;
	}
}

template <class T>
Node<T>* List<T>::Lookup(T object)
{

}
template <class T>
void List<T>::Deletion(T object)
{

}