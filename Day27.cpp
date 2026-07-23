#include<iostream>
#include<cstdlib>
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

int length(Node *head)
{
    int len = 0;

    while(head != nullptr)
    {
        len++;
        head = head->next;
    }

    return len;
}

void intersection(Node *head1, Node *head2)
{
    int len1 = length(head1);
    int len2 = length(head2);

    int diff = abs(len1 - len2);

    if(len1 > len2)
    {
        while(diff--)
        {
            head1 = head1->next;
        }
    }
    else
    {
        while(diff--)
        {
            head2 = head2->next;
        }
    }

    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1->data == head2->data)
        {
            cout << "Output: " << head1->data;
            return;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    cout << "No Intersection";
}

int main()
{
    int m, n;

    cout << "Enter the number of nodes in list 1: ";
    cin >> n;

    cout << "Enter the number of nodes in list 2: ";
    cin >> m;

    Node *head1 = nullptr;
    Node *tail1 = nullptr;

    Node *head2 = nullptr;
    Node *tail2 = nullptr;

    cout << "Enter the values in list 1: ";
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        Node *newNode = new Node(x);

        if(head1 == nullptr)
        {
            head1 = tail1 = newNode;
        }
        else
        {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    cout << "Enter the values in list 2: ";
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        Node *newNode = new Node(x);

        if(head2 == nullptr)
        {
            head2 = tail2 = newNode;
        }
        else
        {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    intersection(head1, head2);

    return 0;
}