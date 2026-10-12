#include <iostream>
#include <string>
using namespace std;
class OrderStack {
private:
    struct Node {
        string orderID;
        Node* next;

        Node(string id) {
            orderID = id;
            next = NULL;
        }
    };
    Node* top;
public:
    OrderStack() {
        top = NULL;
    }
    ~OrderStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Processing order: "
             << temp->orderID << endl;

        top = top->next;
        delete temp;
    }
    void peek() {
        if (top == NULL) {
            cout << "No orders remaining." << endl;
        } else {
            cout << "Current TOP order: "
                 << top->orderID << endl;
        }
    }
    void display() {
        if (top == NULL) {
            cout << "Order stack is empty." << endl;
            return;
        }
        cout << "Orders (TOP to BOTTOM):" << endl;
        Node* current = top;
        while (current != NULL) {
            cout << current->orderID << endl;
            current = current->next;
        }
    }
    bool isEmpty() {
        return top == NULL;
    }
};
int main() {
    OrderStack restaurant;

    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");
    restaurant.display();
    cout << "\n--- Process Two Orders ---" << endl;
    restaurant.pop();
    restaurant.pop();
    restaurant.peek();
    cout << "\n--- Remaining Orders ---" << endl;
    restaurant.display();
    cout << "\nIs the stack empty? ";
    cout<< (restaurant.isEmpty() ? "Yes" : "No");
    cout<< endl;
    return 0;
}
