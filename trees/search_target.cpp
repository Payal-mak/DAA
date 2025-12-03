// given an integer value, search for the node with the value in the given tree
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

bool search_val(Node *root, int &val)
{
    // base case
    if (root == nullptr)
        return false;

    if (root->data == val)
    {
        return true;
    }
    return search_val(root->left, val) or search_val(root->right, val);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int target = 5;

    cout << "node with value " << target << ": ";
    bool ans = search_val(root, target);
    cout << ans << endl;
    return 0;
}