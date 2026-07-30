#include <iostream>
using namespace std;

struct Node
{
    int coeff;
    int exp;
    Node *next;

    Node(int c, int e)
    {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

class Polynomial
{
    Node *head, *tail;
    public:
    Polynomial()
    {
        head = tail = NULL;
    }

    void insert(int c, int e)
    {
        Node *temp = new Node(c, e);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void display()
    {
        cout<<"Output: ";
        Node *cur = head;
        while (cur != NULL)
        {
            cout << cur->coeff;
            if (cur->exp > 1)
                cout << "x^" << cur->exp;
            else if (cur->exp == 1)
                cout << "x";

            if (cur->next != NULL)
                cout << " + ";

            cur = cur->next;
        }
    }
};

int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin >> n;

    Polynomial p;

    cout<<"Enter the value of coefficient and exponent: ";
    for (int i = 0; i < n; i++)
    {
        int coeff, exp;
        cin >> coeff >> exp;
        p.insert(coeff, exp);
    }

    p.display();

    return 0;
}