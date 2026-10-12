#include <iostream>
#include <string>
using namespace std;
class ActionStack {
private:
    string actions[10];
    int top;
public:
    ActionStack() {
        top = -1;
    }
    void push(string action) {
        if (top == 9) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        actions[++top] = action;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Undo action: " << actions[top] << endl;
        top--;
    }
    void peek() {
        if (top == -1) {
            cout << "No actions remaining." << endl;
        } else {
            cout << "Current TOP action: "
                 << actions[top] << endl;
        }
    }
    void display() {
        if (top == -1) {
            cout << "No actions remaining." << endl;
            return;
        }
        cout << "Actions (TOP to BOTTOM):" << endl;

        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }
};
int main() {
    ActionStack editor;
    editor.push("Type \"Hello\"");
    editor.push("Type \"World\"");
    editor.push("Add \"!\"");
    editor.push("Delete \"!\"");
    editor.display();
    cout << "\n--- Two Undo Operations ---" << endl;
    editor.pop();
    editor.pop();
    editor.peek();
    cout << "\n--- Remaining Actions ---" << endl;
    editor.display();
    return 0;
}
