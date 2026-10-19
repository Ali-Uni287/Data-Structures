#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Patient {
    string id;
    int priority;
};

class PriorityQueue {
private:
    Patient patients[SIZE];
    int count;

public:
    PriorityQueue() : count(0) {}

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    void enqueue(string id, int priority) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add more patients.\n";
            return;
        }

        if (priority < 1) {
            cout << "Invalid priority. Use 1 or a higher number.\n";
            return;
        }

        patients[count].id = id;
        patients[count].priority = priority;
        count++;
        cout << "Patient " << id << " added with priority " << priority << ".\n";
    }

    void treatNext() {
        if (isEmpty()) {
            cout << "Queue Underflow! No patients are waiting.\n";
            return;
        }

        // A smaller number means higher urgency: priority 1 is highest.
        int highestIndex = 0;
        for (int i = 1; i < count; i++) {
            if (patients[i].priority < patients[highestIndex].priority) {
                highestIndex = i;
            }
        }

        cout << "Treating patient " << patients[highestIndex].id
             << " (priority " << patients[highestIndex].priority << ").\n";

        // Remove the treated patient by shifting later entries left.
        for (int i = highestIndex; i < count - 1; i++) {
            patients[i] = patients[i + 1];
        }
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patients are waiting.\n";
            return;
        }

        cout << "Waiting patients (ID, priority):\n";
        for (int i = 0; i < count; i++) {
            cout << patients[i].id << " , " << patients[i].priority << "\n";
        }
    }
};

int main() {
    PriorityQueue emergency;
    int choice, priority;
    string id;

    do {
        cout << "\n--- Hospital Emergency (Priority Queue) ---\n";
        cout << "1. Add patient\n";
        cout << "2. Treat highest-priority patient\n";
        cout << "3. Display waiting patients\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient ID (e.g., P102): ";
                cin >> id;
                cout << "Enter priority (1 = highest urgency): ";
                cin >> priority;
                emergency.enqueue(id, priority);
                break;
            case 2:
                emergency.treatNext();
                break;
            case 3:
                emergency.display();
                break;
            case 0:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}