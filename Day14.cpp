#include <iostream>
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
        cout << "Not an Identity Matrix";
        return 0;
    }

    bool isIdentity = true;
    int element;

    cout << "Enter the elements in matrix:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> element;

            if ((i == j && element != 1) || (i != j && element != 0))
            {
                isIdentity = false;
            }
        }
    }

    if (isIdentity)
        cout << "Identity Matrix";
    else
        cout << "Not an Identity Matrix";

    return 0;
}