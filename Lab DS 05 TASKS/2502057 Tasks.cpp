#include <iostream>
using namespace std;

class Node {
public:
    string site;
    Node *prev, *next;

    Node(string s) {
        site = s;
        prev = next = NULL;
    }
};

int main() {
    Node *head = NULL, *tail = NULL;

    string sites[5] = {
        "Google", "YouTube", "Wikipedia", "GitHub", "StackOverflow"
    };

    for (int i = 0; i < 5; i++) {
        Node *newNode = new Node(sites[i]);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    cout << "First to Last:\n";
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->site << endl;
        temp = temp->next;
    }

    cout << "\nLast to First:\n";
    temp = tail;
    while (temp != NULL) {
        cout << temp->site << endl;
        temp = temp->prev;
    }

    return 0;
}
