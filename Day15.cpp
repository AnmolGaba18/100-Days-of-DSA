#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int rows, cols;
    int sum = 0;
    cout << "Enter the rows: ";
    cin >> rows;

    cout << "Enter the columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout<<"Enter the elements in matrix: ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin>>matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(i == j)
            {
                sum += matrix[i][j];
            }
        }
        
    }

    cout<<"Sum of the Diagonal is: "<<sum<<endl;
    
}