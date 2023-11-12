#include <iostream>
using namespace std;

void swap_built(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//O(n^2)
//Ý tưởng: duyệt qua tất cả các phần tử, và đưa về đúng vị trí của nó (in place)
//sắp xếp tăng dần, nghĩa là đưa phần tử min về đầu dãy
void seclection_sort(int a[], int n){
    for (int i=0; i<n-1; i++){
        int index_min=i; //giả sử phần tử đầu tiên là min, so sánh với các phần tử phía sau để tìm ra phần tử nhỏ nhất
        for (int j=i+1; j<n; j++){
            if(a[j]<a[index_min]) index_min=j;// tìm ra phần tử nhỏ nhất
        }
        if(index_min!=i) swap(a[i],a[index_min]);// đổi phần tử nhỏ nhất tìm được với a[i]
        //phần tử nhỏ nhất đã được tìm ra và ở đúng vị trí
    }
}

//sắp xếp giảm dần, nghĩa là đưa phần tử max về đầu dãy
void seclection_sort1(int a[], int n){
    for (int i=0; i<n-1; i++){
        int index_max=i; //giả sử phần tử đầu tiên là max
        for (int j=i+1; j<n; j++){//so sánh với các phần tử phía sau
            if (a[j]>a[index_max]) index_max=j;//tìm ra phần tử nhỏ nhất
        }
        swap(a[i],a[index_max]);
        //phần tử lớn nhất đã được đưa về đúng vị trí
    }
}
int main (){
    int a[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    seclection_sort1(a,n);
    for (int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    return 0;
}
