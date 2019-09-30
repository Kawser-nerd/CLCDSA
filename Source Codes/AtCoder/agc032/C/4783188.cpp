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

class Flow {
public:
    struct edge {
        int to, cap, rev;
    };
    vector<vector<edge> > G;
    vector<bool> used;

    //0 ~ maxSize-1 ???????????????
    explicit Flow(unsigned maxSize) {
        G.resize(maxSize, vector<edge>());
        used.resize(maxSize, false);
    }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size() - 1});
    }

    //???????
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        for (;;) {
            rep(i, 0, used.size()) used[i] = false;
            int f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }

};

class Solve {
public:
    void input() {

    }

    void solve() {
        input();
        int N, M;
        cin >> N >> M;
        Flow flow(N + 2);

        vector<int> cnt(N + 1);
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            cnt[a]++;
            cnt[b]++;
            flow.add_edge(a, b, 1);
            flow.add_edge(b, a, 1);
        }

        bool six = false; //6??
        bool odd = false; //??
        vector<int> four; //4???

        for (int i = 1; i <= N; ++i) {
            if (cnt[i] >= 6) six = true;
            if (cnt[i] % 2) odd = true;
            if (cnt[i] == 4) four.push_back(i);
        }

        if (odd) {
            cout << "No" << endl;
            return;
        }

        if (six) {
            cout << "Yes" << endl;
            return;
        }

        if (four.size() > 2) {
            cout << "Yes" << endl;
            return;
        }
        if (four.size() < 2) {
            cout << "No" << endl;
            return;
        }

        int fl = flow.max_flow(four[0], four[1]);
        if (fl == 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
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