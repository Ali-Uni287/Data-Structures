#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    Patient* next;
};

Patient* head = nullptr;

Patient* createPatient(int id, const string& name, int age) {
    Patient* p = new Patient;
    p->id = id;
    p->name = name;
    p->age = age;
    p->next = nullptr;
    return p;
}

Patient* findPatient(int id) {
    Patient* cur = head;
    while (cur != nullptr && cur->id != id)
        cur = cur->next;
    return cur;
}

void addAtEnd(int id, const string& name, int age) {
    if (findPatient(id) != nullptr) {
        cout << "A patient with ID " << id << " is already in the list.\n";
        return;
    }
    Patient* p = createPatient(id, name, age);
    if (head == nullptr) {
        head = p;
    } else {
        Patient* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = p;
    }
    cout << "Patient " << name << " added to the end of the list.\n";
}

void addAtBeginning(int id, const string& name, int age) {
    if (findPatient(id) != nullptr) {
        cout << "A patient with ID " << id << " is already in the list.\n";
        return;
    }
    Patient* p = createPatient(id, name, age);
    p->next = head;
    head = p;
    cout << "Emergency patient " << name << " added at the front.\n";
}

void searchPatient(int id) {
    Patient* p = findPatient(id);
    if (p == nullptr) {
        cout << "Patient with ID " << id << " does not exist.\n";
        return;
    }
    cout << "Found -> ID: " << p->id << " | Name: " << p->name << " | Age: " << p->age << "\n";
}

void removePatient(int id) {
    if (head == nullptr) {
        cout << "The waiting list is empty.\n";
        return;
    }
    Patient* del = nullptr;
    if (head->id == id) {
        del = head;
        head = head->next;
    } else {
        Patient* cur = head;
        while (cur->next != nullptr && cur->next->id != id)
            cur = cur->next;
        if (cur->next == nullptr) {
            cout << "Patient with ID " << id << " does not exist.\n";
            return;
        }
        del = cur->next;
        cur->next = del->next;
    }
    cout << "Patient " << del->name << " treated and removed from the list.\n";
    delete del;
}

void displayPatients() {
    if (head == nullptr) {
        cout << "No patients are waiting.\n";
        return;
    }
    cout << "\nWaiting patients:\n";
    int pos = 1;
    for (Patient* cur = head; cur != nullptr; cur = cur->next)
        cout << pos++ << ". ID: " << cur->id << " | Name: " << cur->name << " | Age: " << cur->age << "\n";
}

void freeList() {
    while (head != nullptr) {
        Patient* temp = head;
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

void readPatient(int& id, string& name, int& age) {
    id = readInt("Patient ID: ");
    cout << "Patient Name: ";
    getline(cin, name);
    age = readInt("Patient Age: ");
}

int main() {
    int choice;
    do {
        cout << "\n===== Hospital Emergency Patient Management =====\n";
        cout << "1. Add new patient at end\n";
        cout << "2. Add emergency patient at beginning\n";
        cout << "3. Search patient by ID\n";
        cout << "4. Remove patient after treatment\n";
        cout << "5. Display all waiting patients\n";
        cout << "0. Exit\n";
        choice = readInt("Enter your choice: ");

        int id, age;
        string name;
        switch (choice) {
            case 1:
                readPatient(id, name, age);
                addAtEnd(id, name, age);
                break;
            case 2:
                readPatient(id, name, age);
                addAtBeginning(id, name, age);
                break;
            case 3:
                searchPatient(readInt("Enter Patient ID: "));
                break;
            case 4:
                removePatient(readInt("Enter Patient ID: "));
                break;
            case 5:
                displayPatients();
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
