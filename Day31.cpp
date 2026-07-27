#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    int stack[1000];
    int top = -1;

    cout << "Enter the operations: ";

    while (n--)
    {
        int op;
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int value;
            cin >> value;
            stack[++top] = value;
            cout << "Output: " << value << " pushed into the stack." << endl;
            break;
        }

        case 2:
        {
            if (top == -1)
                cout << "Output: Stack Underflow" << endl;
            else
                cout << "Output: Popped element is " << stack[top--] << endl;
            break;
        }

        case 3:
        {
            if (top == -1)
            {
                cout << "Output: Stack is empty." << endl;
            }
            else
            {
                cout << "Output: Current Stack (Top to Bottom): ";
                for (int i = top; i >= 0; i--)
                    cout << stack[i] << " ";
                cout << endl;
            }
            break;
        }

        default:
            cout << "Output: Invalid Operation" << endl;
        }
    }

    return 0;
}