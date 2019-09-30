#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[100000];
vector<int> b[100000];

int dfs(int n){
    int N = G[n].size();
    if(N == 0) return 1;
    int m = 0;

    for(int i = 0; i < N; i++){
        b[n].push_back(dfs(G[n][i]));
    }
    sort(b[n].begin(), b[n].end(), greater<int>());
    for(int i = 0; i < N; i++){
        m = max(m, b[n][i]+i+1);
    }
    return m;
}

int main(){
    int N;
    int a[100000];
    cin >> N;
    for(int i = 1; i < N; i++){
        cin >> a[i];
        a[i]--;
        G[a[i]].push_back(i);
    }
    cout << dfs(0)-1 << endl;
}