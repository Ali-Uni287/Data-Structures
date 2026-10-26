
#include <iostream>
using namespace std;

class Node {
public:
    int roll;
    Node* left;
    Node* right;

    Node(int r) {
        roll = r;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int roll) {
        if (node == nullptr)
            return new Node(roll);

        if (roll < node->roll)
            node->left = insert(node->left, roll);
        else if (roll > node->roll)
            node->right = insert(node->right, roll);
        else
            cout << "Duplicate roll number ignored: "
                 << roll << endl;

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->roll << " ";
        inorder(node->right);
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

    void insert(int roll) {
        root = insert(root, roll);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.insert(45);
    tree.insert(25);
    tree.insert(65);
    tree.insert(15);
    tree.insert(35);
    tree.insert(55);
    tree.insert(75);

    int roll;

    for (int i = 1; i <= 2; i++) {
        cout << "Enter additional roll number " << i << ": ";
        cin >> roll;
        tree.insert(roll);
    }

    cout << "Roll numbers in ascending order: ";
    tree.display();

    return 0;
}
