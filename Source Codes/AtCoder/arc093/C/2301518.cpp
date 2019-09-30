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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    ll X;
    cin >> X;
    using pii = pair<ll, pair<int, int> >;
    vector<pii> vpii;
    rep(i, 0, M) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        pii tmp;
        tmp.first = w;
        tmp.second.first = u;
        tmp.second.second = v;
        vpii.push_back(tmp);
    }

    sort(all(vpii));
    map<ll, int> costs;
    rep(i, 0, M) {
        UnionFind uf(N);
        ll sum_cost = 0ll;
        uf.unite(vpii[i].second.first, vpii[i].second.second);
        sum_cost += vpii[i].first;

        rep(j, 0, M) {
            if (i == j) continue;
            int l = vpii[j].second.first;
            int r = vpii[j].second.second;
            if (!uf.same(l, r)) {
                uf.unite(l, r);
                sum_cost += vpii[j].first;
            }
        }
        costs[sum_cost]++;
    }

    ll mst_cost = costs.begin()->first;

    if (X == mst_cost) {
        int min_cnt = costs.begin()->second;
        int oth_cnt = M - min_cnt;
        ll l = 1LL;
        rep(i, 0, oth_cnt) {
            l *= 2LL;
            l %= MOD;
        }
        ll r = 1LL;
        rep(i, 0, min_cnt) {
            r *= 2LL;
            r %= MOD;
        }
        r -= 2LL;
        if (r < 0) r += MOD;

        ll ans = (l * r) % MOD;
        cout << ans << endl;

    } else {
        int min_cnt = 0;
        int eq_cnt = 0;
        for (auto &e: costs) {
//            cout << "--" <<  e.first << endl;
            if (e.first < X) {
                min_cnt += e.second;
            } else if (e.first == X) {
                eq_cnt += e.second;
                break;
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
        int oth_cnt = M - min_cnt - eq_cnt;
//        ll ans = 1LL;
//        rep(i, 0, oth_cnt) {
//            ans *= 2ll;
//            ans %= MOD;
//        }
        ll l = 1LL;
        ll r = 1LL;
        rep(i, 0, oth_cnt) {
            l *= 2LL;
            l %= MOD;
        }
        rep(i, 0, eq_cnt) {
            r *= 2LL;
            r %= MOD;
        }
//        if (eq_cnt == 1) {
//            ll ans = (l * r) % MOD;
//            cout << ans << endl;
//        } else {
//            r *= 2LL;
//            r -= 2LL;
//            r %= MOD;
//            ll ans = (l * r) % MOD;
//            cout << ans << endl;
//        }
        r *= 2LL;
        r -= 2LL;
        if (r > MOD)r %= MOD;
        ll ans = (l * r) % MOD;
        cout << ans << endl;

    }


    return 0;
}