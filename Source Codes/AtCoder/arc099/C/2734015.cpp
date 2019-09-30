#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i, b, n) for(int i=b;i<(int)n;i++)
#define rep(i, n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it, o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cout << __LINE__ << ' ' << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;

//??????????????!!

class DisJointSet{
public:
    vector<int> v;//????????
    DisJointSet(int n){//???
        v = vector<int>(n);
        rep(i, n)v[i] = i;
    }
    int find(int x){//????
        if(v[x] == x)return x;
        else return v[x] = find(v[x]);
    }
    void unite(int x, int y){//x?y??????
        x = find(x);
        y = find(y);
        if(x == y)return;
        v[x] = y;
    }
    bool same(int x, int y){//x?y?????????
        return find(x) == find(y);
    }
};

vector<vector<int> > V;

vector<int> countSize(int now, map<int, int> &visited, int c){
    if(visited.count(now)){
        if(visited[now] != c){
            vector<int> tmp(2);
            tmp[0] = -1;
            return tmp;
        }
        else return vector<int>(2);
    }
    visited[now] = c;
    c = (c+1)%2;

    vector<int> ret(2);
    ret[0] = ret[1] = 0;
    ret[c] = 1;
    rep(i, V.size()){
        if(V[now][i] == 0)continue;
        vector<int> tmp = countSize(i, visited, c);
        if(min(tmp[0], tmp[1]) == -1)return tmp;
        ret[0] += tmp[0];
        ret[1] += tmp[1];
    }
    return ret;
}



int main() {
    int N;
    cin >> N;
    rep(i, N)V.push_back(vector<int>(N));
    rep(i, N)rep(j, N)V[i][j] = 1;
    int M ;
    cin >> M;
    DisJointSet ds(N), ds2(N);
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--;b--;
        V[a][b] = V[b][a] = 0;
        ds2.unite(a,b);
    }
    rep(i, N)V[i][i] = 0;


    rep(i, N)rep(j, N)if(V[i][j]){
                ds.unite(i, j);
            }
    set<int> used;
    vector< vector<int> > ANS;

    rep(i, N){
        if(used.count(ds.find(i)) != 0)continue;
        map<int, int> visited;
        vector<int> tmp = countSize(i, visited, 0);
        if(min(tmp[0], tmp[1]) == -1){
            cout << -1 <<endl;
            return 0;
        }
        ANS.push_back(tmp);
        used.insert(ds.find(i));
    }


    set<int> SUM;
    SUM.insert(0);

    FOR(it1, ANS){
        set<int> next;
        FOR(it2, SUM){
            next.insert(*it2 + (*it1)[0]);
            next.insert(*it2 + (*it1)[1]);
        }
        SUM = next;
    }

    int ans = 1e9;
    FOR(it, SUM){
        int a = *it;
        int b = N - a;
        ans = min(ans, a*(a-1)/2 + b*(b-1)/2);
    }
    cout << ans <<endl;

    return 0;
}