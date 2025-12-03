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

int max_node(Node *root)
{
    // base case
    if (root == nullptr)
        return INT_MIN;

    int max = root->data;
    // we will count the number of nodes in the left and right subtree, and add 1 to the total count
    int left_max = max_node(root->left);
    int right_max = max_node(root->right);

    if (left_max > max)
    {
        max = left_max;
    }
    if (right_max > max)
    {
        max = right_max;
    }
    return max;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "maximum value of node in a binary tree: ";
    int ans = max_node(root);
    cout << ans << endl;
    return 0;
}