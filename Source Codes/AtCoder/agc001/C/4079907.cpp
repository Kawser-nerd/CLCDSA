#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> P;

int N, K;
vector<int> G[2001];
int depth[2001];
P edge[2000];

void clear_depth(){
    for(int i = 1; i<= N; i++){
        depth[i] = -1;
    }
}

void dfs1(int n, int d){
    depth[n] = d;
    for(int i = 0; i < G[n].size(); i++){
        if(depth[G[n][i]]==-1) dfs1(G[n][i], d+1);
    }
}

int main(){
    cin >> N >> K;
    int ans = INT32_MAX;
    for(int i = 0; i < N-1; i++){
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
        edge[i] = P(A, B);
    }
    if(K%2 == 0){
        for(int i = 1; i <= N; i++){
            int tmp = 0;
            clear_depth();
            dfs1(i, 0);
            for(int j = 1; j <= N; j++){
                if(depth[j] > K/2) tmp++;
            }
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }else{
        for(int i = 0; i < N-1; i++){
            int tmp = 0;
            clear_depth();
            depth[edge[i].first] = 0;
            depth[edge[i].second] = 0;
            dfs1(edge[i].first, 0);
            dfs1(edge[i].second, 0);
            for(int j = 1; j <= N; j++){
                if(depth[j] > K/2) tmp++;
            }
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
}