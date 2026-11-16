#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string f) {
        folder = f;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->folder << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->folder << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->folder << " ";
}

int main() {
    Node* root = new Node("C:");

    root->left = new Node("Program Files");
    root->right = new Node("Users");

    root->left->left = new Node("Microsoft Office");
    root->left->right = new Node("Games");

    root->right->left = new Node("Documents");
    root->right->right = new Node("Downloads");

    cout << "Computer File Explorer\n\n";

    cout << "In-order Traversal:\n";
    inorder(root);

    cout << "\n\nPre-order Traversal:\n";
    preorder(root);

    cout << "\n\nPost-order Traversal:\n";
    postorder(root);

    cout << endl;

    return 0;
}