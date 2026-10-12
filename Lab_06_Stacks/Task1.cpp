#include <iostream>
#include <string>
using namespace std;
class BrowserStack {
private:
    string pages[10];
    int top;
public:
    BrowserStack() {
        top = -1;
    }
    void push(string page) {
        if (top == 9) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        pages[++top] = page;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << "Back button pressed. Removed: "
             << pages[top] << endl;
        top--;
    }
    void peek() {
        if (top == -1) {
            cout << "No current page." << endl;
        } else {
            cout << "Current TOP page: "
                 << pages[top] << endl;
        }
    }
    void display() {
        if (top == -1) {
            cout << "Browsing history is empty." << endl;
            return;
        }
        cout << "Browsing History (TOP to BOTTOM):" << endl;

        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }
};
int main() {
    BrowserStack browser;
    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");
    browser.display();
    cout << "\n--- Back Operation ---" << endl;
    browser.pop();
    browser.peek();
    cout << "\n--- Remaining History ---" << endl;
    browser.display();
    return 0;
}
