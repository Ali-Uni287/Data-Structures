#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int patientID;
    int priority;
    Patient* left;
    Patient* right;

    Patient(string n, int id, int p) {
        name = n;
        patientID = id;
        priority = p;
        left = right = nullptr;
    }
};

class PatientHeap {
    Patient* heap[50];
    int size;

    void swapNodes(int a, int b) {
        Patient* temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
    }

    void updatePointers() {
        for (int i = 0; i < size; i++) {
            heap[i]->left = (2*i+1 < size) ? heap[2*i+1] : nullptr;
            heap[i]->right = (2*i+2 < size) ? heap[2*i+2] : nullptr;
        }
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i-1)/2;

            if (heap[i]->priority > heap[parent]->priority) {
                swapNodes(i, parent);
                i = parent;
            } else {
                break;
            }
        }
        updatePointers();
    }

    void heapifyDown(int i) {
        while (true) {
            int largest = i;
            int left = 2*i+1;
            int right = 2*i+2;

            if (left < size &&
                heap[left]->priority > heap[largest]->priority)
                largest = left;

            if (right < size &&
                heap[right]->priority > heap[largest]->priority)
                largest = right;

            if (largest == i)
                break;

            swapNodes(i, largest);
            i = largest;
        }
        updatePointers();
    }

public:
    PatientHeap() {
        size = 0;
    }

    void insert(string name, int id, int priority) {
        heap[size] = new Patient(name, id, priority);
        size++;
        heapifyUp(size-1);
    }

    void display() {
        cout << "\nPatients (Level Order):\n";

        for (int i = 0; i < size; i++) {
            cout << heap[i]->name
                 << " | ID: " << heap[i]->patientID
                 << " | Priority: " << heap[i]->priority
                 << endl;
        }
    }

    void showHighest() {
        if (size == 0) {
            cout << "No patients available!\n";
            return;
        }

        cout << "\nHighest Priority Patient:\n";
        cout << heap[0]->name
             << " | ID: " << heap[0]->patientID
             << " | Priority: " << heap[0]->priority
             << endl;
    }

    void treatPatient() {
        if (size == 0) {
            cout << "No patients to treat!\n";
            return;
        }

        cout << "\nPatient Treated: " << heap[0]->name
             << " | Priority: " << heap[0]->priority << endl;

        delete heap[0];

        heap[0] = heap[size-1];
        size--;

        if (size > 0)
            heapifyDown(0);
    }

    ~PatientHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};

int main() {
    PatientHeap h;

    h.insert("Ali", 201, 4);
    h.insert("Ahmed", 202, 8);
    h.insert("Sara", 203, 5);
    h.insert("Fatima", 204, 10);
    h.insert("Usman", 205, 6);
    h.insert("Ayesha", 206, 9);

    h.display();

    h.showHighest();

    h.treatPatient();

    h.display();

    h.showHighest();

    return 0;
}