
#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    int amount;
    Order* left;
    Order* right;

    Order(int id, string name, int a) {
        orderID = id;
        customerName = name;
        amount = a;
        left = right = nullptr;
    }
};

class OrderHeap {
    Order* heap[50];
    int size;

    int deletedAmounts[50];
    int deletedCount;

    void swapNodes(int a, int b) {
        Order* temp = heap[a];
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

            if (heap[i]->amount > heap[parent]->amount) {
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
                heap[left]->amount > heap[largest]->amount)
                largest = left;

            if (right < size &&
                heap[right]->amount > heap[largest]->amount)
                largest = right;

            if (largest == i)
                break;

            swapNodes(i, largest);
            i = largest;
        }
        updatePointers();
    }

public:
    OrderHeap() {
        size = 0;
        deletedCount = 0;
    }

    void insert(int id, string name, int amount) {
        heap[size] = new Order(id, name, amount);
        size++;
        heapifyUp(size-1);
    }

    void display() {
        cout << "\nOrders in Max Heap:\n";

        for (int i = 0; i < size; i++) {
            cout << "Order ID: " << heap[i]->orderID
                 << " | Customer: " << heap[i]->customerName
                 << " | Amount: " << heap[i]->amount << endl;
        }
    }

    void heapSort() {
        cout << "\nDeleting Orders Using Heap Sort:\n";

        while (size > 0) {
            Order* temp = heap[0];

            deletedAmounts[deletedCount++] = temp->amount;

            cout << "Deleted Order: " << temp->orderID
                 << " | Amount: " << temp->amount << endl;

            delete temp;

            heap[0] = heap[size-1];
            size--;

            if (size > 0)
                heapifyDown(0);
        }
    }

    void displaySorted() {
        cout << "\nOrder Amounts in Ascending Order:\n";

        for (int i = deletedCount-1; i >= 0; i--) {
            cout << deletedAmounts[i] << " ";
        }
        cout << endl;
    }

    ~OrderHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};

int main() {
    OrderHeap h;

    h.insert(301, "Ali", 5000);
    h.insert(302, "Ahmed", 8000);
    h.insert(303, "Sara", 3000);
    h.insert(304, "Fatima", 12000);
    h.insert(305, "Usman", 7000);
    h.insert(306, "Ayesha", 10000);

    h.display();

    h.heapSort();

    h.displaySorted();

    return 0;
}