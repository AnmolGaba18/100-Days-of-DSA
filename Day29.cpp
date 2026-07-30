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

Node *findLast(Node *head, int k)
{
    int count = 1;
    while (head != NULL)
    {
        if (count == k)
            return head;
        count++;
        head = head->next;
    }
    return head;
}

Node *rotateRight(Node *head, int k)
{
    if (head == NULL || k == 0)
        return head;
    Node *temp = head;
    int len = 1;

    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }

    if (k % len == 0)
        return head;
    k = k % len;

    temp->next = head;

    Node *lastNode = findLast(head, len - k);

    head = lastNode->next;
    lastNode->next = NULL;

    return head;
}

int main()
{
    int n, k;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    cout << "Enter the value of nodes: ";
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
            tail = newNode;
        }
    }

    cout << "Enter the rotation count: ";
    cin >> k;
    Node *ans = rotateRight(head, k);
    Node *temp = ans;

    cout << "Output: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}