#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, ops;

    cout << "Enter the number of elements: ";
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    cout << "Enter the number of operations: ";
    cin >> ops;

    cout<<"\nEnter the following number for operations: (1 for insert, 2 for remove, 3 for peek)"<<endl;
    for (int i = 0; i < ops; i++)
    {
        cout << "Enter the operations: " << endl;
        int operation;
        cin >> operation;

        if (operation == 1)
        {
            int element;
            cout << "Enter the element to insert: ";
            cin >> element;
            pq.push(element);
            cout << "Inserted " << element << endl;
        }
        else if (operation == 2)
        {
            if (!pq.empty())
            {
                cout << "Removed " << pq.top() << endl;
                pq.pop();
            }
            else
            {
                cout << "Priority queue is empty!" << endl;
            }
        }
        else if (operation == 3)
        {
            if (!pq.empty())
            {
                cout << "Peek: " << pq.top() << endl;
            }
            else
            {
                cout << "Priority queue is empty!" << endl;
            }
        }
        else
        {
            cout << "Invalid operation!" << endl;
        }
    }
}