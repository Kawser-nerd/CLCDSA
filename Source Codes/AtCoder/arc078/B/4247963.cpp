#include <iostream>
#include <vector>

using namespace std;

vector<int> G[100000];

bool flag;
bool visited[100000];
bool fennec[100000];
bool sunuke[100000];
int cnt;

int dist_s[100000];
int dist_f[100000];

void dfs(int s, int t, int d, int dist[], bool p[]){
    //cout << s << endl;
    visited[s] = true;
    dist[s] = d;
    if(s == t) flag = true;
    if(flag){
        cnt++;
        p[s] = true;
        //cout << s << endl;
    }
    for(int i = 0; i < G[s].size();i++){
        if(!visited[G[s][i]]) dfs(G[s][i], t, d+1, dist, p);
    }
    if(s == t) flag = false;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N-1 ;i++){
        visited[i] = false;
        sunuke[i] = false;
        fennec[i] = false;
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    flag = false;
    dfs(0, N-1, 0, dist_f, sunuke);
    //int s = cnt;
    
    cnt = 0;
    for(int i = 0; i < N ;i++){
        visited[i] = false;
    }
    flag = false;
    dfs(N-1, 0, 0, dist_s, fennec);
    //int f = cnt;
    int s = 0;
    int f = 0;
    for(int i = 0; i < N; i++){
        //cout << dist_f[i] << ' ' << dist_s[i] << endl;
        if(sunuke[i]) s++;
        else if(fennec[i]) f++;
        else{
            if(dist_f[i] <= dist_s[i]) f++;
            else s++;
        }
    }
    //cout << f << ' ' << s << endl;
    if(f > s) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}