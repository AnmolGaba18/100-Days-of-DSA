#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, k;
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    vector<int> arr(n);
    
    cout<<"Enter the elements in array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter the positions to rotate: ";
    cin>>k;

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());

    cout<<"Output: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}