
#include <iostream>
#include <cstring>
#include <string>
#define M 10        // M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;

struct node {
    int key;
    int value;
};
struct Hash {
    node* hashtable;
    int N;
};

void initHash(Hash& H){
    H.N=0;
    H.hashtable = new node[M];
    for (int i=0; i<M; i++){
        H.hashtable[i].key = NULLKEY;
    }
}
bool isFuLL(Hash& H){
    if (H.N>M) return 1;
    return 0;
}
int hashfunc(int k){
    return k%M;
}

void insertHash(Hash& H, int k){
    H.N++;
    if (isFuLL(H)==1){
        cout <<"\nBang bam bi day, khong them duoc\n";
        return;
    }
    int i = hashfunc(k);
    int t = i;
    int r =0;
    while (H.hashtable[t].key!=NULLKEY){
        t = (i+r*r)%M;
        //if(r>=M) cout <<"Khong them duoc\n";
        r++;
    }
    H.hashtable[t].key = k;
    cout <<endl;
}
void traverseAllHash(Hash H){
    for (int i=0; i<M; i++){
        cout << i;
        if (H.hashtable[i].key!=NULLKEY)
            cout <<" --> "<<H.hashtable[i].key<<endl;
        else cout <<endl;
    }
}

int main()
{
    Hash H;
    initHash(H);

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        cout<<"\nInsert "<<x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"\nCreated Hash:"<<endl;
    traverseAllHash(H);

    return 0;
}


