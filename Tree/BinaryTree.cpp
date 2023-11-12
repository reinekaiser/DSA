#include <iostream>
using namespace std;
struct TNode{
    int info;
    TNode* left;
    TNode* right;
};
typedef TNode* Tree;

Tree makeNode(int x){
    Tree tmp = new TNode;
    if (tmp!=NULL){
        tmp->info=x;
        tmp->left=NULL;
        tmp->right=NULL;
    }
    return tmp;
}
void insert_intoTree(Tree& T, int x){
    if (T!=NULL){
        //tìm vị trí phù hợp
        if (x==T->info) return; //vị trí bị trùng, ko thêm nữa
        else if (x<T->info)
            insert_intoTree(T->left,x);//tìm bên trái
        else insert_intoTree(T->right,x);//tìm bên phải
    }
    else {//T lúc này ở vị trí NULL
        T = makeNode(x);
    }
}
void inputTree(Tree& T){
    int x,n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x;
        insert_intoTree(T,x);
    }
    
}
void LNR(Tree T){
    if (T!=NULL){
        LNR(T->left);
        cout <<T->info<<" ";
        LNR(T->right);
    }
}
void RNL(Tree T){
    if (T!=NULL){
        LNR(T->right);
        cout <<T->info<<" ";
        LNR(T->left);
    }
}
void LRN(Tree T){
    if (T!=NULL){
        LRN(T->left);
        LRN(T->right);
        cout <<T->info<<" ";
    }
}
void RLN(Tree T){
    if (T!=NULL){
        LRN(T->right);
        LRN(T->left);
        cout <<T->info<<" ";
    }
}
void NLR(Tree T){
    if (T!=NULL){
        cout <<T->info<<" ";
        NLR(T->left);
        NLR(T->right);
    }
}
void NRL(Tree T){
    if (T!=NULL){
        cout <<T->info<<" ";
        NLR(T->right);
        NLR(T->left);
    }
}
void listLeafs(Tree T){
    if (T!=NULL){
        //node lá có 2 nhánh là null
        if (T->right == NULL && T->left == NULL) cout <<T->info<<" ";
        else {
            listLeafs(T->left);
            listLeafs(T->right);
        }
    }
}
void listInternalNodes(Tree T, int x){
    if (T!=NULL){
        //node trung gian có ít nhất 1 con khác root
        if ((T->left!=NULL || T->right!=NULL) && x!=0){
            cout <<T->info<<" ";
        }
        listInternalNodes(T->left,1);
        listInternalNodes(T->right,1);
    }
}

void listNodesWithOneChild(Tree T){
    if (T!=NULL){
        //node 1 con
        if ((T->right == NULL && T->left != NULL) || (T->right != NULL && T->left == NULL)){
            cout <<T->info<<" ";
        }
        listNodesWithOneChild(T->left);
        listNodesWithOneChild(T->right);
    }
}

void listNodesWithTwoChildren(Tree T){
    if (T!=NULL){
        //node 2 con
        if (T->right != NULL && T->left != NULL)
            cout <<T->info<<" ";
        listNodesWithTwoChildren(T->left);
        listNodesWithTwoChildren(T->right);
    }
}
int countNodes(Tree T){
    if (T == NULL) return 0;
    return 1+countNodes(T->left)+countNodes(T->right);
}
void countNode(Tree T, int& cnt){
    if (T!=NULL){
        cnt++;
        countNode(T->left, cnt);
        countNode(T->right, cnt);
    }
}
int countLeafs(Tree T){
    if (T==NULL) return 0;
    if(T->left == NULL && T->right == NULL)
        return 1;
    return countLeafs(T->left)+countLeafs(T->right);
}
void cLeafs(Tree T, int& cnt){
    if (T!=NULL){
        if (T->left==NULL && T->right==NULL)
            cnt++;
        cLeafs(T->left, cnt);
        cLeafs(T->right, cnt);
    }
}
int cInternalNodes(Tree T){
    if (T == NULL) {
        return 0;
    }
    if ((T->left!=NULL || T->right!=NULL)) {
        return cInternalNodes(T->left) + cInternalNodes(T->right) + 1;
    }
    return cInternalNodes(T->left) + cInternalNodes(T->right);
}
int countInternalNodes(Tree T){
    int x= cInternalNodes(T)-1;
    if (x<0) return 0;
    return x;
}
void cntInternalNodes(Tree T, int& cnt, bool f){
    if(T!=NULL){
        if ((T->left!=NULL || T->right!=NULL) && f==1){
            cnt++;
        }
        cntInternalNodes(T->left, cnt, 1);
        cntInternalNodes(T->right, cnt, 1);
    }
}
int countOneChild(Tree T){
    if (T == NULL) {
        return 0;
    }
    if ((T->right == NULL && T->left != NULL) || (T->right != NULL && T->left == NULL)) {
        return countOneChild(T->left) + countOneChild(T->right) + 1;
    }
    return countOneChild(T->left) + countOneChild(T->right);
}
int countTwoChildren(Tree T){
    if (T == NULL) {
        return 0;
    }
    if (T->left != NULL && T->right != NULL) {
        return countTwoChildren(T->left) + countTwoChildren(T->right) + 1;
    }
    return countTwoChildren(T->left) + countTwoChildren(T->right);
}

