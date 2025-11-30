#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = NULL;
    prev = NULL;
    cursor = NULL;
}

LinkedList::~LinkedList()
{
    head = NULL;
    prev = NULL;
    cursor = NULL;
}

bool LinkedList::listIsEmpty() const
{
    return head == NULL;
}
bool LinkedList::cursorIsEmpty() const
{
    return cursor == NULL;
}

void LinkedList::initCursor()
{
    prev = NULL;
    cursor = head;
}

bool LinkedList::isCursorAtHead() const
{
    return cursor == head;
}

void LinkedList::moveCursorToNext()
{
    prev = cursor;
    cursor = cursor->next;
}

void LinkedList::moveCursorToEnd()
{
    initCursor();
    if (!listIsEmpty())
    {
        while (cursor->next != NULL)
        {
            moveCursorToNext();
        }
    }
}

bool LinkedList::isCursorAtEnd() const
{
    return cursor == NULL;
}

int LinkedList::listSize()
{
    int count = 0;
    initCursor();
    while (cursor != NULL)
    {
        count++;
        moveCursorToNext();
    }
    return count;
}

void LinkedList::insertFirst(const int &key, const string &data)
{
    NodePtr newNode = new Node;
    newNode->key = key;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    cursor = head;
    prev = NULL;
}

void LinkedList::insertAfter(const int &key, const string &data)
{
    NodePtr newNode = new Node;
    newNode->key = key;
    newNode->data = data;
    newNode->next = nullptr;
    head->next = newNode;
    cursor = newNode;
    prev = head;
}

void LinkedList::insertBefore(const int &key, const string &data)
{
    NodePtr newNode = new Node;
    newNode->key = key;
    newNode->data = data;
    newNode->next = cursor;
    prev->next = newNode;
}

void LinkedList::insertLast(const int &key, const string &data)
{
    moveCursorToEnd();
    NodePtr newNode = new Node;
    newNode->key = key;
    newNode->data = data;
    newNode->next = nullptr;
    prev->next = cursor;
    cursor->next = newNode;
}

void LinkedList::updateNode(const int &key, const string &data)
{
    initCursor();
    while (!isCursorAtEnd())
    {
        if (cursor->key == key)
        {
            cursor->data = data;
        }
        moveCursorToNext();
    }
}

void LinkedList::orderInsert(const int &key, const string &data)
{
    initCursor();
    while (!isCursorAtEnd())
    {
        if (cursor->key > key)
        {
            insertBefore(key, data);
            return;
        }
        moveCursorToNext();
    }
    insertLast(key, data);
}

string LinkedList::searchOnList(const int &key)
{
    initCursor();
    while (!isCursorAtEnd())
    {
        if (cursor->key == key)
        {
            return cursor->data;
        }
        moveCursorToNext();
    }
    return "";
}

void LinkedList::deleteNode()
{
    if (!isCursorAtEnd())
    {
        prev->next = cursor;
        cursor->next = nullptr;
    }
}

void LinkedList::deleteAllNodes()
{
    initCursor();
    while (!listIsEmpty())
    {
        cout << "deleting " << cursor->key << endl;
        deleteFirstNode();
    }
}

void LinkedList::deleteFirstNode()
{
    if (!listIsEmpty())
    {
        head = head->next;
        initCursor();
    }
}

void LinkedList::TraverseList()
{
    initCursor();
    while (cursor != NULL)
    {
        cout << cursor->key << " " << cursor->data << endl;
        moveCursorToNext();
    }
    if (listIsEmpty())
    {
        cout << "List is empty" << endl;
    }
}
