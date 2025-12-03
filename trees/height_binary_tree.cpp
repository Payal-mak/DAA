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

int height(Node *root)
{
    // base case
    if (root == nullptr)
        return 0;

    // we will compute the height of left and right subtree, and add 1 to the total height
    int left_subtree = height(root->left);
    int right_subtree = height(root->right);

    return 1 + max(left_subtree, right_subtree);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of binary tree: ";
    int ans = height(root);
    cout << ans << endl;
    return 0;
}