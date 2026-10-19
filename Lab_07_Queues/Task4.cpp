#include <iostream>
using namespace std;

const int SIZE = 5;

class Deque {
private:
    int data[SIZE];
    int front, rear, count;

public:
    Deque() : front(0), rear(-1), count(0) {}

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot insert at front.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }

        data[front] = value;
        count++;
        cout << value << " inserted at the front.\n";
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot insert at rear.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        data[rear] = value;
        count++;
        cout << value << " inserted at the rear.\n";
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! Nothing to remove.\n";
            return;
        }

        cout << "Removed from front: " << data[front] << ".\n";
        if (count == 1) {
            front = 0;
            rear = -1;
            count = 0;
        } else {
            front = (front + 1) % SIZE;
            count--;
        }
    }

    void removeRear() {
        if (isEmpty()) {
            cout << "Deque Underflow! Nothing to remove.\n";
            return;
        }

        cout << "Removed from rear: " << data[rear] << ".\n";
        if (count == 1) {
            front = 0;
            rear = -1;
            count = 0;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
            count--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Front -> ";
        for (int i = 0; i < count; i++) {
            cout << data[(front + i) % SIZE];
            if (i < count - 1) {
                cout << ", ";
            }
        }
        cout << " <- Rear\n";
    }
};

int main() {
    Deque requests;
    int choice, requestID;

    do {
        cout << "\n--- Train Station (Deque) ---\n";
        cout << "1. Insert request at front\n";
        cout << "2. Insert request at rear\n";
        cout << "3. Remove request from front\n";
        cout << "4. Remove request from rear\n";
        cout << "5. Display requests\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter passenger request ID: ";
                cin >> requestID;
                requests.insertFront(requestID);
                break;
            case 2:
                cout << "Enter passenger request ID: ";
                cin >> requestID;
                requests.insertRear(requestID);
                break;
            case 3:
                requests.removeFront();
                break;
            case 4:
                requests.removeRear();
                break;
            case 5:
                requests.display();
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