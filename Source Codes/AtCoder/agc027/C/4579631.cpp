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
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//????????
struct SCC {
    int V;
    vector<vector<int> > G;//???????????
    vector<vector<int> > rG;//????????????
    vector<int> vs;//????????
    vector<bool> used;//??????
    vector<int> cmp;//?????????????????

    SCC(int v) {
        V = v;
        G.resize(V);
        rG.resize(V);
        used.resize(V);
        cmp.resize(V);
    }

    /**
     * ????
     * @param from ???
     * @param to ???
     */
    void add_edge(int from, int to) {
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v) {
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            if (!used[G[v][i]]) dfs(G[v][i]);
        }
        vs.push_back(v);
    }


    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (int i = 0; i < rG[v].size(); i++) {
            if (!used[rG[v][i]]) rdfs(rG[v][i], k);
        }
    }

    int scc() {
        fill(used.begin(), used.end(), false);
        vs.clear();
        for (int v = 0; v < V; v++) {
            if (!used[v]) dfs(v);
        }
        fill(used.begin(), used.end(), false);
        int k = 0;
        for (int i = vs.size() - 1; i >= 0; i--) {
            if (!used[vs[i]]) rdfs(vs[i], k++);
        }
        return k;
    }
};

class Solve {
public:
    int N, M;
    string S;

    struct edge {
        int v;
        int n; //???
        bool operator==(const edge &rhs) const {
            return v == rhs.v && n == rhs.n;
        }
    };

    vector<vector<vector<edge>>> G;

    void input() {
        cin >> N >> M;
        cin >> S;
        G.resize(N, vector<vector<edge>>(4));

        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (S[x] == 'A' && S[y] == 'A') {
                G[x][0].push_back(edge{y, 1});
                G[y][0].push_back(edge{x, 1});
            } else if (S[x] == 'A' && S[y] == 'B') {
                G[x][1].push_back(edge{y, 2});
                G[y][3].push_back(edge{x, 0});
            } else if (S[x] == 'B' && S[y] == 'A') {
                G[x][3].push_back(edge{y, 0});
                G[y][1].push_back(edge{x, 2});
            } else {
                G[x][2].push_back(edge{y, 3});
                G[y][2].push_back(edge{x, 3});
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 4; ++j) {
                sort(all(G[i][j]), [](edge a, edge b) {
                    if (a.v == b.v) return a.n < b.n;
                    return a.v < b.v;
                });
                G[i][j].erase(unique(all(G[i][j])), G[i][j].end());
//                G[i][j].erase(unique(G[i][j].begin(), G[i][j].end()), G[i][j].end());
            }
        }
    }

    int conv(int v, int n) {
        return v + n * N;
    }

    void solve() {
        input();
        SCC scc(N * 4);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (auto e : G[i][j]) {
                    scc.add_edge(conv(i, j), conv(e.v, e.n));

//                    if (i == 0 && j == 0 && e.v == 10 && e.n == 1) {
//                        cout << conv(i, j) << " -> " << conv(e.v, e.n) << endl;
//                    }
//                    if (i == 10 && j == 1 && e.v == 8 && e.n == 2) {
//                        cout << conv(i, j) << " -> " << conv(e.v, e.n) << endl;
//                    }
//                    if (i == 8 && j == 2 && e.v == 6 && e.n == 3) {
//                        cout << conv(i, j) << " -> " << conv(e.v, e.n) << endl;
//                    }
//                    if (i == 6 && j == 3 && e.v == 0 && e.n == 0) {
//                        cout << conv(i, j) << " -> " << conv(e.v, e.n) << endl;
//                    }
                }
            }
        }
        int k = scc.scc();
        if (k == 4 * N) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}