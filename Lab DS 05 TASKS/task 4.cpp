#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string s) {
        song = s;
        next = NULL;
    }
};

int main() {
    Node* first = new Node("Song 1");
    Node* second = new Node("Song 2");
    Node* third = new Node("Song 3");
    Node* fourth = new Node("Song 4");
    Node* fifth = new Node("Song 5");

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = first;

    Node* temp = first;

    cout << "Playlist:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << temp->song << endl;
        temp = temp->next;
    }

    cout << "\n2 Rounds:" << endl;
    temp = first;

    for(int i = 0; i < 10; i++) {
        cout << temp->song << endl;
        temp = temp->next;
    }

    return 0;
}
