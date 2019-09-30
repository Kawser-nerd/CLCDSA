#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30)
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007

//????????
class UnionFind {
    vector<int> p;//p[i]?i??????
public:
    UnionFind(int n) {
        p = vector<int>(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        return;
    }

    void printState() {
        if (DEBUG) {
            cout << "---" << endl;
            for (int i = 0; i < p.size(); i++) {
                printf("%d???%d\n", i, p[i]);
            }
            cout << "---" << endl;
        }
    }

/* x????????? */
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

/* y?x????? */
    void unite(int x, int y) {
        p[find(x)] = p[find(y)];
    }

/* x?y??????????????? */
    bool same(int x, int y) {
        return find(x) == find(y);
    }

};

class Dijkstra {
public:
    struct edge {
        ll to, cost;
    };
    typedef pair<ll, ll> P;//first??????second??????

    int V;//???
    vector<vector<edge> > G;//???,G[i]?i????????,G[i][j]?i??????j????
    vector<ll> d; //????

    //0origin
    Dijkstra(int N) {
        V = N;
        G = vector<vector<edge> >(N);
        d = vector<ll>(N);
        fill(d.begin(), d.end(), INFl);
    };

    bool dijkstra(int s) {
        priority_queue<P, vector<P>, greater<P> > que;
        d[s] = 0;
        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();
            ll v = p.second;
            if (d[v] < p.first) continue;
            for (int i = 0; i < G[v].size(); i++) {
                edge e = G[v][i];
                if (d[e.to] < d[v] + e.cost) return false;
                if (d[e.to] > d[v] + e.cost && !(d[e.to] == INFl && d[v] == INFl)) {
                    if (d[e.to] != INFl) return false;
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
        return true;
    }

    /* ??from???to???????cost????? */
    void addEdge(int from, int to, int cost) {
        edge e;
        e.to = to;
        e.cost = cost;
        G[from].push_back(e);
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
//    UnionFind uf(N);
    Dijkstra dij(N);
    vector<int> parent(N, -1);
    vector<bool> apr(N, false);
    rep(i, 0, M) {
        int L, R, D;
        cin >> L >> R >> D;
        L--;
        R--;
//        uf.unite(L,R);
        dij.addEdge(L, R, D);
        parent[R] = L;
        apr[L] = apr[R] = true;
    }
//    set<int> apr;

    rep(i, 0, N) {
//        if(apr.find(uf.find(i)) == apr.end()){
//            apr.insert(uf.find(i));
//            if(!dij.dijkstra(i)){
//                cout << "No" << endl;
//                return 0;
//            }
//        }
        if (dij.d[i] == INFl) {
            if (!apr[i]) continue;
            int node = i;
            int loop = 0;

            while (true) {
                if (parent[node] == -1) break;
                node = parent[node];
                ++loop;
                if (loop > N) {
                    cout << "No" << endl;
                    return 0;
                }
            }
            if (!dij.dijkstra(node)) {
                cout << "No" << endl;
                return 0;
            }
        }

    }

    cout << "Yes" << endl;


    return 0;
}