#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Order {
    string id;
    string customer;
    string item;
    Order* next;
};

Order* head = nullptr;

Order* findOrder(const string& id) {
    Order* cur = head;
    while (cur != nullptr && cur->id != id)
        cur = cur->next;
    return cur;
}

Order* createOrder(const string& id, const string& customer, const string& item) {
    Order* o = new Order;
    o->id = id;
    o->customer = customer;
    o->item = item;
    o->next = nullptr;
    return o;
}

void addAtEnd(const string& id, const string& customer, const string& item) {
    if (findOrder(id) != nullptr) {
        cout << "Order " << id << " already exists.\n";
        return;
    }
    Order* o = createOrder(id, customer, item);
    if (head == nullptr) {
        head = o;
    } else {
        Order* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = o;
    }
    cout << "Order " << id << " added.\n";
}

void addUrgent(const string& id, const string& customer, const string& item) {
    if (findOrder(id) != nullptr) {
        cout << "Order " << id << " already exists.\n";
        return;
    }
    Order* o = createOrder(id, customer, item);
    o->next = head;
    head = o;
    cout << "Urgent Order " << id << " received.\n";
}

void searchOrder(const string& id) {
    Order* o = findOrder(id);
    if (o == nullptr) {
        cout << "Order " << id << " not found.\n";
        return;
    }
    cout << "Order ID: " << o->id << " | Customer: " << o->customer << " | Item: " << o->item << "\n";
}

void removeOrder(const string& id) {
    if (head == nullptr) {
        cout << "There are no pending orders.\n";
        return;
    }
    Order* del = nullptr;
    if (head->id == id) {
        del = head;
        head = head->next;
    } else {
        Order* cur = head;
        while (cur->next != nullptr && cur->next->id != id)
            cur = cur->next;
        if (cur->next == nullptr) {
            cout << "Order " << id << " not found.\n";
            return;
        }
        del = cur->next;
        cur->next = del->next;
    }
    cout << "Order " << del->id << " delivered.\n";
    delete del;
}

void displayOrders(const string& heading) {
    cout << "\n" << heading << "\n";
    if (head == nullptr) {
        cout << "No pending orders.\n";
        return;
    }
    for (Order* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->id;
        if (cur->next != nullptr)
            cout << " -> ";
    }
    cout << "\n";
    for (Order* cur = head; cur != nullptr; cur = cur->next)
        cout << "  " << cur->id << " | " << cur->customer << " | " << cur->item << "\n";
}

void freeList() {
    while (head != nullptr) {
        Order* temp = head;
        head = head->next;
        delete temp;
    }
}

int readInt(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

string readLine(const string& prompt) {
    string s;
    cout << prompt;
    getline(cin, s);
    return s;
}

int main() {
    int choice;
    do {
        cout << "\n===== Online Food Delivery Orders =====\n";
        cout << "1. Add new order at end\n";
        cout << "2. Display all pending orders\n";
        cout << "3. Search order by ID\n";
        cout << "4. Remove delivered order\n";
        cout << "5. Add urgent order at beginning\n";
        cout << "6. Display updated pending-order list\n";
        cout << "0. Exit\n";
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
            case 5: {
                string id = readLine("Order ID: ");
                string customer = readLine("Customer Name: ");
                string item = readLine("Food Item: ");
                if (choice == 1)
                    addAtEnd(id, customer, item);
                else
                    addUrgent(id, customer, item);
                break;
            }
            case 2:
                displayOrders("Pending Orders:");
                break;
            case 3:
                searchOrder(readLine("Enter Order ID: "));
                break;
            case 4:
                removeOrder(readLine("Enter Order ID: "));
                break;
            case 6:
                displayOrders("Updated Pending Orders:");
                break;
            case 0:
                cout << "Goodbye.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    freeList();
    return 0;
}
