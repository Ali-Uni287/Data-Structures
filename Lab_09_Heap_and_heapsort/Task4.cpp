#include <iostream>
#include <string>
using namespace std;

struct Medicine {
    string name;
    int medicineID;
    int expiryDate;
    Medicine* left;
    Medicine* right;

    Medicine(string n, int id, int date) {
        name = n;
        medicineID = id;
        expiryDate = date;
        left = right = nullptr;
    }
};

class MinHeap {
    Medicine* heap[50];
    int size;

    void swapNodes(int a, int b) {
        Medicine* temp = heap[a];
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

            if (heap[i]->expiryDate < heap[parent]->expiryDate) {
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
            int smallest = i;
            int left = 2*i+1;
            int right = 2*i+2;

            if (left < size &&
                heap[left]->expiryDate < heap[smallest]->expiryDate)
                smallest = left;

            if (right < size &&
                heap[right]->expiryDate < heap[smallest]->expiryDate)
                smallest = right;

            if (smallest == i)
                break;

            swapNodes(i, smallest);
            i = smallest;
        }
        updatePointers();
    }

public:
    MinHeap() {
        size = 0;
    }

    void insert(string name, int id, int date) {
        heap[size] = new Medicine(name, id, date);
        size++;
        heapifyUp(size-1);
    }

    void display() {
        cout << "\nMedicines in Min Heap:\n";

        for (int i = 0; i < size; i++) {
            cout << heap[i]->name
                 << " | ID: " << heap[i]->medicineID
                 << " | Expiry Date: " << heap[i]->expiryDate
                 << endl;
        }
    }

    void deleteNearestExpiry() {
        if (size == 0) {
            cout << "No medicines available!\n";
            return;
        }

        cout << "\nMedicine with Nearest Expiry:\n";

        cout << heap[0]->name
             << " | ID: " << heap[0]->medicineID
             << " | Expiry Date: " << heap[0]->expiryDate
             << endl;

        delete heap[0];

        heap[0] = heap[size-1];
        size--;

        if (size > 0)
            heapifyDown(0);
    }

    ~MinHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};

int main() {
    MinHeap h;

    h.insert("Panadol", 401, 20271215);
    h.insert("Brufen", 402, 20261210);
    h.insert("Augmentin", 403, 20281120);
    h.insert("Calpol", 404, 20260515);
    h.insert("Disprin", 405, 20270310);
    h.insert("Cetrizine", 406, 20261025);

    h.display();

    h.deleteNearestExpiry();

    cout << "\nUpdated Heap After Deletion:";
    h.display();

    return 0;
}