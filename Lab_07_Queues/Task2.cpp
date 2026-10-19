#include <iostream>
using namespace std;

const int SIZE = 5;

class CircularQueue {
private:
    int queue[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    void enqueue(int packetID) {
        if (isFull()) {
            cout << "Queue Overflow! Buffer is full.\n";
            return;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = packetID;
        count++;
        cout << "Packet " << packetID << " added to the buffer.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No packets to transmit.\n";
            return;
        }

        cout << "Transmitting packet " << queue[front] << ".\n";
        front = (front + 1) % SIZE;
        count--;

        if (count == 0) {
            front = 0;
            rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No packets are waiting.\n";
            return;
        }

        cout << "Packets waiting for transmission: ";
        for (int i = 0; i < count; i++) {
            cout << queue[(front + i) % SIZE] << " ";
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue buffer;
    int choice, packetID;

    do {
        cout << "\n--- Network Packet Buffer (Circular Queue) ---\n";
        cout << "1. Add packet\n";
        cout << "2. Transmit oldest packet\n";
        cout << "3. Display waiting packets\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter packet ID: ";
                cin >> packetID;
                buffer.enqueue(packetID);
                break;
            case 2:
                buffer.dequeue();
                break;
            case 3:
                buffer.display();
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