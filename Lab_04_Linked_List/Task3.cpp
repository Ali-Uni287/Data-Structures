#include <iostream>
#include <string>
using namespace std;
struct Node {
    string productId;
    Node* next;
    Node(const string& id) : productId(id), next(nullptr) {}
};
bool exists(Node* head, const string& id) {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->productId == id) return true;
    }
    return false;
}
void addProduct(Node*& head, const string& id) {
    if (exists(head, id)) {
        cout << "Product " << id << " is already in the cart.\n";
        return;
    }
    Node* fresh = new Node(id);
    if (head == nullptr) {
        head = fresh;
    } else {
        Node* cur = head;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = fresh;
    }
    cout << "Product " << id << " added to the cart.\n";
}
void displayCart(Node* head) {
    if (head == nullptr) {
        cout << "The cart is empty.\n";
        return;
    }
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->productId;
        if (cur->next != nullptr) cout << " -> ";
    }
    cout << "\n";
}
void removeProduct(Node*& head, const string& id) {
    if (head == nullptr) {
        cout << "The cart is empty.\n";
        return;
    }
    Node* target = nullptr;
    if (head->productId == id) {
        target = head;
        head = head->next;
    } else {
        Node* prev = head;
        while (prev->next != nullptr && prev->next->productId != id) {
            prev = prev->next;
        }
        if (prev->next == nullptr) {
            cout << "Product " << id << " was not found in the cart.\n";
            return;
        }
        target = prev->next;
        prev->next = target->next;
    }
    delete target;

    cout << "\nUpdated Cart:\n";
    displayCart(head);
}
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* head = nullptr;
    int choice = 0;
    string id;

    do {
        cout << "\n--- Online Shopping Cart ---\n";
        cout << "1. Add product\n";
        cout << "2. Display cart\n";
        cout << "3. Remove product\n";
        cout << "4. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter Product ID: ";
                cin >> id;
                addProduct(head, id);
                break;
            case 2:
                cout << "Shopping Cart:\n";
                displayCart(head);
                break;
            case 3:
                cout << "Remove Product: ";
                cin >> id;
                removeProduct(head, id);
                break;
            case 4:
                cout << "Goodbye.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    clearList(head);
    return 0;
}