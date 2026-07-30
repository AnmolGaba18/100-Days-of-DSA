#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

int main()
{
    int n, val;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    Node *head = nullptr;
    Node *tail = nullptr;

    cout<<"Enter the nodes: ";
    for (int  i = 0; i < n; i++)
    {
        int x;
        cin>>x;

        Node *newNode = new Node(x);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout<<"Enter the value to be counter: ";
    cin>>val;

    Node *temp = head;
    int count = 0;
    
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            count ++;
        }

        temp = temp->next;
    }
    
    cout<<"Frequency of " <<val<<" is: "<<count;
}