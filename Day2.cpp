#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int n, position;

    cout<<"Enter the size: ";
    cin>>n;

    vector<int> arr(n+1);

    cout<<"Enter the elements: ";
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter the position: ";
    cin>>position;

    arr.erase(arr.begin() + (position));
    
    cout<<"Final Array after removal: ";
    for(int i=1; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}