#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    string name;
    int id, priority;
    Node *left,*right;
    Node(string n,int i,int p) {
        name=n; id=i; priority=p; left=right=NULL;
    }
};

class MaxHeap {
    Node *root;
    queue<Node*> q;
public:
    MaxHeap() { root=NULL; }
    void insert(string n,int id,int p) {
        Node *t=new Node(n,id,p);
        if(!root) { root=t; q.push(root); return; }
        Node *x=q.front();
        if(!x->left) x->left=t;
        else { x->right=t; q.pop(); }
        q.push(t);
        // Heapify Up
        Node *c=t;
        while(c!=root) {
            queue<Node*> f; f.push(root); Node *par=NULL;
            while(!f.empty()) {
                Node *a=f.front(); f.pop();
                if(a->left==c || a->right==c) { par=a; break; }
                if(a->left) f.push(a->left);
                if(a->right) f.push(a->right);
            }
            if(par->priority>=c->priority) break;
            swap(par->name,c->name); swap(par->id,c->id);
            swap(par->priority,c->priority); c=par;
        }
    }
    void display() {
        if(!root) return;
        queue<Node*> x; x.push(root);
        while(!x.empty()) {
            Node *a=x.front(); x.pop();
            cout<<a->name<<" ID:"<<a->id<<" Priority:"<<a->priority<<endl;
            if(a->left) x.push(a->left);
            if(a->right) x.push(a->right);
        }
    }
};

int main() {
    MaxHeap h;
    h.insert("Ali",201,4); h.insert("Sara",202,8);
    h.insert("Bilal",203,3); h.insert("Hina",204,9);
    h.insert("Usman",205,6); h.insert("Noor",206,5);
    cout<<"Hospital Patient Max Heap:"<<endl;
    h.display();
    return 0;
}