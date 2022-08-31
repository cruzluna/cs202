/*
* Name: Cruz Luna, 2001582775, Assignment 9
* Description: linked list assignment.
* Input: none.
* Output: ordered and unordered linked lists in terminal.
*/

#ifndef LINKEDLISTYPE_H
#define LINKEDLISTYPE_H

#include <iostream>
using namespace std;

template <class myType>
struct nodeType
{
    myType info;//data
    nodeType<myType> *link;//pointer 
};

template <class myType> 
class linkedListType
{

protected:
    int count;
    nodeType<myType> *first; // head
    nodeType<myType> *last; //tail

public:
    linkedListType();//default constructor
    linkedListType(const linkedListType<myType>&); //copy constructor
    ~linkedListType(); // destructor
    
    void initializeList();
    bool isEmptyList() const; 
    void print() const;
    void reversePrint() const;
    int length() const;
    void destroyList();
    
    myType front() const;
    myType back() const;
    nodeType<myType>* firstPtr() const;

    //Abstract Functions
    virtual bool search(const myType&) const = 0;
    virtual void insert(const myType&) = 0;
    virtual void insertLast(const myType&) = 0;
    virtual void deleteNode(const myType&) = 0;

private:
    void copyList(const linkedListType&);
    void recursiveReversePrint(nodeType<myType> *) const;


};

//Function Definitions

//Default constructor
template<class myType>
linkedListType<myType>::linkedListType()
{
    //initialize to empty state
    first = nullptr;//head is null
    last = nullptr;//tail is null
    count = 0;

}

//copy constructor
template<class myType>
linkedListType<myType>::linkedListType(const linkedListType<myType>& rhs)
{
    first = nullptr;
    last = nullptr;
    count = rhs.length();

    if(!rhs.isEmptyList())//not empty
    {
       copyList(rhs);
    }
    
}

//destructor
template<class myType>
linkedListType<myType>::~linkedListType(){destroyList();}

template<class myType>
void linkedListType<myType>::initializeList()
{
    //empty state
    first = nullptr; //head
    last = nullptr; //tail
    count = 0;
    destroyList(); //all items deleted

}

template<class myType>
bool linkedListType<myType>:: isEmptyList() const
{   

    // if(first == nullptr)//head is pointing to nullptr
    //     return true;
    // else //not empty    
    //     return false;

    //check if empty
    //bool flag = (first == nullptr)? true: false; 
    //expression is already boolean, redundant

    return (first == nullptr);
}

template<class myType>
void linkedListType<myType>:: print() const
{
    if(first == nullptr)//empty list
        return; //exit
    
    nodeType<myType> *current = first; //set ptr to head
    while( current != nullptr)
    {
        cout << current->info << " ";
        current = current->link;//transverse- going thru data one by one
    }
    //alternate way
    /* 
    for(nodeType *current = first; current != nullptr; current->link)
    */
}

template<class myType>
void linkedListType<myType>::reversePrint() const
{
    //indirect recursion
    recursiveReversePrint(first);
}

template<class myType>
int linkedListType<myType>::length() const
{
  
    return count;
}

template<class myType>
void linkedListType<myType>::destroyList()
{
    if(first == nullptr)//empty list
        return;
    
    nodeType<myType> *temp; //temp pointer
    
    while(first != last)
    {
        temp = first->link;
        delete first;
        first = temp;
    }

    delete first;

    first = nullptr;
    last = nullptr;
    count = 0;

}

template<class myType>
nodeType<myType>* linkedListType<myType>::firstPtr() const
{
    return first;//returns address of first pointer
}


template<class myType>
myType linkedListType<myType>::front() const
{
    if(first != nullptr)
        return first->info;//returns data in linked list
    
    return myType{};//returns nullptr
}

template<class myType>
myType linkedListType<myType>::back() const
{
    if(last != nullptr)
        return last->info;
        
    return myType{};//call default constructor
}

template<class myType>
void linkedListType<myType>::copyList(const linkedListType& list)
{   //deep copy from the passed list
    //list is original 

    
    //Temp to move
    nodeType<myType>* tmp = list.first; //set temp to head of passed list

    //allocate New Node
    nodeType<myType>* head = new nodeType<myType>;// new node copying to
    first = head;
    
    head->info = tmp->info;//copy over the data
    head->link = nullptr; //setting the tail to null, will add data in while loop
    
    
    nodeType<myType>* current = first; 
    
    tmp = tmp->link;//move to next item in list
    while(tmp != nullptr)
    {
        current->link = new nodeType<myType>();//allocate a new node
        current = current->link; //set current to new node
        current->info = tmp->info;//copy data
        current->link = nullptr; 
        tmp = tmp->link;//move in list
        
    }
    last = current;//set last pointer



}

template<class myType>
void linkedListType<myType>::recursiveReversePrint(nodeType<myType> *list) const
{
    //REVERSE PRINT 
    if (list == nullptr)
    {
        return;
    }
    
        
    
    //recursive call
    //prints the list after the head node
    recursiveReversePrint(list->link);
    
    //prints head once everyting else is printed
    cout << list->info << " "; 
    if (list == first)
        cout << endl;
    
}

#endif