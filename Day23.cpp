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

void insertEnd(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node *mergeSortedLists(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    Node *dummy = new Node(0);
    Node *curr = dummy;
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data <= head2->data)
        {
            curr->next = head1;
            head1 = head1->next;
        }
        else
        {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if (head1 != nullptr)
    {
        curr->next = head1;
    }
    else
    {
        curr->next = head2;
    }
    Node *mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n, m, val;
    if (!(cin >> n))
        return 0;
    Node *head1 = nullptr;
    Node *tail1 = nullptr;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertEnd(head1, tail1, val);
    }
    if (!(cin >> m))
        return 0;
    Node *head2 = nullptr;
    Node *tail2 = nullptr;
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        insertEnd(head2, tail2, val);
    }
    Node *mergedHead = mergeSortedLists(head1, head2);
    printList(mergedHead);
    return 0;
}