/*
* Description: linked list assignment.
* Input: none.
* Output: ordered and unordered linked lists in terminal.
*/
#include <iostream>
#include "linkedListType.h"

using namespace std;
//inherits from linkedList class

//Derived Class
template<class myType>
class unorderedLinkedList: public linkedListType<myType>
{
protected:
    using linkedListType<myType>::count;
    using linkedListType<myType>::first;
    using linkedListType<myType>::last;

public:
    bool search(const myType&) const;
    void insert(const myType&);
    void insertLast(const myType&);
    void deleteNode(const myType&);
    
};

template<class myType>
bool unorderedLinkedList<myType>::search(const myType& value) const
{
    nodeType<myType> *current = first;
    while(current != nullptr)
    {
        if(current->info == value)
            return true;
        
        current = current->link;//transverse current pointer
    }

    return false;
}

template<class myType>
void unorderedLinkedList<myType>::insert(const myType& value)
{
    //insert to the front 

    //Allocate a new node
    nodeType<myType>* temp = new nodeType<myType>();
    temp->info = value; //setting data 

    temp->link = first;//point to the head
    first = temp;//set the new head to the temp node

    if(last == nullptr)
    {
        last = first;
    }

    count++; //increment count

}

template<class myType>
void unorderedLinkedList<myType>::insertLast(const myType& value)
{
    //allocate a new node
    nodeType<myType>* temp = new nodeType<myType>();

    temp->info = value;//set the data
    temp->link = nullptr;//becomes the tail

    if(first == nullptr)//if empty, node is head
    {
        first = temp;
        last = temp;
        count++;
    }else{
        nodeType<myType>* current = first;//pointer at head
        while(current->link != nullptr)//stop one before end
        {
            current = current->link;//transverse
        }
        //last->link = temp
        //last = temp;
        // 
        //once we reach the end
        last = temp;
        current->link = temp;//changing the last node
        count++; //increment count
    }

}

template<class myType>
void unorderedLinkedList<myType>::deleteNode(const myType& value)
{
    if(first == nullptr)//empty list
    {
        cout << "Cannot delete from an empty list." << endl;
        return;
    }else if(first->info == value)//deleting the head
    {
        nodeType<myType> *oldHead = first;
        first = first->link; //update the head
        delete oldHead;//deallocate the old head
    }else{
        nodeType<myType>* previousNode = first, *current = first->link;

        while(current != nullptr)
        {
            if(current->info == value)
            {
                if (current == last)
                {
                    last = previousNode;
                }

                previousNode->link = current->link; //wrap around 
                delete current; //delete node found 
                count--;//decrement count
                
                return;
            }
            //move pointers
            previousNode = current;
            current = current->link;
        }
        //once we reach the end
        cout << "The item to be deleted is not in the list." << endl;

    }
}
