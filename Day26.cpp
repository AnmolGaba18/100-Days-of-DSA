#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void insert(Node*& head, Node*& tail, int val)
{
    Node* newNode = new Node(val);

    if (head == nullptr)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void printList(Node* head)
{
    Node* temp = head;

    cout<<"Output: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    cout<<"Enter the value of nodes: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        insert(head, tail, val);
    }

    printList(head);

    return 0;
}