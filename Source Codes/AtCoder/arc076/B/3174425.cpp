#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 1000000007;

Int mod_pow(Int x, Int n){
    Int res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

Int gcd(Int a, Int b) {
  return b != 0 ? gcd(b, a % b) : a;
}
Int lcm(Int a, Int b) {
  return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

//????????
struct Edge{
    int from, to, cost;
};

//????????????????????(e1<e2??true)
bool Edge_comp(const Edge& e1, const Edge& e2){
    return e1.cost < e2.cost;
}

// Union-Find ? (Verified: ATC 001 B) Tsutaj??
struct UnionFind {
private:
    const int n;
    int __size;
    vector<int> uf;
public:
    // ??? UnionFind uni(n) ???????????
    UnionFind(int _n) : n(_n), __size(_n), uf(_n, -1) {}
    // find (???????)
    int find(int x) {return (uf[x] < 0) ? x : uf[x] = find(uf[x]);}
    // x ? y ?????????????
    bool same(int x, int y) {return find(x) == find(y);}
    // x ??????????
    int size(int x) {return -uf[find(x)];}
    // ?????????
    int size()      {return __size;}
    // x ? y ?????????
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        __size--;
        if(uf[y] < uf[x]) swap(x, y);
        uf[x] += uf[y]; uf[y] = x;
    }
};

// kruskal(vector????????????)
Int kruskal(vector<vector<Edge>> &G){
    int V = G.size();
    vector<Edge> es;
    for (int i = 0; i < V; i++){
        for (int j = 0; j < G[i].size(); j++){
            es.push_back(G[i][j]);
        }
    }
    int E = es.size();
    sort(es.begin(), es.end(), Edge_comp);
    UnionFind uf(V);
    Int res = 0;
    for (int i = 0; i < E; i++){
        Edge e = es[i];
        if (!uf.same(e.from, e.to)){
            uf.unite(e.from, e.to);
            res += e.cost;
        }
    }
    return res;
}
struct Town{
    int v, x, y;
};

bool Town_comp_x(const Town& t1, const Town& t2){
    return t1.x < t2.x;
}

bool Town_comp_y(const Town& t1, const Town& t2){
    return t1.y < t2.y;
}


int main(){
    vector<Town> vt;
    int N;
    cin >> N;
    vector<vector<Edge>> G(N);
    for (int i = 0; i < N; i++){
        Town t;
        cin >> t.x >> t.y;
        t.v = i;
        vt.push_back(t);
    }
    sort(vt.begin(), vt.end(), Town_comp_x);
    for (int i = 1; i < N; i++){
        Edge e;
        e.from = vt[i].v;
        e.to = vt[i-1].v;
        e.cost = vt[i].x - vt[i-1].x;
        G[e.from].push_back(e);
    }
    sort(vt.begin(), vt.end(), Town_comp_y);
    for (int i = 1; i < N; i++){
        Edge e;
        e.from = vt[i].v;
        e.to = vt[i-1].v;
        e.cost = vt[i].y - vt[i-1].y;
        G[e.from].push_back(e);
    }
    Int ans = kruskal(G);
    cout << ans << endl;
    return 0;
}