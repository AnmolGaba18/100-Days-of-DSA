#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> arr(n);

    unordered_map<int, int> freq;
    cout<<"Enter the elements in array: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    cout<<"Output: ";
    for (auto it : freq)
    {
        cout << it.first << ":" << it.second << " ";
    }

    return 0;
}