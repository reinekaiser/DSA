#include <iostream>
using namespace std;
//O(log n)
//mảng phải được sắp xếp thì mới tìm kiếm nhin phân được
//Ý tưởng: so sánh x với phần tử giữa mảng
//nếu bằng thì return, nêu x>a[mid] thì tìm kiém bên phải mid, nếu x<a[mid] thì tìm kiếm bên trái mid

//trả về 1 nếu tìm thấy, trả về 0 nếu ko tìm thấy(mảng tăng dần)
int binary_search(int a[], int n, int x){
    int l=0;
    int r=n-1;
    int mid;
    while (l<=r){
        mid=(l+r)/2;// vị trí giữa mảng
        if (x==a[mid]) return 1;// tìm thấy
        else if (x<a[mid]) r=mid-1;// tìm bên trái mảng
        else l=mid+1;// tìm bên phải mảng
    }
    return 0;
}
//trả về 1 nếu tìm thấy, trả về 0 nếu ko tìm thấy(mảng giảm dần)
int binary_search2(int a[], int n, int x){
    int l=0;
    int r=n-1;
    int mid;
    while (l<=r){
        mid=(l+r)/2;// vị trí giữa mảng
        if (x==a[mid]) return 1;// tìm thấy
        else if (x>a[mid]) r=mid-1;// tìm bên trái mảng
        else l=mid+1;// tìm bên phải mảng
    }
    return 0;
}
// dùng đệ quy
int binary_search_rec(int a[], int l, int r, int x){
    if (l>r) return 0;// không tìm thấy
    int mid=(l+r)/2;// vị trí giữa mảng
    if (x==a[mid]) return 1;// tìm thấy
    else if (x<a[mid]) return binary_search_rec(a,l,mid-1,x);// tìm bên trái mảng
         else return binary_search_rec(a,mid+1,r,x);// tìm bên phải mảng
}

int main (){
    int a[100];
    int n;
    cin>>n;
    int x;
    cin>>x;
    for (int i=0; i<n; i++){
        cin >>a[i];
    }
    //cout << binary_search(a,n,x);
    //cout << binary_search2(a,n,x);
    return 0;
}
