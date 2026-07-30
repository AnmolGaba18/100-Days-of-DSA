#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the limit: ";
    cin >> n;

    vector<int> arr(n);

    cout<<"Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 0) return 0;

    int j = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    cout<<"Output: ";
    for (int i = 0; i <= j; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}