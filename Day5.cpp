#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the limit of array 1: ";
    cin >> n;

    cout << "Enter the limit of array 2: ";
    cin >> m;
    
    vector<int> arr1(n);
    vector<int> arr2(m);
    vector<int> arr3(m+n);

    cout << "Enter elements in array 1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter elements in array 2: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    int i, j;
    i = j = 0;
    int a = 0;
    while(i < n && j < m)
    {
        if(arr1[i] <= arr2[j])
        {
            arr3[a++] = arr1[i++];
        }
        else{
            arr3[a++] = arr2[j++];
        }
    }
    while(i < n)
    {
        arr3[a] = arr1[i];
        i++;
        a++;
    }

    while(j < m)
    {
        arr3[a] = arr2[j];
        j++;
        a++;
    }

    cout<<"Merged array: ";
    for (int k = 0; k < n + m; k++)
    {
        cout << arr3[k] << " ";
    }
}