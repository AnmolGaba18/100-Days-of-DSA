#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int arr[], int n)
{

    if (n == 0 || arr[0] == -1)
        return NULL;

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

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main()
{

    int n;
    cout<< "Enter the number of nodes: ";
    cin >> n;

    int arr[n];

    cout<< "Enter the node values (use -1 for NULL nodes): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = buildTree(arr, n);

    cout<<"Inorder Traversal: ";
    inorder(root);

    return 0;
}