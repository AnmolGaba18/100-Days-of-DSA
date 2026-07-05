#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of the string: ";
    cin >> n;

    vector<char> arr(n);

    cout<<"Enter the characters: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int left = 0, right = n-1;

    while(left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    cout<<"Reversed String: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}