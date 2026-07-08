#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter the rows: ";
    cin >> rows;

    cout << "Enter the columns: ";
    cin >> cols;

    if (rows != cols)
    {
        cout << "Not a Symmetric Matrix";
        return 0;
    }
    
    vector<vector<int>> mat(rows, vector<int>(cols));

    cout << "Enter the elements: ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> mat[i][j];
        }
    }

    bool isSym = true;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] != mat[j][i])
            {
                isSym = false;
                break;
            }
        }
        if (!isSym)
        {
            break;
        }
    }

    if (isSym)
    {
        cout << "Symmetric Matrix";
    }
    else
    {
        cout << "Not a Symmetric Matrix";
    }
}