#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string site;
    Node* prev;
    Node* next;

    Node(string s) {
        site = s;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
private:
    Node* head;
    Node* tail;

public:
    BrowserHistory() {
        head = NULL;
        tail = NULL;
    }

    void visit(string site) {
        Node* newNode = new Node(site);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void showFirstToLast() {
        cout << "History (first visited -> last visited):" << endl;
        Node* current = head;
        int i = 1;
        while (current != NULL) {
            cout << i++ << ". " << current->site << endl;
            current = current->next;
        }
    }

    void showLastToFirst() {
        cout << "History (last visited -> first visited):" << endl;
        Node* current = tail;
        int i = 1;
        while (current != NULL) {
            cout << i++ << ". " << current->site << endl;
            current = current->prev;
        }
    }

    ~BrowserHistory() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    BrowserHistory history;

    history.visit("google.com");
    history.visit("youtube.com");
    history.visit("github.com");
    history.visit("stackoverflow.com");
    history.visit("wikipedia.org");

    history.showFirstToLast();
    cout << endl;
    history.showLastToFirst();

    return 0;
}