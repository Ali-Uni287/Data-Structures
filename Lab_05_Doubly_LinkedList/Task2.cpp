#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string image;
    Node* prev;
    Node* next;

    Node(string name) {
        image = name;
        prev = NULL;
        next = NULL;
    }
};

class ImageGallery {
private:
    Node* head;
    Node* tail;

public:
    ImageGallery() {
        head = NULL;
        tail = NULL;
    }

    void addImage(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void displayForward() {
        cout << "Gallery forward (first -> last):" << endl;
        for (Node* current = head; current != NULL; current = current->next) {
            cout << current->image << endl;
        }
    }

    void displayBackward() {
        cout << "Gallery backward (last -> first):" << endl;
        for (Node* current = tail; current != NULL; current = current->prev) {
            cout << current->image << endl;
        }
    }

    void demonstrateNavigation() {
        Node* current = head;
        cout << "Moving forward using next:" << endl;
        while (current->next != NULL) {
            cout << current->image << " -> " << current->next->image << endl;
            current = current->next;
        }
        cout << "Moving backward using prev:" << endl;
        while (current->prev != NULL) {
            cout << current->image << " -> " << current->prev->image << endl;
            current = current->prev;
        }
    }

    ~ImageGallery() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    ImageGallery gallery;

    gallery.addImage("sunset.jpg");
    gallery.addImage("mountain.png");
    gallery.addImage("beach.jpg");
    gallery.addImage("city.png");
    gallery.addImage("forest.jpg");

    gallery.displayForward();
    cout << endl;
    gallery.displayBackward();
    cout << endl;
    gallery.demonstrateNavigation();

    return 0;
}