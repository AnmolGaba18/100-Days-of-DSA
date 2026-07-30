#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int a, b;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (abs(sum) < minSum)
        {
            minSum = abs(sum);
            a = arr[left];
            b = arr[right];
        }

        if (sum < 0)
        {
            left++;
        }

        else if (sum > 0)
        {
            right--;
        }

        else
            break;
    }

    cout << "Output: " << a << " " << b << endl;

    return 0;
}