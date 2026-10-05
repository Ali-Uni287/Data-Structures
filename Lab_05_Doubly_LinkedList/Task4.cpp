#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string name) {
        song = name;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    void addSong(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        count++;
    }

    void displayAll() {
        if (head == NULL) return;
        cout << "Playlist:" << endl;
        Node* current = head;
        int i = 1;
        do {
            cout << i++ << ". " << current->song << endl;
            current = current->next;
        } while (current != head);
    }

    void play(int rounds) {
        if (head == NULL) return;
        Node* current = head;
        for (int r = 1; r <= rounds; r++) {
            cout << "Round " << r << endl;
            for (int i = 0; i < count; i++) {
                cout << "Now playing: " << current->song << endl;
                current = current->next;
            }
        }
    }

    ~Playlist() {
        if (head == NULL) return;
        tail->next = NULL;
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("Tum Hi Ho");
    playlist.addSong("Shape of You");
    playlist.addSong("Blinding Lights");
    playlist.addSong("Kun Faya Kun");
    playlist.addSong("Believer");

    playlist.displayAll();
    cout << endl;
    playlist.play(2);

    return 0;
}