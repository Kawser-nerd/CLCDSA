#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iomanip>
using namespace std;
  
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
typedef long long ll;

struct SCC {

    int cmp_cnt;
    vector< vector< int > > G, rev_G;
    vector< bool > used;
    vector< int > vs, cmp;
    SCC (int n) : G(n),rev_G(n),used(n),cmp(n) {}
    
    void add_edge(int from, int to) {
        G[from].push_back(to);
        rev_G[to].push_back(from);
    }
    
    void build() {
        vs.clear();
        cmp_cnt = 0;
        fill(used.begin(),used.end(),false);
        for (int i = 0; i < G.size(); i++) {
            if(!used[i]) {
                dfs(i);
            }
        }
        fill(used.begin(),used.end(),false);
        for (int i = (int)vs.size() - 1; i >= 0; i--) {
            if (!used[vs[i]]) {
                rev_dfs(vs[i],cmp_cnt++);
            }
        }        
    }
    
    void dfs(int v) {
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            if (!used[G[v][i]]) dfs(G[v][i]);
        }
        vs.push_back(v);
    }
    
    void rev_dfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (int i = 0; i < rev_G[v].size(); i++) {
            if (!used[rev_G[v][i]]) rev_dfs(rev_G[v][i], k);
        }
    }
    
    int operator [] (int n) {
        return cmp[n];
    }
    
};

int N,A,B;
vector < int > x,y;
vector < int > u,v;

void dfs(vector < vector <int> > G, set<int> &unused, int v) {
    stack < int > sta;
    sta.push(v);
    bool used[110];
    REP(i,110) used[i] = false;
    while (!sta.empty()) {
        int vt = sta.top();
        sta.pop();
        if (used[vt]) continue;
        used[vt] = true;
        unused.insert(vt);
        REP(i,G[vt].size()) {
            sta.push(G[vt][i]);
        }
    }
}

int main() {

    cin >> N >> A;
    x.resize(A);
    y.resize(A);
    REP(i,A) cin >> x[i] >> y[i];

    cin >> B;
    u.resize(B);
    v.resize(B);
    REP(i,B) cin >> u[i] >> v[i];

    int ans = 0;
    REP(i,(1 << B)) {
        SCC inst(110);
        vector < vector <int> > G(110);
        set < int > unused;
        REP(j,A) {
            inst.add_edge(y[j], x[j]);
            G[y[j]].push_back(x[j]);
        } 
        REP(j,B) if ((i >> j) & 1) {
            inst.add_edge(u[j], v[j]);
            G[u[j]].push_back(v[j]);
        } else {
            unused.insert(u[j]);
        }
        
        inst.build();
        map < int, int > cnt;
        for (int i = 1; i <= N; i++) cnt[inst[i]]++;
        for (int i = 1; i <= N; i++) if (cnt[inst[i]] > 1) unused.insert(i);
        for (int i = 1; i <= N; i++) if (unused.find(i) != unused.end()) dfs(G, unused, i);
        ans = max(ans, N - (int) unused.size());
    }

    cout << ans << endl;

    return 0;
}