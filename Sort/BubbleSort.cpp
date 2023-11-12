#include <iostream>
using namespace std;

void swap_built(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//O(n^2)
//Ý tưởng: duyệt qua các cặp liền kề nhau và so sánh - khác với interchange sort(các cặp không liền kề),
//trong cặp đó nếu nhẹ hơn thì nổi lên, nặng hơn thì chìm xuống.
//Nghĩa là hoán vị cặp số ngay tại đó

//sắp xếp tăng dần
void bubble_sort(int a[], int n){
    //sau mỗi vòng sẽ đưa được 1 phần tử "đúng" về cuối dãy, nghĩa là có n-1 phần tử cần sắp xếp, phần tử còn lại tự động về đúng vị trí
    //như vậy chỉ cần n-1 vòng
    for (int i=0; i<n-1; i++)//vòng cần chạy
        for (int j=0; j<n-1; j++)//vòng tiến hành so sánh 
        //(cải tiến: vì mỗi lần xong vòng này sẽ đúng thêm 1 vị trí (nghĩa là 1 phần mảng phía sau sẽ đc sắp xếp đúng), 
        //vậy vòng lặp này sẽ giảm số lần lặp)
        //for (int j=0; j<n-i-1; j++)<- cải tiến
            if (a[j]>a[j+1]) swap(a[j],a[j+1]); //so sánh 2 phần tử liền kề và hoán vị ngay tại đó
    
    
}

//sắp xếp giảm dần
void bubble_sort1(int a[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1; j++){
            if (a[j]<a[j+1]) swap(a[j],a[j+1]);
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
    bubble_sort1(a,n);
    for (int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    return 0;
}
