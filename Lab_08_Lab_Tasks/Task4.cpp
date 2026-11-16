
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int token;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        token = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(Node* node) {
    if (node == NULL)
        return 0;

    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->token)
        root->left = insert(root->left, value);

    else if (value > root->token)
        root->right = insert(root->right, value);

    else
        return root;

    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && value < root->left->token)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && value > root->right->token)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && value > root->left->token) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && value < root->right->token) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->token << " ";
    inorder(root->right);
}

void displayTree(Node* root, int space = 0) {
    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->token
         << " (H:" << root->height
         << ", BF:" << getBalance(root) << ")";

    displayTree(root->left, space);
}

int main() {
    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    cout << "Hospital Appointment System\n\n";

    for (int i = 0; i < 7; i++) {
        root = insert(root, tokens[i]);
        cout << "Inserted Token: " << tokens[i] << endl;
    }

    cout << "\nIn-order Traversal:\n";
    inorder(root);

    cout << "\n\nFinal Balanced AVL Tree:\n";
    displayTree(root);

    cout << endl;

    return 0;
}