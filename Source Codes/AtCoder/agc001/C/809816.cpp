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

int N, K;
vector<vector<int> > graph;
vector<pair<int,int> > edges;

// return num of delete nodes
int dfs(int v,int prev, int sum){
    int res = 0;
    REP(i, graph[v].size()){
        int u = graph[v][i];
        if(u==prev)continue;
        res += dfs(u, v, sum+1);
    }
    if(sum>K/2)res++;
    return res;
}


int main(){
    cin >> N >> K;
    graph.assign(N, vector<int>());
    edges.clear();
    REP(i, N-1){
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        edges.push_back(make_pair(A, B));
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    int res = N;
    if(K%2==0){
        REP(i,N){
            res = min(res, dfs(i, -1, 0));
        }
    }else{
        K--;
        REP(i,N-1){
            int a = edges[i].first;
            int b = edges[i].second;
            res = min(res, dfs(a, b, 0) + dfs(b, a, 0));
        }
    }

    cout << res << endl;

    return 0;
}