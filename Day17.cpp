#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, minimum, maximum;
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    vector<int> arr(n);

    cout<<"Enter the elements in array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    minimum = *min_element(arr.begin(), arr.end());
    maximum = *max_element(arr.begin(), arr.end());

    cout<<"Minimum: "<<minimum<<endl;
    cout<<"Maximum: "<<maximum<<endl;
}