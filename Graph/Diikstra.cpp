#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

class Graph{
public:
    vector<vector<int>> matrix;
    vector<string> v_list;
    map<string, int> v_index;
    
    void nhap(int v){
        string x;
        matrix = vector<vector<int>>(v, vector<int>(v,0));
        v_list = vector<string> (v, "");
        for (int i=0; i<v; i++){
            cin >> x;
            v_list[i] = x;//lưu danh sách tên
            v_index[x] = i;// ánh xạ tên->số
        }
        //nhập matran đồ thị trọng số
        for (int i=0; i<v; i++){
            for (int j=0; j<v; j++){
                cin >> matrix[i][j];
            }
        }
    }
    void findpath(string s, string g, map<string, string> con_cha, int& sum){
        vector<string> List;
        string cur = g;
        sum = 0;
        while (cur!=s){
            //cout <<"--\n";
            List.push_back(cur);
            cur = con_cha[cur];
        }
        List.push_back(cur);
//        cout << matrix[v_index[List[1]]][v_index[List[1-1]]];
        for (int i = List.size()-1; i>=1; i--){
            sum = sum + matrix[v_index[List[i]]][v_index[List[i-1]]];
        }
        for (int i = List.size()-1; i>=0; i--){
            cout <<List[i]<<" ";
        }
        cout <<endl;
    }
    void dijkstra(string s, string g, int v){
        map<string, string> con_cha;
        stack<string> open;
        vector<bool> close;
        open.push(s);
        close = vector<bool>(v, 0);
        bool f=0;
        int cnt=0;
        while (!open.empty()){
            string p = open.top();
            open.pop();
            if (p==g){
                f=1;
                cnt++;
                break;
            }
            if (close[v_index[p]]==1){
                continue;
            }
            close[v_index[p]]=1;
            cnt++;
            string q;
            for (int i=0; i<v; i++){
                if (matrix[v_index[p]][i]>0){
                    q = v_list[i];
                    if (close[i]==0){
                        open.push(q);
                        con_cha[q] = p;
                    }
                }
            }
        }
        int sum = 0;
        if (f==1) findpath(s,g,con_cha,sum);
        //cout <<"cÃ³ nÃ¨\n";
        else cout <<"-unreachable-\n";
        cout <<cnt<<" "<<sum<<endl;
    }
    
};

int main (){
    Graph G;
    int v, n;
    cin >> v >> n;
    G.nhap(v);
    string s,g;
    for (int i=0; i<n; i++){
        //cout <<"Nhap: ";
        cin >> s >> g;
        G.dijkstra(s, g, v);
    }
    return 0;
}
