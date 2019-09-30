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
class Dijkstra {
public:
    struct edge {
        ll to, cost;
    };
    typedef pair<ll, ll> P;//first??????second??????

    int V;//???
    vector<vector<edge> > G;//???,G[i]?i????????,G[i][j]?i??????j????
    vector<ll> d; //????
    vector<ll> dp;

    //0origin
    Dijkstra(int N) {
        V = N;
        G = vector<vector<edge> >(N);
        d = vector<ll>(N);
        dp = vector<ll>(N);
    };

    void dijkstra(int s) {
        priority_queue<P, vector<P>, greater<P> > que;
        fill(d.begin(), d.end(), INFl);
        d[s] = 0;
        dp[s] = 1;
        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();
            ll v = p.second;
            if (d[v] < p.first) continue;
            for (int i = 0; i < G[v].size(); i++) {
                edge e = G[v][i];
                if (d[e.to] == d[v] + e.cost && d[v] != INFl) {
                    dp[e.to] += dp[v];
                    dp[e.to] %= MOD;
                }
                if (d[e.to] > d[v] + e.cost && !(d[e.to] == INFl && d[v] == INFl)) {
                    d[e.to] = d[v] + e.cost;
                    dp[e.to] = dp[v];
                    que.push(P(d[e.to], e.to));
                }
            }
        }

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
    int S, T;
    cin >> S >> T;
    S--;
    T--;
    Dijkstra dijA(N), dijB(N);

    rep(i, 0, M) {
        int U, V, D;
        cin >> U >> V >> D;
        U--;
        V--;
//        int mid = i + N;
        dijA.addEdge(U, V, D);
//        dijA.addEdge(mid, U, D);
//        dijA.addEdge(mid, V, D);
        dijA.addEdge(V, U, D);

        dijB.addEdge(U, V, D);
        dijB.addEdge(V, U, D);
//        dijB.addEdge(mid, V, D);
//        dijB.addEdge(V, mid, D);
    }
    dijA.dijkstra(S);
    dijB.dijkstra(T);
    ll dist = dijA.d[T];
    ll ans = (dijA.dp[T] * dijB.dp[S]) % MOD;
    rep(i, 0, dijA.d.size()) {
        if (dijA.d[i] * 2 == dist) {
//            ans = (ans - dijA.dp[i] * dijB.dp[i] * dijA.dp[i] * dijB.dp[i]) % MOD;
            ll tmp = dijA.dp[i] * dijB.dp[i] % MOD;
            tmp = tmp * tmp % MOD;
            ans -= tmp;
            if (ans < 0) ans += MOD;
        }
    }
//    ans -= dijA.dp[T];
//    ans %= MOD;
//    if (ans < 0) ans += MOD;
    rep(i, 0, dijA.G.size()) {
        rep(j, 0, dijA.G[i].size()) {
            if (dijA.d[i] * 2 < dist &&
                dijB.d[dijA.G[i][j].to] * 2 < dist &&
                dijA.d[i] + dijB.d[dijA.G[i][j].to] + dijA.G[i][j].cost == dist) {
                ll tmp = dijA.dp[i] * dijB.dp[dijA.G[i][j].to]  % MOD;
                tmp = tmp * tmp % MOD;
//                ans -= (dijA.dp[i] * dijB.dp[dijA.G[i][j].to] * dijA.dp[i] * dijB.dp[dijA.G[i][j].to]) % MOD;
                ans -= tmp;
                ans %= MOD;
                if (ans < 0) ans += MOD;
            }
        }
    }

    cout << ans << endl;
    return 0;
}