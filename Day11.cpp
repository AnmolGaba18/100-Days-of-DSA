#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    cout<<"Enter the rows: ";
    cin>>n;

    cout<<"Enter the columns: ";
    cin>>m;

    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<int>> mat2(n, vector<int>(m));
    vector<vector<int>> ans(n, vector<int>(m));

    cout<<"Enter the elements in matrix 1: ";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mat[i][j];
        }
    }

    cout<<"Enter the elements in matrix 2: ";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mat2[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            ans[i][j] = mat[i][j] + mat2[i][j];
        }
    }

    cout<<"Matrix Addition: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}