#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the limit: ";
    cin>>n;

    int ans = 1, a = 0, b = 1;
    for(int i=1; i<n; i++)
    {
        ans = a+b;
        a = b;
        b = ans;
    }

    cout<<"Output: "<<ans;
}