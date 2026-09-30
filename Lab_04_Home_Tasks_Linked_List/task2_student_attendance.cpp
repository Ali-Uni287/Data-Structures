#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    int roll;
    string name;
    string status;
    Student* next;
};

Student* head = nullptr;

Student* findStudent(int roll) {
    Student* cur = head;
    while (cur != nullptr && cur->roll != roll)
        cur = cur->next;
    return cur;
}

void addStudent(int roll, const string& name, const string& status) {
    if (findStudent(roll) != nullptr) {
        cout << "Roll number " << roll << " is already in the list.\n";
        return;
    }
    Student* s = new Student;
    s->roll = roll;
    s->name = name;
    s->status = status;
    s->next = nullptr;
    if (head == nullptr) {
        head = s;
    } else {
        Student* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = s;
    }
    cout << "Student " << name << " added.\n";
}

void searchStudent(int roll) {
    Student* s = findStudent(roll);
    if (s == nullptr) {
        cout << "Student not found.\n";
        return;
    }
    cout << "Roll No: " << s->roll << " | Name: " << s->name << " | Status: " << s->status << "\n";
}

void deleteStudent(int roll) {
    if (head == nullptr) {
        cout << "Student not found.\n";
        return;
    }
    Student* del = nullptr;
    if (head->roll == roll) {
        del = head;
        head = head->next;
    } else {
        Student* cur = head;
        while (cur->next != nullptr && cur->next->roll != roll)
            cur = cur->next;
        if (cur->next == nullptr) {
            cout << "Student not found.\n";
            return;
        }
        del = cur->next;
        cur->next = del->next;
    }
    cout << "Student " << del->name << " removed from the list.\n";
    delete del;
}

void displayStudents(const string& heading) {
    cout << "\n" << heading << "\n";
    if (head == nullptr) {
        cout << "The attendance list is empty.\n";
        return;
    }
    for (Student* cur = head; cur != nullptr; cur = cur->next)
        cout << "Roll No: " << cur->roll << " | Name: " << cur->name << " | Status: " << cur->status << "\n";
}

int countPresent() {
    int count = 0;
    for (Student* cur = head; cur != nullptr; cur = cur->next)
        if (cur->status == "Present")
            count++;
    return count;
}

void freeList() {
    while (head != nullptr) {
        Student* temp = head;
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

string readStatus() {
    string input;
    while (true) {
        cout << "Attendance (P = Present, A = Absent): ";
        getline(cin, input);
        if (input == "P" || input == "p") return "Present";
        if (input == "A" || input == "a") return "Absent";
        cout << "Enter P or A only.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== University Student Attendance List =====\n";
        cout << "1. Add a student\n";
        cout << "2. Search student by roll number\n";
        cout << "3. Delete a student\n";
        cout << "4. Display all students\n";
        cout << "5. Count students present\n";
        cout << "6. Display final attendance list\n";
        cout << "0. Exit\n";
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: {
                int roll = readInt("Roll Number: ");
                string name;
                cout << "Student Name: ";
                getline(cin, name);
                addStudent(roll, name, readStatus());
                break;
            }
            case 2:
                searchStudent(readInt("Enter Roll Number: "));
                break;
            case 3:
                deleteStudent(readInt("Enter Roll Number: "));
                break;
            case 4:
                displayStudents("All students:");
                break;
            case 5:
                cout << "Total students present: " << countPresent() << "\n";
                break;
            case 6:
                displayStudents("Final attendance list:");
                cout << "Present: " << countPresent() << "\n";
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
