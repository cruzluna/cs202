// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List list;

    //Put some things in the linked list
    cout << "--------------Default linked list--------------" << endl;
    list.Insert(4);
    list.Insert(7);
    list.Insert(2);
    list.Insert(5);

    list.print();

    if (list.Lookup(7) != nullptr)
        cout << "Found 7 in the list!" << endl;

    if (list.Lookup(11) != nullptr)
        cout << "Found 11 in the list!" << endl;

    //Check if sort works
    list.sort();
    list.print();

    list.Deletion(2);
    list.Deletion(4);

    list.print();

    //------------- Recursive Example -------------
    cout << endl << "--------------Recursive linked list--------------" << endl;
    List recList;
    recList.RecursiveInsert(5, recList.getHead()); //Try to insert 5 at the head
    recList.RecursiveInsert(8, recList.getHead());
    recList.RecursiveInsert(10, recList.getHead());
    recList.RecursiveInsert(12, recList.getHead());

    recList.print();

    recList.RecursiveDeletion(8, recList.getHead(), nullptr);

    recList.print();

    //------------- Sorting at insert time Example -------------
    cout << endl << "--------------Sorted linked list--------------" << endl;
    List sorted;
    sorted.insertInOrder(5);
    sorted.insertInOrder(7);
    sorted.insertInOrder(6);
    sorted.insertInOrder(8);
    sorted.insertInOrder(4);

    sorted.print();
}