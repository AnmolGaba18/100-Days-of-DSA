#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int value)
{
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

Node *lowestCommonAncestor(Node *root, int value1, int value2)
{
    if (root == nullptr)
        return nullptr;

    // Both values are smaller than root
    if (value1 < root->data && value2 < root->data)
        return lowestCommonAncestor(root->left, value1, value2);

    // Both values are greater than root
    if (value1 > root->data && value2 > root->data)
        return lowestCommonAncestor(root->right, value1, value2);

    // Values are on different sides
    // or one value is equal to root
    return root;
}

int main()
{
    Node *root = nullptr;

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the values: ";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        root = insert(root, value);
    }

    int value1, value2;

    cout << "Enter the two node values: ";
    cin >> value1 >> value2;

    Node *lca = lowestCommonAncestor(root, value1, value2);

    cout << "Lowest Common Ancestor of "
         << value1 << " and " << value2
         << " is: " << lca->data << endl;

    return 0;
}