#include <iostream>
#include <string>
using namespace std;
class PatientStack {
private:
    struct Node {
        string patientID;
        Node* next;

        Node(string id) {
            patientID = id;
            next = NULL;
        }
    };
    Node* top;
public:
    PatientStack() {
        top = NULL;
    }
    ~PatientStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
	}
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Handling patient request: "
             << temp->patientID << endl;

        top = top->next;
        delete temp;
    }
    void peek() {
        if (top == NULL) {
            cout << "No pending patient requests." << endl;
        } else {
            cout << "Current TOP patient: "
                 << top->patientID << endl;
        }
    }
    void display() {
        if (top == NULL) {
            cout << "No patient requests remaining." << endl;
            return;
        }
        cout << "Patient Requests (TOP to BOTTOM):" << endl;
        Node* current = top;
        while (current != NULL) {
            cout << current->patientID << endl;
            current = current->next;
        }
    }
};
int main() {
    PatientStack hospital;
    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");
    hospital.display();
    cout << "\n--- Handle Latest Request ---" << endl;
    hospital.pop();
    hospital.peek();
    cout << "\n--- Remaining Requests ---" << endl;
    hospital.display();
    return 0;
}
