#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    int n;
    cout << "Enter the number of elements to enqueue: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) 
    {
        int element;
        cin >> element;
        q.push(element);
    }

    cout << "Elements in the queue:\n";
    while(!q.empty()) 
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}