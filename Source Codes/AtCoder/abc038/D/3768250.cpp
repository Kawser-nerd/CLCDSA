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
class SegTree {
public:
    const int MAX_N = 1 << 17;
    int n;
    vector<ll> dat;
    const ll INITIAL_DAT = 0L;

    SegTree(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<ll>(2 * n);
        for (int i = 0; i < 2 * n - 1; ++i) dat[i] = INITIAL_DAT;
    }

    //???SegTree??????(??????RMQ)
    ll calc(ll vl, ll vr) {
        return max(vl, vr);
    }

    //k????(0-indexed)?a???
    void update(int k, ll a) {
        k += n - 1;
        dat[k] = a;
        //???????
        while (k > 0) {
            k = (k - 1) / 2;
//            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
            dat[k] = calc(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    //[a,b)????????
    //k??????,l,r??????[l,r)??????????????
    //??????????query(a,b,0,0,n)??????
    ll query(int a, int b, int k, int l, int r) {
        //[a,b)?[l,r)????????INITIAL_DAT
        if (r <= a || b <= l) return INITIAL_DAT;

        //[a,b)?[l,r)?????????INT_MAX
        if (a <= l && r <= b) return dat[k];
        else {
            //????????2?????????,?????????
            ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return calc(vl, vr);
        }
    }

    //[a,b)????????
    ll find(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};

class Solve {
public:
    void input() {

    }

    void solve() {
        input();
        const int max_v = 123456;
        vector<vector<int>> vv(max_v);

        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            int h, w;
            cin >> h >> w;
            vv[h].push_back(w);
        }

        for (int i = 0; i < max_v; ++i) {
            sort(vv[i].rbegin(), vv[i].rend());
        }

        SegTree treeone(max_v);

        for (int i = 1; i < max_v; ++i) {
            for (auto e : vv[i]) {
                ll tmp = treeone.find(0, e);
                treeone.update(e, tmp + 1);
            }
        }

        ll ans = treeone.find(0,max_v);
        cout << ans << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}