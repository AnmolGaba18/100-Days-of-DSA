#include <iostream>
#include <queue>
#include <map>
#include <vector>
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

void verticalOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    map<int, vector<int>> vertical;
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        Node *current = q.front().first;
        int horizontalDistance = q.front().second;
        q.pop();

        vertical[horizontalDistance].push_back(current->data);

        if (current->left != nullptr)
        {
            q.push({current->left, horizontalDistance - 1});
        }

        if (current->right != nullptr)
        {
            q.push({current->right, horizontalDistance + 1});
        }
    }

    cout << "Vertical Order Traversal:" << endl;

    for (auto column : vertical)
    {
        for (int value : column.second)
        {
            cout << value << " ";
        }

        cout << endl;
    }
}

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
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

    verticalOrderTraversal(root);

    deleteTree(root);
    delete[] arr;

    return 0;
}
