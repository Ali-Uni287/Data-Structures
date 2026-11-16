#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string c) {
        category = c;
        left = NULL;
        right = NULL;
    }
};

void BFS(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->category << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

int main() {
    Node* root = new Node("Electronics");

    root->left = new Node("Clothing");
    root->right = new Node("Accessories");

    root->left->left = new Node("Mobiles");
    root->left->right = new Node("Laptops");

    root->right->left = new Node("Men");
    root->right->right = new Node("Women");

    cout << "Online Shopping Categories\n\n";

    cout << "Breadth First Traversal (BFS):\n";

    BFS(root);

    cout << endl;

    return 0;
}