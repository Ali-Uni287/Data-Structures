
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class FamilyTree {
private:
    Node* root;

    void display(Node* node) {
        if (node == nullptr)
            return;

        cout << "Person: " << node->name << endl;

        cout << "Left child: ";
        if (node->left != nullptr)
            cout << node->left->name;
        else
            cout << "None";
        cout << endl;

        cout << "Right child: ";
        if (node->right != nullptr)
            cout << node->right->name;
        else
            cout << "None";
        cout << "\n\n";

        display(node->left);
        display(node->right);
    }

public:
    FamilyTree() {
        root = nullptr;
    }

    void createTree() {
        root = new Node("Grandfather");

        root->left = new Node("Father");
        root->right = new Node("Uncle");

        root->left->left = new Node("Ali");
        root->left->right = new Node("Sara");

        root->right->left = new Node("Ahmed");
        root->right->right = new Node("Ayesha");
    }

    void displayTree() {
        display(root);
    }

    ~FamilyTree() {
        destroy(root);
    }

private:
    void destroy(Node* node) {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }
};

int main() {
    FamilyTree tree;

    tree.createTree();
    tree.displayTree();

    return 0;
}
