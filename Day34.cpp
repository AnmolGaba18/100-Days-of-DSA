#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if (top == NULL)
            return -1;

        int val = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    int peek()
    {
        return top->data;
    }

    bool empty()
    {
        return top == NULL;
    }
};

int main()
{
    Stack st;
    string postfix;
    getline(cin, postfix);

    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]))
        {
            st.push(stoi(token));
        }
        else
        {
            int b = st.pop();
            int a = st.pop();

            if (token == "+")
                st.push(a + b);
            else if (token == "-")
                st.push(a - b);
            else if (token == "*")
                st.push(a * b);
            else if (token == "/")
                st.push(a / b);
        }
    }

    cout << st.peek();

    return 0;
}