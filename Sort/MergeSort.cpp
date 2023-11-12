#include <iostream>
using namespace std;

void swap_built(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//O(nlogn)
//Tư tưởng: chia không gian cần sắp xếp thành 2 không gian con
//nếu các không gian con có nhiều hơn 1 phần tử
//-> tiếp tục chia thành 2 không gian con nhỏ hơn cho đến khi các không gian con chỉ có 1 phần tử
//trộn các không gian con lại với nhau sao cho khi trộn các không gian con được sắp xếp theo thứ tự

//sắp xếp tăng dần
void merge(int a[], int l, int r, int mid){
    //mảng nhỏ 1 lưu đoạn từ l -> mid
    //mảng nhỏ 2 lưu đoạn từ mid+1 -> r
    int temp[r-l+1];// temp là mảng trộn lại của các mảng nhỏ, nghĩa là từ l -> r
    int i=l;// chỉ số bắt đầu mảng nhỏ 1
    int j=mid+1;//chỉ số bắt đầu mảng nhỏ 2
    int m=0; //chỉ số mảng temp
    
    while (i<=mid && j<=r){
        if (a[i]<a[j]) temp[m++]=a[i++]; //cái nào nhỏ hơn thì xếp vào trước
        //if (a[i]>a[j]) temp[m++]=a[i++]; //nếu sắp xếp giảm dần
        else temp[m++]=a[j++];
    }
    while (i<=mid){ //nếu hết phẩn tử trong mảng 2 mà vẫn còn phần tử trong mảng 1
        temp[m++]=a[i++];
    }
    while (j<=r){ //nếu hết phẩn tử trong mảng 1 mà vẫn còn phần tử trong mảng 2
        temp[m++]=a[j++];
    }
    //hoàn thành trộn và mảng temp đc sắp xếp
    //trả mảng temp về lại đoạn mảng a ban đầu đưa vào trộn
    for (int t=0; t<m; t++){
        a[l+t]=temp[t];
    }
}
void merge_sort(int a[], int l, int r){
    if (l>=r) return;
    int mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    merge(a,l,r,mid);
}
int main (){
    int a[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    merge_sort(a,0,n-1);
    for (int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    return 0;
}
