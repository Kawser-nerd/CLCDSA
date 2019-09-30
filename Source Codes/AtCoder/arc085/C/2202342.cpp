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
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007

//????????
class Flow {
    using T = long long;
public:
    struct edge {
        int to;
        T cap, rev;
    };
    vector<vector<edge> > G;
    vector<bool> used;
    vector<T> level;//s?????
    vector<int> iter;//???????????

    //0 ~ maxSize-1 ???????????????
    explicit Flow(unsigned maxSize) {
        G.resize(maxSize, vector<edge>());
        used.resize(maxSize, false);
        level.resize(maxSize, 0);
        iter.resize(maxSize, 0);
    }

    void add_edge(int from, int to, T cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size() - 1});
    }

    //s????????DFS???
    void bfs(int s) {
//        memset(level, -1, sizeof(level));
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    //???????
    T dfs(int v, int t, T f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    //s??t?????????
    T max_flow(int s, int t) {
        T flow = 0;
        for (;;) {
            bfs(s);
            if (level[t] < 0) return flow;
//            memset(iter, 0, sizeof(iter));
            fill(iter.begin(), iter.end(), 0);
            T f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    }

};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    Flow flow(N + 2);
    int S = 0;
    int T = N + 1;
    ll ans = 0;
    rep(i, 0, N) {
        int a;
        cin >> a;
        if (a < 0) {
            flow.add_edge(S, i + 1, -a);
        } else {
            flow.add_edge(i + 1, T, a);
            ans += 1LL * a;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i * 2; j <= N; j += i) {
            flow.add_edge(i, j, INF);
        }
    }
    ans -= flow.max_flow(S, T);
    cout << ans << endl;


    return 0;
}