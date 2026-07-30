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

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout<<"Enter the elements in matrix: ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin>>matrix[i][j];
        }
    }

    vector<int> ans;
    int top = 0, left = 0, right = cols - 1, bottom = rows - 1;

    while (top <= bottom && left <= right)
    {
        // right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
        }
        bottom--;

        // top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
        }
        left++;
    }

    cout<<"Output: "<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}