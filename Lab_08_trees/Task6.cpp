#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = NULL;
        right = NULL;
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
        else
            cout << "Duplicate product ID!" << endl;

        return node;
    }

    bool search(Node* node, int id) {
        if (node == NULL)
            return false;

        if (node->id == id)
            return true;

        if (id < node->id)
            return search(node->left, id);

        return search(node->right, id);
    }

    Node* findMin(Node* node) {
        while (node->left != NULL)
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
            // No child
            if (node->left == NULL &&
                node->right == NULL) {
                delete node;
                return NULL;
            }

            // Only right child
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Only left child
            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Two children
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

    void preorder(Node* node) {
        if (node == NULL)
            return;

        cout << node->id << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->id << " ";
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

    void insertProduct(int id) {
        if (search(root, id)) {
            cout << "Product ID already exists!" << endl;
            return;
        }

        root = insert(root, id);
        cout << "Product inserted successfully." << endl;
    }

    void searchProduct(int id) {
        if (search(root, id))
            cout << "Product Found!" << endl;
        else
            cout << "Product Not Found!" << endl;
    }

    void deleteProduct(int id) {
        if (!search(root, id)) {
            cout << "Product Not Found. Cannot delete."
                 << endl;
            return;
        }

        root = remove(root, id);
        cout << "Product deleted successfully." << endl;
    }

    void displayInorder() {
        cout << "In-order: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Pre-order: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Post-order: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, id;

    do {
        cout << "\n===== ONLINE STORE INVENTORY =====\n";
        cout << "1. Insert a product ID\n";
        cout << "2. Search for a product ID\n";
        cout << "3. Delete a product ID\n";
        cout << "4. Display in-order traversal\n";
        cout << "5. Display pre-order traversal\n";
        cout << "6. Display post-order traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;
            tree.insertProduct(id);
            break;

        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;
            tree.searchProduct(id);
            break;

        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;
            tree.deleteProduct(id);
            break;

        case 4:
            tree.displayInorder();
            break;

        case 5:
            tree.displayPreorder();
            break;

        case 6:
            tree.displayPostorder();
            break;

        case 7:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
