#include "math.h"
#include <algorithm>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define ifor(i, a, b) for (int i = (a); i < (b); i++)
#define rfor(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long double ld;
typedef long long int lli;
typedef complex<double> P;
const double eps = 1e-11;
int vex[4] = {1, 0, -1, 0};
int vey[4] = {0, 1, 0, -1};
typedef vector<double> Vec;
typedef vector<int> vec;
typedef vector<Vec> MAT;
typedef vector<vec> mat;
lli MOD = 1000000007;
#define MAX 100005
struct node {
    lli v, d;
    node(lli v, lli d) : v(v), d(d) {}
    bool operator<(const node& n) const { return d > n.d; }
};
struct edge {
    lli to, d;
    edge(lli to,lli d) : to(to), d(d) {}
};
lli V;
struct Graph {
    vector<edge> G[MAX];
    lli dist[MAX];  // shortest distance
    Graph()
    {
        rep(i, MAX)
        {
            G[i].clear();
            dist[i] = -1;
        }
    }
    void dijkstra(lli s)
    {
        priority_queue<node> que;
        que.push(node(s, 0));
        while (!que.empty()) {
            lli v = que.top().v, d = que.top().d;
            que.pop();
            if (dist[v] >= 0 and dist[v] <= d)
                continue;
            dist[v] = d;
            for (lli i = 0; i < G[v].size(); i++)
                que.push(node(G[v][i].to, d + G[v][i].d));
        }
    }
};

Graph g1{};
int main()
{
    lli a,b,n,v,p,k;
    cin >> n;
    rep(i, n - 1)
    {
        cin >> a >> b;
        a--, b--;
        g1.G[a].push_back(edge(b,1));
        g1.G[b].push_back(edge(a,1));
    }
    cin >> k;
    lli vl[100095],pl[100095];
    rep(i, k)
    {
        cin >> v >> p;
        p+=1;
        v--;
        vl[i] = v;
        pl[i] = p;
        g1.G[n].push_back(edge(v,p));
        g1.G[v].push_back(edge(n,p));
    }
    g1.dijkstra(n);
    queue<lli> que;
    rep(i,n)cerr << i << ' ' << g1.dist[i]<<endl;
    que.push(0);
    bool used[100005]={};
    used[0] = true;

    while (!que.empty()) {
        lli now = que.front();
        que.pop();
        for(lli i = 0;i<g1.G[now].size();i++){
            edge s = g1.G[now][i];
            if (s.to == n || now == n)
                continue;
            if (abs(g1.dist[now] - g1.dist[s.to]) == 0) {
                cout << "No" << endl;
                return 0;
            }
            if(!used[s.to]){
                used[s.to] = true;
                que.push(s.to);
            }

        }
    }
    rep(i,k)if(g1.dist[vl[i]]!= pl[i]) {
            cout << "No"<<endl;
            return 0;
        }
    cout << "Yes" << endl;
    rep(i, n)
    {
        cout << g1.dist[i]-1 << endl;
    }
}