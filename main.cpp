#include <iostream>
#include "linkedlist.h"
#include "stdio.h"
using namespace std;
int main()
{
    LinkedList list;
    list.insertFirst(1, "Hello World");
    list.insertAfter(2, "Hello World 2");
    list.insertBefore(3, "Hello World 3");
    list.insertLast(4, "Hello World 4");
    list.deleteNode();
    list.insertLast(5, "Hello World 5");
    list.deleteNode();
    list.insertLast(6, "Hello World 6");
    list.deleteFirstNode();
    list.insertLast(8, "Hello World 8");
    list.orderInsert(7, "Hello World 7");
    list.TraverseList();
    cout << "Start delete all nodes.." << endl;
    list.deleteAllNodes();
    cout << "All nodes deleted successfully." << endl;
    list.TraverseList();
    return 0;
}