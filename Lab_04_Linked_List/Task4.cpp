#include <iostream>
#include <limits>
using namespace std;
struct Node {
    int roll;
    Node* next;
    Node(int r) : roll(r), next(nullptr) {}
};
bool exists(Node* head, int roll) {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->roll == roll) return true;
    }
    return false;
}
void addStudent(Node*& head, int roll) {
    if (exists(head, roll)) {
        cout << "Roll number " << roll << " is already enrolled.\n";
        return;
    }
    Node* fresh = new Node(roll);
    if (head == nullptr) {
        head = fresh;
    } else {
        Node* cur = head;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = fresh;
    }
    cout << "Student " << roll << " enrolled.\n";
}
void insertAtBeginning(Node*& head, int roll) {
    if (exists(head, roll)) {
        cout << "Roll number " << roll << " is already enrolled.\n";
        return;
    }
    Node* fresh = new Node(roll);
    fresh->next = head;
    head = fresh;
    cout << "Student " << roll << " joins the course.\n";
}
void displayStudents(Node* head) {
    if (head == nullptr) {
        cout << "No students are enrolled.\n";
        return;
    }
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->roll;
        if (cur->next != nullptr) cout << " -> ";
    }
    cout << "\n";
}
void searchStudent(Node* head, int roll) {
    if (exists(head, roll)) cout << "Student Found\n";
    else cout << "Student Not Found\n";
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
    int choice = 0, roll;

    do {
        cout << "\n--- University Course Enrollment ---\n";
        cout << "1. Add student (end of list)\n";
        cout << "2. Insert student at the beginning\n";
        cout << "3. Search student\n";
        cout << "4. Display enrolled students\n";
        cout << "5. Exit\n";
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
                cout << "Enter Roll Number: ";
                if (cin >> roll) {
                    insertAtBeginning(head, roll);
                    cout << "\nAfter insertion:\n";
                    displayStudents(head);
                }
                break;
            case 3:
                cout << "Enter Roll Number to Search: ";
                if (cin >> roll) searchStudent(head, roll);
                break;
            case 4:
                cout << "Enrolled Students:\n";
                displayStudents(head);
                break;
            case 5:
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
    } while (choice != 5 && !cin.eof());
    clearList(head);
    return 0;
}