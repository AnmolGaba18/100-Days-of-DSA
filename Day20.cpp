#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
    int sumSubarrays(vector<int> &arr, int n)
    {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if(mpp.count(sum))
            {
                ans += mpp[sum];
            }

            mpp[sum]++;
        }
        return ans;
    }
};

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter the elements in array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    Solution obj;
    int ans = obj.sumSubarrays(arr, n);

    cout<<"Output: "<<ans;
}