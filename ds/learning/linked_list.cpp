#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    // structure of the node
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, int x)
{
    // function to insert a node at the beginning of list
    // reference is passed to make changes to original list rather than making copies

    Node *temp = new Node(x); // creation of new node
    temp->next = head;        // setting temp to be at beginning of list
    head = temp;              // setting head to temp
}

void print_list(Node *&head)
{
    Node *temp = head;
    // using temp instead of head because we passed head by reference
    if (temp == NULL)
    {
        cout << "list is empty";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insert_at_tail(Node *&head, int x)
{
    Node *temp = head;
    // using temp instead of head because we passed head by reference
    if (temp == NULL)
    {
        cout << "list is empty";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    Node *head = node1;
    cout << head->data;

    int i, n, x;
    cout << "\nEnter number of nodes needed ";
    cin >> n;
    cout << "\nEnter values to be inserted\n";
    for (i = 0; i < n - 1; i++)
    {
        // entering elements into list
        cin >> x;
        insert_at_head(head, x);
    }

    cout << "\nThe data stored in the list is\n";
    print_list(head); // calling function to print list elements

    return 0;
}
