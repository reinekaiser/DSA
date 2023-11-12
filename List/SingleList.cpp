#include <iostream>
using namespace std;
struct Node{
    int info;
    Node* next;
};
struct List{
    Node* head;
    Node* tail;
};

typedef struct Node* node;

void Init(List &L){
    L.head = L.tail = NULL;
}
node make_node(int x){
    node tmp = new Node;
    if (tmp!=NULL){
        tmp->info = x;
        tmp->next = NULL;
    }
    return tmp;
}
void add_head(List& L, int x){
    node tmp = make_node(x);
    if (L.head==NULL){
        L.head=L.tail=tmp;
        return;
    }
    else{
        tmp->next = L.head;
        L.head = tmp;
    }
}
void add_tail(List& L, int x){
    node tmp = make_node(x);
    if (L.head == NULL)
        L.head = L.tail = tmp;
    else{
        L.tail->next = tmp;
        L.tail = tmp;
    }
}
void add_after(List& L, int a, int b){
    if (L.head==NULL){
        return;
    }
    node r = L.head;
    while (r!=NULL){
        if (r->info==a) break;
        r = r->next;
    }
    if (r==NULL){
        add_head(L, b);
        return;
    }
    else if (r!=NULL){
        if (r==L.tail){
            add_tail(L, b);
            return;
        }
        node tmp = make_node(b);
        tmp->next = r->next;
        r->next = tmp;
    }
}
void del_head(List& L){
    if (L.head == NULL) return ;
    node tmp = L.head;
    L.head = tmp->next;
    tmp->next = NULL;
    delete tmp;
    if (L.head==NULL) L.tail=NULL;
}
void del_tail(List& L){
    if (L.head==NULL) return;
    node prev_r = NULL;
    node r = L.head;
    while (r->next != NULL){
        prev_r = r;
        r = r->next;
    }
    if (prev_r==NULL) L.head=L.tail=NULL;
    else {
        prev_r->next = NULL;
        L.tail = prev_r;
    }
}
void del_x(List& L, int x){
    if (L.head == NULL) return;
    if (L.head->info==x) {
        del_head(L);
        return;
    }
    node r = L.head;
    node prev_r = NULL;
    while (r!=NULL){
        if (r->info==x) break;
        prev_r = r;
        r = r->next;
    }
    if (r==NULL) return;
    if (r!=NULL){
        if (r==L.tail){
            del_tail(L);
            return;
        }
        prev_r->next = r->next;
        r->next = NULL;
    }
}
void del_all_x(List& L, int x){
    if (L.head==NULL) return;
    node r = L.head;
    node prev_r = NULL;
    while (r!=NULL){
        if (r->info==x) {
            if (r==L.head){
                L.head = L.head->next;
                r = L.head;
                continue;
            }
            else{
                node tmp = r;
                if (r==L.tail) L.tail = prev_r;
                prev_r->next = tmp->next;
                tmp->next = NULL;
                delete tmp;
                r = prev_r;
                continue;
            }
        }
        prev_r = r;
        r = r->next;
    }
}
void inputList(List& L, int n){
    int x;
    for (int i=0; i<n; i++){
        cin >> x;
        add_tail(L, x);
    }
}
void outputList(List L){
    node r = L.head;
    if (L.head == NULL){
        cout <<"List is empty";
        return;
    }
    while (r != NULL){
        cout <<r->info<<" ";
        r = r->next;
    }
}
void moveLastToFront(List& L){
    if (L.head==NULL || L.head->next==NULL) return;
    node r = L.head;
    node prev_r = NULL;
    while (r!=L.tail){
        prev_r = r;
        r = r->next;
    }
    r->next=L.head;
    L.head = r;
    prev_r->next = NULL;
    L.tail = prev_r;
}
int size_list(List L){
    node r = L.head;
    int size=0;
    while (r!=NULL){
        size++;
        r=r->next;
    }
    return size;
}
node findMiddle(List L){
    int s = size_list(L);
    int pos = (s/2)+1;
    int cnt = 0;
    node r = L.head;
    while (r!=NULL){
        cnt++;
        if (cnt==pos) return r;
        r = r->next;
    }
    return r;
}
//nối L2 vào sau L1
void concate(List& L1, List L2){
    if (L2.head==NULL) return;
    if (L1.head==NULL) {
        L1 = L2;
        return;
    }
    L1.tail->next=L2.head;
    L1.tail = L2.tail;
}
node swapData(List& L, int x, int y){
    if (L.head==NULL) return NULL;
    node r = L.head;
    while (r!=NULL){
        if (r->info == x) break;
        r = r->next;
    }
    node r2 = L.head;
    while (r2!=NULL){
        if (r2->info==y) break;
        r2 = r2->next;
    }
    if (r!=NULL && r2!=NULL){
        int tmp;
        tmp = r->info;
        r->info = r2->info;
        r2->info = tmp;
    }
    else return NULL;
    return r;
}
int MySearch(List L, int x){
    int pos=-1;
    node r = L.head;
    while (r!=NULL){
        pos++;
        if (r->info==x) break;
        r=r->next;
    }
    if (r==NULL) pos=-1;
    return pos;
}
void MySeclecSort(List& L){
    for (node i = L.head; i->next!=NULL; i=i->next){
        int min = i->info;
        node j; node p = NULL;
        for ( j = i->next; j!=NULL; j=j->next){
            if (j->info<min) {
                min = j->info;
                p = j;
            }
        }
        if (i->info!=min){
            int tmp = i->info;
            i->info = p->info;
            p->info = tmp;
        }
            
    }
}

int main() {

}