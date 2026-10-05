#include <iostream>
using namespace std;

class Node {
public:
    string image;
    Node* next;
    Node* prev;

    Node(string n) {
        image = n;
        next = NULL;
        prev = NULL;
    }
};

int main() {
    Node* first = new Node("Image1");
    Node* second = new Node("Image2");
    Node* third = new Node("Image3");
    Node* fourth = new Node("Image4");
    Node* fifth = new Node("Image5");

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    Node* temp = first;

    cout << "Forward:" << endl;
    while(temp != NULL) {
        cout << temp->image << endl;
        temp = temp->next;
    }

    temp = fifth;

    cout << "Backward:" << endl;
    while(temp != NULL) {
        cout << temp->image << endl;
        temp = temp->prev;
    }

    return 0;
}
