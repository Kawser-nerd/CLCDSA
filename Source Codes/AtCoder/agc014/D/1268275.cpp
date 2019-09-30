#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int N;
vector<vector<int> > g;

int dfs(int u,int p){
    int match = 0;
    REP(i, g[u].size()){
        if(g[u][i]==p)continue;
        int child = dfs(g[u][i], u);
        if(child<0)return -1;
        if(child==0){
            if(match)return -1;
            match = 1;
        }
    }
    return match;
}

int main(){
    cin >> N;
    g.assign(N, vector<int>());
    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << (dfs(0, -1)==1 ? "Second" : "First") << endl;
    return 0;
}