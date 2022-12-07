/*
* Description: linked list assignment.
* Input: none.
* Output: ordered and unordered linked lists in terminal.
*/

#include <iostream>
#include "linkedListType.h"


using namespace std;
//inherits from linkedList class

template<class myType>
class orderedLinkedList: public linkedListType<myType>
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
bool orderedLinkedList<myType>::search(const myType& value) const
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
void orderedLinkedList<myType>::insert(const myType& value)
{
    //nodeType<myType>* temp = first;
    //Special Case for the head end
    if(first == nullptr || first->info >= value)
    {
        /* head is null or the head data is greater
           than or equal to the passed value*/
        
        //Allocate new node
        nodeType<myType>* temp = new nodeType<myType>();
        temp->info = value; //setting data
        temp->link = first;//point to the head

        
        if (first == nullptr) { last = temp; }
        first = temp;//set the new head to the temp mode
        count++;
        return;
    }else{
        nodeType<myType> *current = first; //pointer at head
        nodeType<myType>* temp = new nodeType<myType>();
        temp->info = value; //setting data
        //temp->link = first;

        while(current->link != nullptr && current->link->info < temp->info)
        {
            current = current->link;
            
        }
        //need to check for the end
        if (current->link == nullptr) { last = temp; }
        temp->link = current->link;//set the temp to the current pointer
        current->link = temp;
        
        count++;
    }
}

template<class myType>
void orderedLinkedList<myType>::insertLast(const myType& value){insert(value);}

template<class myType>
void orderedLinkedList<myType>::deleteNode(const myType& value)
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
