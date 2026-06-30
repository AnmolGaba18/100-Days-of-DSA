#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;

    cout << "Enter the limit: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        
        start++;
        end--;
    }

    cout << "Reversed array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}