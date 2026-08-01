#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of elements to enqueue: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the value of elements to enqueue: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the number of dequeue operations: ";
    cin >> m;

    int front = 0;
    int rear = 0;

    rear = n - 1;

    front = (front + m) % n;
    rear = (rear + m) % n;

    cout << "Queue elements after operations: ";
    int i = front;
    while (true)
    {
        cout << arr[i] << " ";
        if (i == rear)
        {
            break;
        }
        i = (i + 1) % n;
    }

    return 0;
}