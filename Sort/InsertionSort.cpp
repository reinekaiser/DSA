#include <iostream>
using namespace std;

void swap_built(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//O(n^2)
//Tư tưởng: giả sử mảng đã được sắp xếp 1 phần trước đó ; ta chỉ cần thêm phần tử chưa được sắp xếp vào phần đã được sắp xếp trước đó; 
//sao cho sau khi thêm thì phần mới vẫn được sắp xếp
//Ý tưởng: lấy phần tử thứ i lần lượt so sánh với phần tử trước đó, rồi chèn vào đúng vị trí

//sắp xếp tăng dần
void insertion_sort(int a[], int n){
    for (int i=1; i<n; i++){//coi a[0] là phần đã được sắp xếp trước đó, bắt đầu chay với i=1
        int x=a[i];// coi x là phần tử cần chèn
        int j;
        for ( j=i-1; j>=0 && x<a[j]; j--){//duyệt các phần tử trước i
            a[j+1]=a[j];//nếu lớn hơn x thì dời về sau 1 vị trí
        }//nếu a[j] nhỏ hơn hoặc bằng thì dừng lặp
        a[j+1]=x;// chèn x vào vị trí sau đó vì j đang ở phần tử nhỏ hơn hoặc bằng
    }
}

//sắp xếp giảm dần
void insertion_sort1(int a[], int n){
    for (int i=1; i<n; i++){
        int x=a[i];
        int j;
        for (j=i-1; j>=0 && x>a[j]; j--){
            a[j+1]=a[j];
        }
        a[j+1]=x;
    }
}

void binary_inser_sort(int a[], int n){
    for (int i=1; i<n; i++){
        int x= a[i];
        int l=0; int r=i-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (x<a[mid]) r=mid-1;// tìm bên trái mảng
            else l=mid+1;// tìm bên phải mảng
        }
        // khi vòng lặp trên dừng, l đang ở vị trí mà cần chèn x vào
        for (int j=i-1; j>=l;j--){// dời mảng ra sau đến phần tư a[l]
            a[j+1]=a[j];
        }
        a[l]=x;// dời xong, gán x vào đúng vị trí
    }
}
int main (){
    int a[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    insertion_sort1(a,n);
    for (int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    return 0;
}