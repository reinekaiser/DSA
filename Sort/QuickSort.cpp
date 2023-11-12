#include <iostream>
#include <stdio.h>
using namespace std;

void inputArray(int* &a, int &n){
    cin >> n;
    a = new int [n];
    srand((int)time(0));
    for (int i=0; i<n; i++)
        a[i]=rand()%10000;
        //cin >> a[i];
}
void output(int *a, int n){
    for (int i=0; i<n; i++)
        cout << a[i] <<" ";
}
//sắp xếp tăng dần
void quick(int *a, int l, int r){
    int i, j , x;
    x = a[l+r/2]; // phần tử giữa mảng
    i=l; j=r; // i chạy từ đầu, j chạy từ cuối
    while (i<=j){
        while (a[i]<x) i++; // nếu a[i] < mid thì hợp lý
        while (a[j]>x) j--; // nếu a[j] > mid thì hợp lí
        // nếu không đúng với hai trường hợp trên thì thực hiện hoán vị
        if (i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l<j) quick(a,l,j); // khi j chạy chưa đến đầu mảng
    if (i<r) quick (a,i,l); // khi i chạy chưa đến cuối mảng
}
int main (){
    int n;
    int *a=NULL;
    inputArray(a,n);
    quick(a,0,n-1);
    output(a,n);
    return 0;
}