int countLess(Tree T, int x){
    if (T == NULL) {
        return 0;
    }
    if (T->info < x) {
        return countLess(T->left, x) + countLess(T->right, x) + 1;
    }
    return countLess(T->left, x);
}
int countBetweenValues(TNode* T, int x, int y) {
    if (T == NULL) {
        return 0;
    }
    if (T->info > x && T->info < y) {
        return countBetweenValues(T->left, x, y) + countBetweenValues(T->right, x, y) + 1;
    }
    return countBetweenValues(T->left, x, y) + countBetweenValues(T->right, x, y);
}
int countOneRight(Tree T){
    if (T==NULL) return 0;
    if (T->left==NULL && T->right!=NULL){
        return countOneRight(T->left) + countOneRight(T->right) + 1;
    }
    return countOneRight(T->left) + countOneRight(T->right);
}
TNode* Search(Tree T, int x){
    TNode* r = T;
    while(r!=NULL){
        if (r->info==x) return r;
        else if (x<r->info) r = r->left;
        else if (x>r->info) r=r->right;
    }
    return NULL;
}
int min_est_Value(Tree T){
    if (T->left==NULL){
        return T->info;
    }
    return min_est_Value(T->left);
}
int max_est_Value(Tree T){
    if (T->right==NULL){
        return T->info;
    }
    return max_est_Value(T->right);
}
int depthOfTree(Tree T){
    if (T==NULL) return -1;
    return 1+ max(depthOfTree(T->left), depthOfTree(T->right));
}

bool isAVL(Tree T){
    if (T==NULL) return 1;
    if (depthOfTree(T->left)-depthOfTree(T->right)!=1 && depthOfTree(T->left)-depthOfTree(T->right)!=0 && depthOfTree(T->left)-depthOfTree(T->right)!=-1) return false;
    return isAVL(T->left)&&isAVL(T->right);
}
void rotateLeft(Tree &T){
    if (T==NULL) cout<< "\nKhong the xoay vi cay rong";
    if (T->right==NULL) cout<< "\nKhong the xoay trai vi khong co nut con ben phai";
    else {
        TNode* p = T->right;
        TNode* tmp = p->left;
        T->right = tmp;
        p->left = T;
        T=p;
    }
}
Tree rotateRight(Tree T){
    if (T==NULL) cout<< "\nKhong the xoay vi cay rong";
    else if (T->left==NULL) cout<< "\nKhong the xoay phai vi khong co nut con ben trai";
    else {
        TNode* p = T->left;
        TNode* tmp = p->right;
        T->left = tmp;
        p->right = T;
        T=p;
        return T;
    }
    return T;
}
void replace(Tree &X, Tree &Y){
    if (Y->left != NULL){
        replace(X, Y->left);
    }
    else{
        X->info = Y->info;
        X = Y;
        Y = Y->right;
    }
}
void deleteNode(Tree &t, int data){
   //trái nhất cây con phải
    if (t == NULL){
        return;
    }
    else{
        if (data < t->info){
            deleteNode(t->left, data);
        }
        else if (data > t->info){
            deleteNode(t->right, data);
        }
        else{
            TNode* X = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            else
                replace(X, t->right);
            delete X;
        }
    }
}
void replace1(Tree &X, Tree &Y){
    if (Y->right != NULL){
        replace1(X, Y->right);
    }
    else{
        X->info = Y->info;
        X = Y;
        Y = Y->left;
    }
}
void deleteNode1(Tree &t, int data){
   //phải nhất cây con trái
    if (t == NULL){
        return;
    }
    else{
        if (data < t->info){
            deleteNode1(t->left, data);
        }
        else if (data > t->info){
            deleteNode1(t->right, data);
        }
        else{
            TNode* X = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            else
                replace1(X, t->left);
            delete X;
        }
    }
}

bool isLeaf(TNode* T){
    if (T->left==NULL && T->right==NULL) return 1;
    return 0;
}
bool checkBST(TNode* T, int minValue, int maxValue) {
    if (T == NULL) {
        return true;
    }
    if (T->info < minValue || T->info > maxValue) {
        return false;
    }
    return checkBST(T->left, minValue, T->info - 1) && checkBST(T->right, T->info + 1, maxValue);
}

bool isBST(TNode* root) {
    return checkBST(root, -100000, 10000);
}

int isFullBinaryTree(Tree T){
    if (T == NULL) {
            return 1;
    }
    if (T->left == NULL && T->right == NULL) {
        return 1;
    }
    if (T->left != NULL && T->right != NULL) {
        return isFullBinaryTree(T->left) && isFullBinaryTree(T->right);
    }
    return 0;
}
int isCompleteBinaryTree(Tree T){
    if (T==NULL) return 1;
    if (depthOfTree(T->left)-depthOfTree(T->right)!=0) return 0;
    return isCompleteBinaryTree(T->left)&&isCompleteBinaryTree(T->right);
}

Tree removeLeafs(Tree T){
    if (T!=NULL){
        if (T->left==NULL && T->right==NULL){
            delete T;
            return NULL;
        }
        else {
            T->left = removeLeafs(T->left);
            T->right = removeLeafs(T->right);
        }
    }
    return T;
}
void printLevelK(Tree T, int k){
    if (T==NULL) return;
    if (k==0){
        cout <<T->info<<" ";
    }
    else {
        printLevelK(T->left,k-1);
        printLevelK(T->right, k-1);
    }
}
void depthOfNode(Tree T, int& d, int x){
    TNode* r = T;
    while (r!=NULL){
        if (r->info==x) return;
        else if (x<r->info){
            r=r->left;
        }
        else r=r->right;
        d++;
    }
}

int main() {
    
}