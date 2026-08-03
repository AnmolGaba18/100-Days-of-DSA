#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    deque<int> dq;
    int n, x;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        dq.push_back(x);
    }

    cout << "\nDeque elements: ";
    for (int i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;
    cout << "Size of deque: " << dq.size() << endl;
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl;

    cout << "\nEnter an element to insert at the front: ";
    cin >> x;
    dq.push_front(x);

    cout << "Enter an element to insert at the back: ";
    cin >> x;
    dq.push_back(x);

    cout << "\nDeque after insertion: ";
    for (int i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "Deque after pop_front and pop_back: ";
    for (int i : dq)
        cout << i << " ";
    cout << endl;

    reverse(dq.begin(), dq.end());

    cout << "Deque after reverse: ";
    for (int i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    sort(dq.begin(), dq.end());

    cout << "Deque after sort: ";
    for (int i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    dq.clear();

    cout << "Deque cleared successfully." << endl;
    cout << "Current size of deque: " << dq.size() << endl;

    return 0;
}