#include <iostream>
#include <queue>
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

Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return nullptr;

    Node *root = new Node(arr[0]);

    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n)
    {
        Node *current = q.front();
        q.pop();

        if (i < n && arr[i] != -1)
        {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

Node *lowestCommonAncestor(Node *root, int value1, int value2)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == value1 || root->data == value2)
        return root;

    Node *leftLCA = lowestCommonAncestor(root->left, value1, value2);
    Node *rightLCA = lowestCommonAncestor(root->right, value1, value2);

    if (leftLCA != nullptr && rightLCA != nullptr)
        return root;

    if (leftLCA != nullptr)
        return leftLCA;

    return rightLCA;
}

int main()
{
    Node *root = nullptr;

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter the level-order values (-1 for NULL): ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    root = buildTree(arr, n);

    int value1, value2;

    cout << "Enter the two node values: ";
    cin >> value1 >> value2;

    Node *lca = lowestCommonAncestor(root, value1, value2);

    if (lca != nullptr)
    {
        cout << "Lowest Common Ancestor of "
             << value1 << " and " << value2
             << " is: " << lca->data << endl;
    }
    else
    {
        cout << "LCA not found." << endl;
    }

    delete[] arr;

    return 0;
}
