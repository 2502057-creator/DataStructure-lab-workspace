

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = NULL;
    }
};

int main() {
    Node* first = new Node("Lajpal");
    Node* second = new Node("Hashmi");
    Node* third = new Node("Waqas");
    Node* fourth = new Node("Hamza");
    Node* fifth = new Node("Bilal");

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = first;

    Node* temp = first;

    for(int i = 0; i < 5; i++) {
        cout << temp->name << "'s turn" << endl;
        temp = temp->next;
    }

    cout << "After last player: " << temp->name << "'s turn" << endl;

    return 0;
}

