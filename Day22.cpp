#include<iostream>
#include<list>
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
    int n;
    cout<<"Enter the number of nodes in linked list: ";
    cin>>n;

    Node *head = nullptr;
    Node *tail = nullptr;

    cout<<"\nEnter the elements in the list: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;

        Node *newNode = new Node(x);

        if(head == nullptr)
        {
            head = tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node *temp = head;
    int count = 0;
    cout<<"\nElements in the list: ";
    while(temp != NULL)
    {
        count++;
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
    cout<<"\nTotal Elements: "<<count;
    
}