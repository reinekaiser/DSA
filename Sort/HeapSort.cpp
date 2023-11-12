#include <iostream>
using namespace std;

//O(nlogn)
//Xây dựng một max heap(phần tử gốc lớn hơn phần tử nhánh) từ một cây nhị phân hoàn chỉnh (Complete binary tree)
//Ở max heap, phần tử lớn nhất mảng nằm ở gốc (root).
//Hoán vị phần tử lớn nhất đó với phần tử cuối mảng, ta có được vị trí đúng của phần tử lớn nhất.
//Vì nó đúng vị trí nên không xét nữa, giảm bớt 1 phần tử trong mảng để xét tiếp. Heapify mảng vừa giảm phần tử đó.
//lặp lại cho đến khi không còn phần tử để xét, nghĩa là tiếp tục heapify khi phần tử mảng cần xét lớn hơn 1
//vị trí nhánh trái của gốc i : i*2+1
//vị trí nhánh phải của gốc i : i*2+2

void heapify(int a[], int n, int i){
    int largest = i;// giả sử gốc i là phần tử lớn hơn so với 2 nhánh
    int l = 2*i + 1; // nhánh trái của i
    int r = 2*i + 2; // nhánh phải của i
    // nếu vị trí l chưa thoát khỏi mảng và a[l](nhánh trái) > a[largest] (gốc) thì largest = l;
    if (l<n && a[l]>a[largest]) largest = l; // mảng giảm dần a[l]<a[largest]
    // nếu vị trí r chưa thoát khỏi mảng và a[r](nhánh phải) > a[largest] (gốc) thì largest = r;
    if (r<n && a[r]>a[largest]) largest = r;// mảng giảm dần a[r]<a[largest]
    // nếu largest khác i ban đầu nghĩa là vị trí phần tử lớn nhất bị thay đổi, hoán vị chúng
    // nếu không bị thang đổi nghĩa là i đúng là vị trí phần tử lớn nhất, lúc đó ko cần hoán vị
    if (largest != i){
        swap (a[i], a[largest]);
        heapify(a,n,largest); // tiếp tục heapify để đưa phần tử lớn hơn về gốc
    }
}
//mảng tăng dần
void heap_sort(int a[], int n){
    //xây dựng max heap
    for (int i = n/2 - 1; i>=0; i--){// chạy từ phần tử khác nhánh lá
        heapify(a,n,i);
    }
    //heap sort
    for (int i=n-1; i>=0; i--){
        swap(a[0], a[i]); // hoán vị phần tử đầu tiên (đã đc xây max heap) về cuối, phần tử lớn nhất mảng đẫ đúng vị trí
        heapify(a,i,0);// heapify mảng đã đã giảm đi 1 phần tử đã đúng vị trí
    }
}
int main(){
    int a[100]; int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    heap_sort(a,n);
    for(int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
}
