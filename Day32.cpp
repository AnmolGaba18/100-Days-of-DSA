#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    stack<int> st;

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
            st.push(value);
            cout << "Output: " << value << " pushed into the stack." << endl;
            break;
        }

        case 2:
        {
            if (st.empty())
                cout << "Output: Stack Underflow" << endl;
            else
            {
                cout << "Output: Popped element is " << st.top() << endl;
                st.pop();
            }
            break;
        }

        default:
            cout << "Output: Invalid Operation" << endl;
        }
    }

    return 0;
}