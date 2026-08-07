#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    queue<int> q;
    cout<<"Enter the elements in the queue: ";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }

    stack<int> st;

    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    cout<<"Reversed Stack: ";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}