#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int item)
    {
        data = item;
        left = right = nullptr;
    }
};

class GFG
{
public:
    static void inOrderTraversal(Node *root)
    {
        if (root == nullptr)
            return;

        // Visit the root node
        cout << root->data << " ";

        // Traverse the left subtree
        inOrderTraversal(root->left);

        // Traverse the right subtree
        inOrderTraversal(root->right);
    }
};

int main()
{
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "In-Order Traversal: ";
    GFG::inOrderTraversal(root);
    cout << endl;

    return 0;
}