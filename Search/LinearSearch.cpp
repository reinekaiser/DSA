#include <iostream>
using namespace std;
//O(n)
//hàm tìm kiếm tuyến tinh, trả về 1 nếu tìm thấy, trả về 0 nếu không tìm thấy 
int linear_search(int a[], int n, int x){//x: giá trị cần tìm trong mảng
    for (int i=0; i<n; i++){ //duyệt qua tất cả các phần tử trong mảng
        if (a[i]==x) return 1;
    }
    return 0;
}
//hàm tìm kiếm tuyến tính, trả về vị trí đầu tiên tìm thấy đầu tiên, nếu không thấy trả về -1
int linear_search1(int a[], int n, int x){//x: giá trị cần tìm trong mảng
    int pos=-1;
    for (int i=0; i<n; i++){ //duyệt qua tất cả các phần tử trong mảng
        if (a[i]==x){
            pos=i;// gặp vị trí đầu tiên thì dừng vòng lặp
            break;
        }
    }
    return pos;
}
//hàm tìm kiếm tuyến tính, trả về vị trí tìm thấy cuối cùng, nếu không thấy trả về -1
int linear_search2(int a[], int n, int x){//x: giá trị cần tìm trong mảng
    int pos=-1;
    for (int i=0; i<n; i++){ //duyệt qua tất cả các phần tử trong mảng
        if (a[i]==x){
            pos=i;// cáp nhật các vị trí bằng x, lưu lại vị tri cuối cùng
        }
    }
    return pos;
}
//hàm tìm kiếm tuyến tính, trả về số lần xuất hiện của phần tử x trong mảng, nếu không có trả về 0
int count_linear_search(int a[], int n, int x){
    int count=0;
    for (int i=0; i<n; i++){ //duyệt qua tất cả các phần tử trong mảng
        if (a[i]==x){
            ++count;// tăng biến đếm mỗi lần tìm thấy
        }
    }
    return count;
}
//caỉ tiến, nếu thấy trả về vị trí đầu tiên, nếu không trả về -1
int linear_search4(int a[], int n, int x){
    int i=0;
    a[n]=x;
    while(x!=a[i]) i++;
    if (i==n) return -1;
    return i;
}
int main(){
    int a[100]; 
    int n;
    cin >>n;
    int x;
    cin >>x;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int f=count_linear_search(a,n,x);
    cout <<f;
    return 0;
}