#include <iostream>
using namespace std;

const int SIZE = 5;

class LinearQueue {
private:
    int queue[SIZE];
    int front, rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    void enqueue(int token) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add customer " << token << ".\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }
        queue[++rear] = token;
        cout << "Customer " << token << " added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No customers are waiting.\n";
            return;
        }

        cout << "Serving customer " << queue[front] << ".\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No customers are waiting.\n";
            return;
        }

        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }

    void countWaiting() {
        if (isEmpty()) {
            cout << "Number of waiting customers: 0\n";
        } else {
            cout << "Number of waiting customers: " << rear - front + 1 << "\n";
        }
    }
};

int main() {
    LinearQueue bank;
    int choice, token;

    do {
        cout << "\n--- Bank Customer Service (Linear Queue) ---\n";
        cout << "1. Add customer token (enqueue)\n";
        cout << "2. Serve next customer (dequeue)\n";
        cout << "3. Display waiting customers\n";
        cout << "4. Count waiting customers\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer token number: ";
                cin >> token;
                bank.enqueue(token);
                break;
            case 2:
                bank.dequeue();
                break;
            case 3:
                bank.display();
                break;
            case 4:
                bank.countWaiting();
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