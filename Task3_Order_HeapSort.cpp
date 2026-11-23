#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int a[], int n, int i) {
    int big=i, l=2*i+1, r=2*i+2;
    if(l<n && a[l]>a[big]) big=l;
    if(r<n && a[r]>a[big]) big=r;
    if(big!=i) {
        swap(a[i],a[big]);
        heapify(a,n,big);
    }
}

int main() {
    int amount[6]={2500,1200,4300,1800,3200,900};
    int n=6;
    cout<<"Order amounts:"<<endl;
    for(int i=0;i<n;i++) cout<<amount[i]<<" ";
    for(int i=n/2-1;i>=0;i--) heapify(amount,n,i);
    for(int i=n-1;i>0;i--) {
        swap(amount[0],amount[i]);
        heapify(amount,i,0);
    }
    cout<<"\nSorted amounts (ascending):"<<endl;
    for(int i=0;i<n;i++) cout<<amount[i]<<" ";
    cout<<endl;
    return 0;
}