#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    int marks;
    Student* left;
    Student* right;
    
    Student(string n, int r, int m) {
        name = n;
        rollNo = r;
        marks = m;
        left = right = nullptr;
    }
};

class MaxHeap {
    Student* heap[50];
    int size;

    void swapNodes(int a, int b) {
        Student* temp = heap[a];
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

            if (heap[i]->marks > heap[parent]->marks) {
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
                heap[left]->marks > heap[largest]->marks)
                largest = left;

            if (right < size &&
                heap[right]->marks > heap[largest]->marks)
                largest = right;

            if (largest == i)
                break;

            swapNodes(i, largest);
            i = largest;
        }
        updatePointers();
    }

public:
    MaxHeap() {
        size = 0;
    }

    void insert(string name, int roll, int marks) {
        heap[size] = new Student(name, roll, marks);
        size++;
        heapifyUp(size-1);
    }

    void display() {
        cout << "\nStudent Heap (Level Order):\n";

        for (int i = 0; i < size; i++) {
            cout << heap[i]->name
                 << " | Roll: " << heap[i]->rollNo
                 << " | Marks: " << heap[i]->marks << endl;
        }
    }

    void deleteHighest() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "\nDeleted Highest Student: "
             << heap[0]->name
             << " | Marks: " << heap[0]->marks << endl;

        delete heap[0];

        heap[0] = heap[size-1];
        size--;

        if (size > 0)
            heapifyDown(0);
    }

    ~MaxHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};

int main() {
    MaxHeap h;

    h.insert("Ali", 101, 85);
    h.insert("Ahmed", 102, 92);
    h.insert("Sara", 103, 78);
    h.insert("Fatima", 104, 96);
    h.insert("Usman", 105, 88);
    h.insert("Ayesha", 106, 90);

    h.display();

    h.deleteHighest();

    cout << "\nUpdated Heap After Deletion:";
    h.display();

    return 0;
}