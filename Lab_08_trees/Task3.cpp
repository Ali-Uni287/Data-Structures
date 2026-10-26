
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

    bool search(Node* node, int id, int& comparisons) {
        if (node == NULL)
            return false;

        comparisons++;

        if (node->id == id)
            return true;

        if (id < node->id)
            return search(node->left, id, comparisons);

        return search(node->right, id, comparisons);
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

    void searchBook(int id) {
        int comparisons = 0;

        if (search(root, id, comparisons))
            cout << "Book Found!" << endl;
        else
            cout << "Book Not Found!" << endl;

        cout << "Comparisons: " << comparisons << endl;
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

    int id;

    cout << "Enter book ID to search: ";
    cin >> id;

    tree.searchBook(id);

    return 0;
}
