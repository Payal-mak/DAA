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

int count_nodes(Node *root)
{
    // base case
    if (root == nullptr)
        return 0;

    // we will count the number of nodes in the left and right subtree, and add 1 to the total count
    int left_subtree = count_nodes(root->left);
    int right_subtree = count_nodes(root->right);

    return left_subtree + right_subtree + 1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "number of nodes in a binary tree: ";
    int ans = count_nodes(root);
    cout << ans << endl;
    return 0;
}