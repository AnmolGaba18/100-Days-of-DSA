#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, key;
    int count = 0;
    bool found = false;

    cout << "Enter the limit: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements in array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        count++;
        if (arr[i] == key)
        {
            cout << "Key found at index: " << i << endl;
            cout << "Comparisons: " << count << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Key not found." << endl;
        cout << "Comparisons: " << count << endl;
    }

    return 0;
}