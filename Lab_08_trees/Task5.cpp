
#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int id) {
        if (node == nullptr)
            return new Node(id);

        if (id < node->id)
            node->left = insert(node->left, id);
        else if (id > node->id)
            node->right = insert(node->right, id);

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr)
            return;

        cout << node->id << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->id << " ";
    }

    void destroy(Node* node) {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        destroy(root);
    }

    void insert(int id) {
        root = insert(root, id);
    }

    void displayTraversals() {
        cout << "In-order: ";
        inorder(root);

        cout << "\nPre-order: ";
        preorder(root);

        cout << "\nPost-order: ";
        postorder(root);

        cout << endl;
    }
};

int main() {
    BST tree;

    tree.insert(40);
    tree.insert(20);
    tree.insert(60);
    tree.insert(10);
    tree.insert(30);
    tree.insert(50);
    tree.insert(70);

    tree.displayTraversals();

    return 0;
}
