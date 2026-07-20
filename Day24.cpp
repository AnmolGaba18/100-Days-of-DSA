#include <iostream>
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
    cout << "Enter the number of nodes: ";
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    cout << "Enter the elements in the list: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        Node *newNode = new Node(x);

        if (head == nullptr)
        {
            head = tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    cout << "Enter the value to be deleted: ";
    cin >> val;

    Node dummy(0);
    dummy.next = head;

    Node *prev = &dummy;
    Node *curr = head;

    while (curr)
    {
        if (curr->data == val)
        {
            prev->next = curr->next;
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    head = dummy.next;

    Node *temp2 = head;
    cout<<"Output: ";
    while (temp2 != NULL)
    {
        cout<<temp2->data<<" ";
        temp2 = temp2->next;
    }
}