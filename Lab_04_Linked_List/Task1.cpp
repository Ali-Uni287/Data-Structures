#include <iostream>
#include <limits>
using namespace std;
struct Node {
    int roll;
    Node* next;
    Node(int r) : roll(r), next(NULL) {}
};
bool exists(Node* head, int roll) {
    for (Node* cur = head; cur != NULL ; cur = cur->next) {
        if (cur->roll == roll) return true;
    }
    return false;
}
void addStudent(Node*& head, int roll) {
    if (exists(head, roll)) {
        cout << "Roll number " << roll << " is already registered.\n";
        return;
    }
    Node* fresh = new Node(roll);
    if (head == NULL) {
        head = fresh;
    } else {
        Node* cur = head;
        while (cur->next != NULL) cur = cur->next;
        cur->next = fresh;
    }
    cout << "Student " << roll << " registered.\n";
}
void displayStudents(Node* head) {
    if (head == NULL) {
        cout << "No students registered yet.\n";
        return;
    }
    cout << "Registered Students:\n";
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        cout << cur->roll;
        if (cur->next != NULL) cout << " -> ";
    }
    cout << "\n";
}
void searchStudent(Node* head, int roll) {
    if (exists(head, roll)) cout << "Student Found\n";
    else cout << "Student Not Found\n";
}
void clearList(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* head = NULL;
    int choice, roll;
    do {
        cout << "\n Student Registration System \n";
        cout << "1. Add student\n";
        cout << "2. Display students\n";
        cout << "3. Search student\n";
        cout << "4. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            continue;
        }
        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                if (cin >> roll) addStudent(head, roll);
                break;
            case 2:
                displayStudents(head);
                break;
            case 3:
                cout << "Enter Roll Number to Search: ";
                if (cin >> roll) searchStudent(head, roll);
                break;
            case 4:
                cout << "Goodbye.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

        if (cin.fail() && !cin.eof()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That wasn't a valid roll number.\n";
        }
    } while (choice != 4 && !cin.eof());
    clearList(head);
    return 0;
}
