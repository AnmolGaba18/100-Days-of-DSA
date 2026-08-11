#include <iostream>
#include <queue>
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

vector<vector<int>> levelOrder(Node *root)
{
    if(root == NULL) return {};
    vector<vector<int>> ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);

            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the value of leaf nodes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = buildTree(arr, n);

    vector<vector<int>> ans = levelOrder(root);

    cout << "Level Order Traversal: ";
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}