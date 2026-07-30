#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    Node* head = nullptr;
    Node* tail = nullptr;

    cout<<"Enter the value of nodes: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    Node* temp = head;
    cout<<"Output: ";
    if (head != nullptr)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    cout << endl;

    return 0;
}