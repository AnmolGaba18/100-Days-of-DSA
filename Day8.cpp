#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int a, b;
    cout<<"Enter the number 1: ";
    cin>>a;

    cout<<"Enter the number 2: ";
    cin>>b;

    int ans = 1;
    for(int i=0; i<b; i++)
    {
        ans = ans * a;
    }

    cout<<"Output: "<<ans;
}