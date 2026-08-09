#include <iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node (int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *buildtTree(int arr[], int n)
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

        if( i < n && arr[i] != -1)
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

void inOrder(Node *root)
{   
    if(root == NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if(root == NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    int arr[n];

    cout<<"Enter the number of elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    
    Node *root = buildtTree(arr, n);
    cout<<"Inorder Traversal: ";
    inOrder(root);

    cout<<"\nPreorder Traversal: ";
    preOrder(root);

    cout<<"\nPostorder Traversal: ";
    postOrder(root);
}