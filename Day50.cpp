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

Node *searchBST(Node *root, int value)
{
    if (root == nullptr || root->data == value)
        return root;

    if (value < root->data)
        return searchBST(root->left, value);

    return searchBST(root->right, value);
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    cout << "BST after insertion (Inorder): ";
    inorder(root);

    cout << endl;

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    Node *result = searchBST(root, value);

    if (result != nullptr)
    {
        cout << "Value " << value << " found in BST." << endl;
    }
    else
    {
        cout << "Value " << value << " not found in BST." << endl;
    }

    return 0;
}
