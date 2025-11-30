#include <iostream>
using namespace std;
#ifndef LINKEDLIST
#define LINKEDLIST

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    bool listIsEmpty() const;
    bool cursorIsEmpty() const;
    void initCursor();
    bool isCursorAtHead() const;
    void moveCursorToNext();
    void moveCursorToEnd();
    bool isCursorAtEnd() const;
    int listSize();
    void insertFirst(const int &key, const string &data);
    void insertBefore(const int &key, const string &data);
    void insertAfter(const int &key, const string &data);
    void insertLast(const int &key, const string &data);
    void orderInsert(const int &key, const string &data);
    void updateNode(const int &key, const string &data);
    string searchOnList(const int &key);
    void deleteNode();
    void deleteAllNodes();
    void deleteFirstNode();
    void TraverseList();

private:
    class Node
    {
    public:
        int key;
        string data;
        Node *next;
    };
    typedef Node *NodePtr;
    NodePtr head, prev, cursor;
};

#endif