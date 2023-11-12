#include <iostream>
using namespace std;

void swap_built(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//O(n^2)
//Ý tưởng: duyệt qua tất cả các cặp giá trị trong mảng và sẽ hoán vị 2 giá trị trong cặp nếu cặp đó là nghịch thế, sau mỗi bước giá trị nhỏ nhất sẽ về đúng vị trí

//sắp xếp tăng dần, nghịch thế khi i<j và a[i]>a[j]
void interchange_sort(int a[], int n){
    for (int i=0; i<n-1; i++){// duyệt từ chỉ số 0 đến n-2
        for (int j=i+1; j<n; j++){// duyệt các phần tử sau i đến hết dãy
            if (a[i]>a[j]) swap(a[i],a[j]);
        }
    }
}

//sắp xếp giảm dần, nghịch thế khi i<j và a[i]<a[j]
void interchange_sort1(int a[], int n){
    for(int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (a[i]<a[j]) swap(a[i],a[j]);
        }
    }
}
int main (){
    int a[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    interchange_sort1(a,n);
    for (int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    return 0;
}
