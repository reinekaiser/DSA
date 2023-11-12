#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

struct Canh{
    int dinh_dau;
    int dinh_cuoi;
};
// ma trận kề
void nhap_matranke(int** &a, int dinh){
    a = new int*[dinh];
    for (int i=0; i<dinh; i++){
        a[i] = new int[dinh];
    }
    cout <<"Nhap ma tran \n";
    for (int i=0; i<dinh; i++)
        for (int j=0; j<dinh; j++)
            cin >> a[i][j];
}
void xuat_matranke(int** a, int dinh){
    for (int i=0; i<dinh; i++){
        for (int j=0; j<dinh; j++)
            cout << a[i][j] <<" ";
        cout << endl;
    }
}
void MTKtoDSC(int** a, int sodinh, int socanh){
    //vô hướng
    Canh* dsc = new Canh[socanh];
    int k=0;
    for (int i=0; i<sodinh; i++){
        for (int j=0; j<sodinh; j++){
            if (a[i][j]==1 && i<j){
                dsc[k].dinh_dau = i+1;
                dsc[k].dinh_cuoi = j+1;
                k++;
            }
        }
    }
    for (int i=0; i<socanh; i++){
        cout <<dsc[i].dinh_dau<<" "<<dsc[i].dinh_cuoi<<endl;
    }
}
void MTKtoDSK(int** a, int sodinh, int socanh){
    //vô hướng
    vector<vector<int>> dsk(sodinh);
    for (int i=0; i<sodinh; i++){
        for (int j=0; j<sodinh; j++){
            if (a[i][j]==1){
                dsk[i].push_back(j+1);
            }
        }
    }
    for (int i=0; i<sodinh; i++){
        cout <<i+1<<": ";
        for (auto x : dsk[i])
            cout <<x<<" ";
        cout <<endl;
    }
}

//danh sách cạnh
void nhap_danhSachCanh(Canh* &c, int &socanh){
    c = new Canh[socanh];
    cout <<"Nhap danh sach canh: \n";
    for (int i=0; i<socanh; i++){
        cin >> c[i].dinh_dau;
        cin >> c[i].dinh_cuoi;
    }
}
void xuat_danhSachCanh(Canh* c, int socanh){
    for (int i=0; i<socanh; i++){
        cout << c[i].dinh_dau <<" "<<c[i].dinh_cuoi<<endl;
    }
}

void DSCtoMTK(Canh* a, int sodinh, int socanh){
    //vô hướng
    int** matrix = new int*[sodinh];
    for (int i=0; i<sodinh; i++){
        matrix[i] = new int[sodinh];
    }
    for (int i=0; i<sodinh; i++)
        for (int j=0; j<sodinh; j++)
            matrix[i][j] = 0;
     
    for (int i=0; i<socanh; i++){
        matrix[a[i].dinh_dau-1][a[i].dinh_cuoi-1] = matrix[a[i].dinh_cuoi-1][a[i].dinh_dau-1] = 1;
    }
    
    for (int i=0; i<sodinh; i++){
        for (int j=0; j<sodinh; j++)
            cout << matrix[i][j] <<" ";
        cout << endl;
    }
}
void DSCtoDSK(Canh* a, int sodinh, int socanh){
    //vô hướng
    vector<vector<int>> dsk(sodinh);
    for (int i=0; i<socanh; i++){
        dsk[a[i].dinh_dau-1].push_back(a[i].dinh_cuoi);
        dsk[a[i].dinh_cuoi-1].push_back(a[i].dinh_dau);
    }
    for (int i=0; i<sodinh; i++){
        cout <<i+1<<": ";
        for (auto x : dsk[i])
            cout <<x<<" ";
        cout <<endl;
    }
}
// danh sách kề
void DSKtoMTK(int sodinh, int socanh){
    //vô hướng
    int** matrix = new int*[sodinh];
    for (int i=0; i<sodinh; i++){
        matrix[i] = new int[sodinh];
    }
    for (int i=0; i<sodinh; i++)
        for (int j=0; j<sodinh; j++)
            matrix[i][j] = 0;
    
    cin.ignore();
    for (int i=0; i<sodinh; i++){
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss>>num){
            matrix[i][stoi(num)-1] = 1;
        }
    }
    for (int i=0; i<sodinh; i++){
        for (int j=0; j<sodinh; j++)
            cout << matrix[i][j] <<" ";
        cout << endl;
    }
}
void DSKtoDSC(int sodinh, int socanh){
    //vô hướng
    Canh* dsc = new Canh[socanh];
    cin.ignore();
    int k=0;
    for (int i=0; i<sodinh; i++){
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss>>num){
            if (i<stoi(num)-1) dsc[k++] = {i+1, stoi(num)};
        }
    }
    for (int i=0; i<socanh; i++){
        cout <<dsc[i].dinh_dau<<" "<<dsc[i].dinh_cuoi<<endl;
    }
}


