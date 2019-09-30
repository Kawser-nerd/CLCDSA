#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> P;

vector<int> Gw[200000];
vector<int> Gr[200000];

P city[200000];

bool used_w[200000] = {false};
bool used_r[200000] = {false};

void dfs_w(int n, int s){
    used_w[n] = true;
    city[n].first = s;
    for(int i = 0; i < Gw[n].size(); i++){
        if(!used_w[Gw[n][i]]) dfs_w(Gw[n][i], s);
    }
}

void dfs_r(int n, int s){
    used_r[n] = true;
    city[n].second = s;
    for(int i = 0; i < Gr[n].size(); i++){
        if(!used_r[Gr[n][i]]) dfs_r(Gr[n][i], s);
    }
}


int main(){
    int N, K, L;
    cin >> N >> K >> L;
    map<P, int> m;
    for(int i = 0; i < K; i++){
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        Gw[p].push_back(q);
        Gw[q].push_back(p);
    }
    for(int i = 0; i < L; i++){
        int r, s;
        cin >> r >> s;
        r--;
        s--;
        Gr[r].push_back(s);
        Gr[s].push_back(r);
    }
    for(int i = 0; i < N; i++){
        if(!used_r[i]){
            dfs_r(i, i);
        }
        if(!used_w[i]){
            dfs_w(i, i);
        }

        if(m.count(city[i]) == 0){
            m[city[i]] = 1;
        }else{
            m[city[i]]++;
        }
    }
    for(int i = 0; i < N; i++){
        cout << m[city[i]];
        if(i < N-1) cout << ' ';
        else cout << endl;
    }
}