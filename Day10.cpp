#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string value;
    cout<<"Enter the string: ";
    cin>>value;

    string temp = value;
    
    int n = value.size();
    string real(value.size(), ' ');

    int a = n-1;

    for(int i=0; i < n; i++)
    {
        real[a] = value[i];
        a--;
    }

    if(temp == real)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
}