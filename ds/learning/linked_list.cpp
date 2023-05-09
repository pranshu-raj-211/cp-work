#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    // structure of the node
    int data;
    Node *next;

    Node()
    {
        // constructor with default values
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        // parameterised constructor
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        // default constructor
        head = NULL;
    }

    void insertNode(int);
    void printList();
    void deleteNode(int);
};

void Linkedlist::deleteNode(int offset)
{
    Node *temp1 = head, *temp2 = NULL;
    int len = 0;

    if (head == NULL)
    {
        cout << "list is empty";
        return;
    }

    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        len++;
    }

    if (len < offset)
    {
        cout << "Offset out of range";
        return;
    }

    temp1 = head;
    if (offset == 1)
    {
        head = head.next;
        delete temp1;
        return;
    }

    while (offset-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete temp1;
}
