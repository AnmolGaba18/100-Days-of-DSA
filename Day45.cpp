#include<iostream>
#include<queue>
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
    if(n == 0 || arr[0] == -1) return NULL;

    Node *root = new Node(arr[0]);

    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n)
    {
        Node *current = q.front();
        q.pop();

        if(i < n && arr[i] != -1)
        {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        if(i < n && arr[i] != -1)
        {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
    
}

int countDepth(Node *root)
{
    if(root == nullptr) return 0;
    int count = 0;
    
    int left = countDepth(root->left);
    int right = countDepth(root->right);

    return 1 + max(left, right);
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the values of leaf nodes: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    Node *root = buildTree(arr, n);

    int ans = countDepth(root);
    cout<<"Depth: "<<ans;
}