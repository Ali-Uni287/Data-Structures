#include <iostream>
#include <string>
using namespace std;
struct Node {
    string id;
    Node* next;
    Node(const string& p) : id(p), next(nullptr) {}
};
bool exists(Node* head, const string& id) {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->id == id) return true;
    }
    return false;
}
void addPatient(Node*& head, const string& id) {
    if (exists(head, id)) {
        cout << "Patient " << id << " is already in the queue.\n";
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
    cout << "Patient " << id << " added to the queue.\n";
}
void displayQueue(Node* head) {
    if (head == nullptr) {
        cout << "No patients are waiting.\n";
        return;
    }
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->id;
        if (cur->next != nullptr) cout << " -> ";
    }
    cout << "\n";
}
void servePatient(Node*& head) {
    if (head == nullptr) {
        cout << "No patients to serve.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Patient " << temp->id << " is being served.\n";
    delete temp;

    cout << "\nUpdated Queue:\n";
    displayQueue(head);
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
        cout << "\n--- Hospital Patient Queue ---\n";
        cout << "1. Add patient\n";
        cout << "2. Display waiting patients\n";
        cout << "3. Serve first patient\n";
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
                cout << "Enter Patient ID: ";
                cin >> id;
                addPatient(head, id);
                break;
            case 2:
                cout << "Waiting Patients:\n";
                displayQueue(head);
                break;
            case 3:
                servePatient(head);
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