class Graph{
public:
    vector<vector<int>> matrix; //ma tran ke trong so
    vector<string> v_list; //danh sach ten dinh
    map<string, int> v_index; // anh xa ten dinh ten -> index
    
    void nhap(int v){
        matrix = vector<vector<int>>(v, vector<int>(v,0));
        string t;
        // nhap danh sach ten dinh
        for (int i=0; i<v; i++){
            cin >> t;
            v_list.push_back(t);
            v_index[t] = i;
        }
        // nhap ma tran trong so
        for (int i=0; i<v; i++){
            for (int j=0; j<v; j++){
                cin >> matrix[i][j];
            }
        }
    }
    void printpath(string s, string g, map<string, string> parent, int& sum){
        vector<string> path;
        string cur = g;
        while (cur!=s){
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(cur);
        for (int i = path.size()-1; i>=1; i--){
            sum = sum + matrix[v_index[path[i]]][v_index[path[i-1]]];
        }
        for (int i = path.size()-1; i>=0; i--){
            cout <<path[i]<<" ";
        }
        cout <<endl;
    }
    void dfs(int v, string s, string g){
        bool found = 0; // chua thay duong di tu s->g
        int count=0;
        stack<string> open;
        vector<bool> close(v,0);
        map<string, string> parent;
        // them dinh bat dau vao ds xet
        open.push(s);
        while (!open.empty()){
            string p = open.top();
            open.pop();
            if (p==g){
                found = 1; // thay duong di tu s->g
                count++;
                break;
            }
            if (close[v_index[p]]==1) continue; // neu dinh da xet thi ko xet lai
            close[v_index[p]]=1; // danh dau dc xet
            count++;
            string q;
            // tim cac dinh ke voi p
            for (int i=0; i<v; i++){
                if (matrix[v_index[p]][i]>0){
                    q = v_list[i];
                    if (close[i]==0){// neu chua dc xet thi them vao open
                        open.push(q);
                        parent[q] = p; // cha cua q la p
                    }
                }
            }
        }
        int sum =0;
        if (found==1) printpath(s, g, parent,sum);
        else cout <<"-unreachable-\n";
        cout <<count<<" "<<sum<<endl;
    }
    void bfs(int v, string s, string g){
        int count = 0;
        bool found = 0;
        queue<string> open;
        map<string, bool> inopen; //luu tru trang thai cac dinh co trong open
        vector<bool> close(v,0);
        map<string, string> parent;
        //them dinh dau tien vao ds xet
        open.push(s);
        while(!open.empty()){
            string p = open.front();
            open.pop();
            inopen[p] = 0; //xoa p ra khoi open
            if (p==g){ // tim thay duong di
                found=1;
                count++;
                break;
            }
            if (close[v_index[p]]==1) continue;
            close[v_index[p]]=1; //them dinh p vao close
            count++;
            // tim cac dinh ke voi p
            string q;
            for (int i=0; i<v; i++){
                q = v_list[i];
                if (matrix[v_index[p]][i]>0){
                    if (close[i]==0){
                        if (inopen[q]==1) continue;// co trong open thi ko them lai
                        open.push(q);
                        inopen[q] = 1; //q co trong open
                        parent[q] = p;
                    }
                }
            }
        }
        int sum=0;
        if (found==1) printpath(s, g, parent, sum);
        else cout <<"-unreachable-\n";
        cout <<count<<" "<<sum<<endl;
    }
    
};

//int main (){
//    Graph G;
//    int v, n;
//    cin >> v >> n;
//    G.nhap(v);
//    string s, g;
//    for (int i=0; i<n; i++){
//        cin >> s >> g;
//        G.bfs(v, s, g);
//    }
//    return 0;
//}

int main(){
    map<string, set<pair<string, int>>> G;
    int e;
    cin >> e;
    string u, v;
    int w;
    for (int i=0; i<e; i++){
        cin >> u >> v >> w;
        G[u].insert({v,w});
    }
    for (auto x : G){
        cout <<x.first<<"->";
        for (auto y : x.second){
            cout <<"("<<y.first<<", "<<y.second<<")";
        }
        cout<<endl;
    }
    
    map<string, map<string, int>> g;
    for (int i=0; i<e; i++){
        cin >> u >> v >> w;
        g[u][v] = w;
    }
    for (auto x : g){
        cout <<x.first<<"->"<<endl;
        for (auto y : x.second){
            cout <<y.first<<"->"<<y.second<<endl;
        }
    }
}
