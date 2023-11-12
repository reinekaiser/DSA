#include <iostream>
using namespace std;
struct DNode{
    int info;
    DNode *pNext, *pPrev;
};
struct DList{
    DNode *pHead, *pTail;
};
void init(DList& L){
    L.pHead = L.pTail=NULL;
}
DNode* Dmake_node(int x){
    DNode* tmp = new DNode;
    if (tmp!=NULL){
        tmp->info=x;
        tmp->pNext=NULL;
        tmp->pPrev=NULL;
    }
    return tmp;
}
void DaddHead(DList &L, int x){
    DNode* tmp = Dmake_node(x);
    if (L.pHead==NULL) L.pHead=L.pTail=tmp;
    else {
        L.pHead->pPrev = tmp;
        tmp->pNext = L.pHead;
        L.pHead=tmp;
    }
}
void DaddTail(DList &L, int x){
    DNode* tmp = Dmake_node(x);
    if (L.pHead==NULL) L.pHead=L.pTail=tmp;
    else {
        tmp->pPrev = L.pTail;
        L.pTail->pNext=tmp;
        L.pTail=tmp;
    }
}
void createList(DList& L){
    int x;
    while(1){
        cin >> x;
        if (x==-1) return;
        DaddTail(L, x);
    }
}
void printList(DList L){
    DNode* r = L.pHead;
    if (r==NULL) {
        cout <<"List is empty";
    }
    while (r!=NULL){
        cout <<r->info << " ";
        r = r->pNext;
    }
    cout <<endl;
}
void addAfter(DList& L, int x, int y){
    DNode* r = L.pHead;
    if (L.pHead==NULL){
        cout << "\nCan't find the value "<<x;
        return;
    }
    while(r!=NULL){
        if (r->info==x) break;
        r=r->pNext;
    }
    if (r==NULL){
        cout << "\nCan't find the value "<<x;
    }
    else {
        if (r==L.pTail) DaddTail(L, y);
        else {
            DNode* tmp = Dmake_node(y);
            tmp->pPrev = r;
            tmp->pNext = r->pNext;
            r->pNext->pPrev = tmp;
            r->pNext = tmp;
        }
    }
}
void DaddAfter(DList& L, DNode* r, int x, int y){
    if (r==NULL){
        cout << "\nCan't find the value "<<x;
    }
    else {
        if (r==L.pTail) DaddTail(L, y);
        else {
            DNode* tmp = Dmake_node(y);
            tmp->pPrev = r;
            tmp->pNext = r->pNext;
            r->pNext->pPrev = tmp;
            r->pNext = tmp;
        }
    }
}
void DaddBefore(DList& L, int x, int y){
    DNode* r = L.pHead;
    if (L.pHead==NULL){
        cout << "\nCan't find the value "<<x;
        return;
    }
    if (L.pHead->info==x) {
        DaddHead(L, y);
        return;
    }
    while(r->pNext!=NULL){
        if (r->pNext->info==x) break;
        r=r->pNext;
    }
    if (r->pNext==NULL){
        cout << "\nCan't find the value "<<x;
    }
    else {
            DNode* tmp = Dmake_node(y);
            tmp->pPrev = r;
            tmp->pNext = r->pNext;
            r->pNext->pPrev = tmp;
            r->pNext = tmp;
    }
}
void DaddBefore(DList& L, DNode*& r, int x, int y){
    if (r->pNext==NULL){
        cout << "\nCan't find the value "<<x;
    }
    else {
            DNode* tmp = Dmake_node(y);
            tmp->pPrev = r;
            tmp->pNext = r->pNext;
            r->pNext->pPrev = tmp;
            r->pNext = tmp;
    }
    r=r->pNext;
}
void DaddAfterMulti(DList& L, int x, int y){
    DNode* r = L.pHead;
    if (L.pHead==NULL){
        cout << "\nCan't find the value "<<x;
        return;
    }
    bool f=0;
    while (r!=NULL){
        if (r->info==x) {
            DaddAfter(L, r, x, y);
            f=1;
        }
        r=r->pNext;
    }
    if (f==0) cout << "\nCan't find the value "<<x;
}
void DaddBeforeMulti(DList& L, int x, int y){
    DNode* r = L.pHead;
    if (L.pHead==NULL){
        cout << "\nCan't find the value "<<x;
        return;
    }
    bool f=0;
    if (L.pHead->info==x) {
        f=1;
        DaddHead(L, y);
    }
    while (r->pNext!=NULL){
        if (r->pNext->info==x) {
            DaddBefore(L, r, x, y);
            f=1;
        }
        r=r->pNext;
    }
    if (f==0) cout << "\nCan't find the value "<<x;
}
void removeHead(DList& L){
    if (L.pHead==NULL){
        cout<<"\nList is empty. Can't delete";
        return;
    }
    char c;
    cout<<"\nDo you want to delete the first element?(y/n): ";
    cin >> c;
    if (c!='y' && c!='Y') return;
    
    if (L.pHead->pNext==NULL){
        L.pHead = L.pTail = NULL;
        cout<<"\nThe list becomes empty";
        return;
    }
    DNode* tmp = L.pHead->pNext;
    tmp->pPrev = NULL;
    L.pHead = tmp;
}
void removeTail(DList& L){
    if (L.pHead==NULL){
        cout<<"\nList is empty. Can't delete";
        return;
    }
    char c;
    cout<<"\nDo you want to delete the last element?(y/n): ";
    cin >> c;
    if (c!='y' && c!='Y') return;
    
    if (L.pHead->pNext==NULL){
        L.pHead = L.pTail = NULL;
        cout<<"\nThe list becomes empty";
        return;
    }
    DNode* tmp = L.pTail->pPrev;
    tmp->pNext = NULL;
    L.pTail = tmp;
}
void removeNode(DList& L, int x){
    if (L.pHead==NULL){
        cout<<"\nList is empty. Can't delete";
        return;
    }
    DNode* r = L.pHead;
    while (r!=NULL){
        if (r->info==x) break;
        r=r->pNext;
    }
    if (r==NULL){
        cout << "\nCan't find the value "<<x;
    }
    else {
        char c;
        cout<<"\nDo you want to delete "<<x<<" ?(y/n): ";
        cin >> c;
        if (c!='y' && c!='Y') return;
        if (r==L.pHead){
            if (L.pHead->pNext==NULL){
                L.pHead = L.pTail = NULL;
                cout<<"\nThe list becomes empty";
                return;
            }
            DNode* tmp = L.pHead->pNext;
            tmp->pPrev = NULL;
            L.pHead = tmp;
        }
        else if (r==L.pTail){
            if (L.pHead->pNext==NULL){
                L.pHead = L.pTail = NULL;
                cout<<"\nThe list becomes empty";
                return;
            }
            DNode* tmp = L.pTail->pPrev;
            tmp->pNext = NULL;
            L.pTail = tmp;
        }
        else{
            r->pPrev->pNext = r->pNext;
            r->pNext->pPrev = r->pPrev;
            r->pNext = NULL;
            r->pPrev = NULL;
        }
        if (L.pHead==NULL) cout<<"\nThe list becomes empty";
    }
}
void removeNode(DList& L, DNode* r, int x){
    if (r==L.pHead){
        if (L.pHead->pNext==NULL){
            L.pHead = L.pTail = NULL;
            return;
        }
        DNode* tmp = L.pHead->pNext;
        tmp->pPrev = NULL;
        L.pHead = tmp;
    }
    else if (r==L.pTail){
        if (L.pHead->pNext==NULL){
            L.pHead = L.pTail = NULL;
            return;
        }
        DNode* tmp = L.pTail->pPrev;
        tmp->pNext = NULL;
        L.pTail = tmp;
    }
    else{
        r->pPrev->pNext = r->pNext;
        r->pNext->pPrev = r->pPrev;
        r->pNext = NULL;
        r->pPrev = NULL;
    }
}
void removeMultiNodeS(DList& L, int x){
    if (L.pHead==NULL){
        cout<<"\nList is empty. Can't delete";
        return;
    }
    bool f = 0;
    DNode* r1 = L.pHead;
    while (r1!=NULL){
        if (r1->info==x){
            f=1;
            break;
        }
        r1=r1->pNext;
    }
    if (f==0){
        cout << "\nCan't find the value "<<x;
        return;
    }
    char c;
    cout<<"\nDo you want to delete "<<x<<"s ?(y/n): ";
    cin >> c;
    if (c!='y' && c!='Y') return;
    DNode* r = L.pHead;
    while (r!=NULL){
        if (r->info == x){
            if (r==L.pHead){
                r=r->pNext;
                if (r!=NULL) r->pPrev = NULL;
                L.pHead = r;
                if (L.pHead==NULL) cout<<"\nThe list becomes empty";
                continue;
            }
            else {
                if (r==L.pTail) L.pTail = r->pPrev;
                r->pPrev->pNext = r->pNext;
                if (r->pNext!=NULL) r->pNext->pPrev = r->pPrev;
                if (L.pHead==NULL) cout<<"\nThe list becomes empty";
            }
        }
        r=r->pNext;
    }
}
void removeAfter(DList& L, int x){
    if (L.pHead==NULL){
        cout<<"\nList is empty. Can't delete";
        return;
    }
    DNode* r =L.pHead;
    while (r!=NULL){
        if (r->info==x) break;
        r=r->pNext;
    }
    if (r==NULL){
        cout << "\nCan't find the value "<<x;
        return;
    }
    if (r==L.pTail) {
        cout<<endl<<x<<" is the last element. Can't delete the element after it";
        return;
    }
    char c;
    cout<<"\nDo you want to delete the element after "<<x<<" ?(y/n): ";
    cin >> c;
    if (c!='y' && c!='Y') return;
    removeNode(L, r->pNext, x);
    if (L.pHead==NULL) cout<<"\nThe list becomes empty";
}

