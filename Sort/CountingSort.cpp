#include <iostream>
using namespace std;

void swap_built(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//O(n^2)
//Ý tưởng: Đếm số lần xuất hiện của 1 phần tử và lưu vào một mảng count.
//Thay đổi mảng count theo công thức count[i] = count[i] + count[i-1]
//lúc này mảng count sẽ lưu vị trí đúng của các phần tử (vị trí đúng = count[]-1)

//sắp xếp tăng dần
void countingSort(int a[], int n){
    //tìm max và min
    int max=a[0];
    int min=a[0];
    for (int i=1; i<n; i++){
        if (a[i]>max) max=a[i];
        if (a[i]<min) min=a[i];
    }
    // xác định phạm vi giá trị và tạo mảng có số phần tử bằng phạm vi đó để đếm
    int range = max - min + 1;
    int *count;
    count = new int[range];
    for (int i=0; i<range; i++){
        count[i] = 0;
    }
    // đếm số lần xuất hiện của mỗi phần tử
    for (int i=0; i<n; i++){
        ++count[a[i]-min];
    }
    //thay đổi mảng count
    for (int i=0; i<range; i++){
        count[i] = count[i] + count[i-1];
    }
    // lưu mảng a được sắp xếp vào tmp
    int* tmp = new int[n];
    for (int i=0; i<n; i++){
        tmp[count[a[i]-min]-1]=a[i];
        --count[a[i]-min];
    }
    //trả về mảng a
    for (int i = 0; i<n ; ++i)
        a[i] = tmp[i];
    delete[] tmp;
    delete[] count;
}

int main (){
    int a[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    countingSort(a,n);
    cout <<endl;
    for (int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    return 0;
}

