
#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int id) {
        if (node == NULL)
            return new Node(id);

        if (id < node->id)
            node->left = insert(node->left, id);
        else if (id > node->id)
            node->right = insert(node->right, id);

        return node;
    }

    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL)
            node = node->left;

        return node;
    }

    Node* remove(Node* node, int id) {
        if (node == NULL)
            return NULL;

        if (id < node->id) {
            node->left = remove(node->left, id);
        }
        else if (id > node->id) {
            node->right = remove(node->right, id);
        }
        else {
            // Case 1: Leaf node
            if (node->left == NULL &&
                node->right == NULL) {
                delete node;
                return NULL;
            }

            // Case 2: Only right child
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: Only left child
            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMin(node->right);
            node->id = temp->id;
            node->right = remove(node->right, temp->id);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }

    void destroy(Node* node) {
        if (node == NULL)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        destroy(root);
    }

    void insert(int id) {
        root = insert(root, id);
    }

    void deleteEmployee(int id) {
        root = remove(root, id);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    int id;

    cout << "Enter employee ID to delete: ";
    cin >> id;

    tree.deleteEmployee(id);

    cout << "Remaining employee IDs: ";
    tree.display();

    return 0;
}
