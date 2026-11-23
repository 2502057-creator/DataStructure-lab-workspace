#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    string name;
    int id, expiry;
    Node *left,*right;
    Node(string n,int i,int e) {
        name=n; id=i; expiry=e; left=right=NULL;
    }
};

class MinHeap {
    Node *root;
    queue<Node*> q;
public:
    MinHeap() { root=NULL; }
    void insert(string n,int id,int e) {
        Node *t=new Node(n,id,e);
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
            if(par->expiry<=c->expiry) break;
            swap(par->name,c->name); swap(par->id,c->id);
            swap(par->expiry,c->expiry); c=par;
        }
    }
    void display() {
        if(!root) return;
        queue<Node*> x; x.push(root);
        while(!x.empty()) {
            Node *a=x.front(); x.pop();
            cout<<a->name<<" ID:"<<a->id<<" Expiry:"<<a->expiry<<endl;
            if(a->left) x.push(a->left);
            if(a->right) x.push(a->right);
        }
    }
};

int main() {
    MinHeap h;
    h.insert("Panadol",301,20270115); h.insert("Brufen",302,20261210);
    h.insert("Calpol",303,20280320); h.insert("Augmentin",304,20261125);
    h.insert("Disprin",305,20270505); h.insert("Zyrtec",306,20270218);
    cout<<"Medicine Min Heap:"<<endl;
    h.display();
    return 0;
}