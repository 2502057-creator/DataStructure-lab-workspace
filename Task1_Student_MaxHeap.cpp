#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    string name;
    int roll, marks;
    Node *left, *right;
    Node(string n, int r, int m) {
        name=n; roll=r; marks=m;
        left=right=NULL;
    }
};

class MaxHeap {
    Node *root;
    queue<Node*> q;
public:
    MaxHeap() { root=NULL; }
    void insert(string n, int r, int m) {
        Node *temp=new Node(n,r,m);
        if(root==NULL) { root=temp; q.push(root); return; }
        Node *p=q.front();
        if(p->left==NULL) p->left=temp;
        else { p->right=temp; q.pop(); }
        q.push(temp);
        // Heapify Up
        Node *child=temp;
        while(child!=root) {
            Node *par=NULL;
            queue<Node*> find; find.push(root);
            while(!find.empty()) {
                Node *x=find.front(); find.pop();
                if(x->left==child || x->right==child) { par=x; break; }
                if(x->left) find.push(x->left);
                if(x->right) find.push(x->right);
            }
            if(par->marks>=child->marks) break;
            swap(par->name,child->name); swap(par->roll,child->roll);
            swap(par->marks,child->marks); child=par;
        }
    }
    void show(Node *n) {
        if(!n) return;
        queue<Node*> x; x.push(n);
        while(!x.empty()) {
            Node *p=x.front(); x.pop();
            cout<<p->name<<" Roll:"<<p->roll<<" Marks:"<<p->marks<<endl;
            if(p->left) x.push(p->left);
            if(p->right) x.push(p->right);
        }
    }
    void display() { show(root); }
};

int main() {
    MaxHeap h;
    h.insert("Ali",101,80); h.insert("Sara",102,95);
    h.insert("Ahmed",103,75); h.insert("Ayesha",104,90);
    h.insert("Hina",105,98); h.insert("Usman",106,85);
    cout<<"Student Max Heap:"<<endl;
    h.display();
    return 0;
}