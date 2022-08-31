#include<iostream>
#include "List.h"

using namespace std;

//Tail Insert
//Normal insert. Go to the end of the list and put the node there
void List::Insert(int new_data)
{
	//Make a new Node
	Node* newNode = new Node(new_data);

	//If our list is empty, put the node at the head
	if (head == nullptr)
		head = newNode;
	else //Else go to the end and put the new node there
	{
		//This is our basically traversal code for most functions

		Node* current = head; //Start at the head
		//transverse Linked List:
		while (current->next != nullptr) //While we're not at the end
			current = current->next; //Go to the next node, allows the transversal

		current->next = newNode; //Once we're at the end, insert the new node
	}
}

//Looks up if the given object is in the list and returns its Node if found.
//On error, returns nullptr
Node* List::Lookup(int object)
{
	Node* current = head; //Start at the head
	while (current != nullptr)
	{
		//If we find the data, then return it
		if (object == current->data)
			return current;//returns address

		current = current->next;//move to next node
	}
		
	return nullptr; //If we found nothing, return nullptr
}

//Deletes the object if we find it in the linked list
void List::Deletion(int object)
{
	//Check if we are deleting the head
	if (head->data == object)//Head is the object we are deleting
	{
		Node* oldHead = head; //Don't lose the old head before we delete it
		head = head->next; //Update the head
		delete oldHead; //Deallocate the old head
	}
	else
	{
		//Need to keep track of previous node to make pointer go around
		//Could also potentially work using ->next->next, but would require 
		//extra checks.
		Node* previousNode = head, * current = head->next;

		//While we're not at the end
		while (current != nullptr)
		{
			if (current->data == object) //If we found the match
			{
				previousNode->next = current->next; //Make the pointer go around
				delete current; //Delete the node we found
				return;
			}

			//transverse: (moving in the linked list)
			//Make the previous and current go to the next node
			previousNode = current;
			current = current->next;	
		}
	}
}

//Prints all of the items in the list
void List::print()
{
	if (head == nullptr) //If the list is empty, don't print
		return;

	Node* current = head; //Start at the head
	while (current->next != nullptr)//should be current !=nullptr I think
	{
		cout << current->data << ", ";
		current = current->next;
	}

	cout << current->data << endl;
}

//Counts how many items are in the linked list
int List::getSize()
{
	int count = 0;

	Node* current = head;
	while (current != nullptr)
	{
		current = current->next;
		count++;
	}
		
	return count;
}

//Fairly optimized version of BubbleSort for a linked list
void List::sort()
{
	Node* current = head, *prev;

	int i, j;
	int count = getSize();
	bool isSorted = false;

	//Loop for how many things have for sure been sorted (i many things)
	for (i = 0; i < count && !isSorted; i++)
	{
		isSorted = true;
		current = head;
		prev = nullptr;
		//Go through the list
		for (j = 0; j < count - i - 1; j++)
		{
			//If two elements are out of order
			if (current->data > current->next->data)
			{
				//Swap by updating pointers
				//Swapright is the right element being swapped, current is the left element
				Node* swapRight = current->next; 
				current->next = swapRight->next;//equivalent to current->next->next
				swapRight->next = current;

				if (prev == nullptr) //If we are swapping the head
					head = swapRight;
				else //Else do a normal swap
					prev->next = swapRight;

				//Since we swapped, current moved right. So we need to fix this
				current = swapRight; 
				isSorted = false;
			}

			//Move prev and current right one Node each
			prev = current;
			current = current->next;
		}
	}
	
}

//Recursively inserts a new_data. Inserts into the list if current is null (i.e.
//points to an empty list), otherwise inserts the data in the list to the right 
//of the current node
void List::RecursiveInsert(int new_data, Node* current)
{
	if (current == NULL) //If we've reached the end/ our list is empty
	{
		if(head == NULL) //If the whole list is empty, set the head
			head = new Node(new_data);
		else //Else this is just the normal end (shouldn't trigger?)
			current = new Node(new_data);
	}
	else if (current->next == NULL) //If we're at the end
		current->next = new Node(new_data);
	else //Otherwise, try inserting to the list to the right
		RecursiveInsert(new_data, current->next);
}

//Recursively traverses and checks for the given object
Node* List::RecursiveLookup(int object, Node* current)
{
	//If we found a match 
	if (current->data == object)
		return current;
	else if (current == nullptr) //If we reached the end
		return nullptr;
	else //Else, try the list to the right
		return RecursiveLookup(object, current->next);
}

//Recursively tries to delete a node containing the given object
void List::RecursiveDeletion(int object, Node* current, Node* prev)
{
	if (current == nullptr) //If we reached the end
		return;
	else if (current->data == object) //If we found a match 
	{
		if (current == head)//If we are deleting the head, update the head
			head = current->next;
		else //Else make the pointer go around the Node being deleted
			prev->next = current->next;

		delete current; //Deallocate the Node
	}
	else //If no match, try checking the list to the right
		return RecursiveDeletion(object, current->next, current);
}

//Inserts the object in a sorted order to the list
void List::insertInOrder(int object)
{
	Node* newNode = new Node(object);

	if (head == nullptr) //If the list is empty
	{
		head = newNode;
		return;
	}
	if (head->data > object) //If the object should go at the head
	{
		newNode->next = head;
		head = newNode;
		return;
	}

	Node* current = head->next, * previous = head;

	//Else traverse until we get to the right spot
	while (current != nullptr)
	{
		//If this is the node our new one should go before
		if (current->data > object)
		{
			previous->next = newNode; //Make the previous point to our new Node
			newNode->next = current; //Make our new Node point to the one to its right
			return;
		}

		//Update previous and current to go right
		previous = current;
		current = current->next;
	}

	//If we got to the end without inserting, we should just insert the newNode
	//but we don't have to set its next
	previous->next = newNode;
}