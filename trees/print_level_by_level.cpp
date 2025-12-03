#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void level_order(Node *root)
{
    // base case
    if (root == nullptr)
        return;

    // we define a queue for storing nodes and track them level by level
    queue<Node *> q;
    // first push the root
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size(); // number of nodes at this level
        for (int i = 0; i < levelSize; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl; // move to next line after completing that level
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level-Order Traversal: ";
    level_order(root);
    cout << endl;
    return 0;
}