void removeBefore(DList& L, int x){
    if (L.pHead==NULL){
        cout<<"\nList is empty. Can't delete";
        return;
    }
    DNode* r =L.pHead;
    while (r!=NULL){
        if (r->info==x) break;
        r=r->pNext;
    }
    if (r==NULL){
        cout << "\nCan't find the value "<<x;
        return;
    }
    if (r==L.pHead) {
        cout<<endl<<x<<" is the first element. Can't delete the element before it";
        return;
    }
    char c;
    cout<<"\nDo you want to delete the element before "<<x<<" ?(y/n): ";
    cin >> c;
    if (c!='y' && c!='Y') return;
    removeNode(L, r->pPrev, x);
    if (L.pHead==NULL) cout<<"\nThe list becomes empty";
}

void removeMultiAfters(DList& L, int x){
    if (L.pHead==NULL){
        cout<<"\nList is empty. Can't delete";
        return;
    }
    bool f = 0;
    DNode* r1 = L.pHead;
    while (r1!=NULL){
        if (r1->info==x){
            f=1;
            break;
        }
        r1=r1->pNext;
    }
    if (f==0){
        cout << "\nCan't find the value "<<x;
        return;
    }
    if (L.pTail->info==x && r1==L.pTail) {
        cout<<"\nList has only one "<<x<<" and "<<x<<" is the last element. Can't delete the element after it";
        return;
    }
    char c;
    cout<<"\nDo you want to delete all elements after "<<x<<" ?(y/n): ";
    cin >> c;
    if (c!='y' && c!='Y') return;
    
    bool ff=0;
    DNode* r = L.pHead;
    while (r!=NULL){
        if (r->info==x && r!=L.pTail){
            removeNode(L, r->pNext, x);
            ff=1;
        }
        //if (ff==0 || r==L.pTail)
            r=r->pNext;
    }
}
void removeMultiBefores(DList& L, int x){
    if (L.pHead==NULL){
        cout<<"\nList is empty. Can't delete";
        return;
    }
    bool f = 0;
    DNode* r1 = L.pHead;
    while (r1!=NULL){
        if (r1->info==x){
            f=1;
            if (r1!=L.pHead) break;
        }
        r1=r1->pNext;
    }
    if (f==0){
        cout << "\nCan't find the value "<<x;
        return;
    }
    if (L.pHead->info==x && r1==NULL){
        cout<<"\nList has only one "<<x<<" and "<<x<<" is the first element. Can't delete the element before it";
        return;
    }
    char c;
    cout<<"\nDo you want to delete all elements before "<<x<<" ?(y/n): ";
    cin >> c;
    if (c!='y' && c!='Y') return;
    
    bool ff=0;
    DNode* r = L.pHead;
    while (r!=NULL){
        if (r->info==x){
            if (r!=L.pHead) removeNode(L, r->pPrev, x);
            ff=1;
        }
        //if (ff==0 || r==L.pTail)
            r=r->pNext;
    }
}
void removeAll(DList& L){
    char c;
    cout<<"\nDo you want to delete all elements?(y/n): ";
    cin >> c;
    if (c!='y' && c!='Y') return;
    L.pHead = L.pTail = NULL;
    cout<<"\nThe list becomes empty";
}

int main() {
    
}