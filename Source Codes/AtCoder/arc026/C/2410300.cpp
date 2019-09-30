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
class SegTree {
public:
    const int MAX_N = 1 << 17;
    int n;
    vector<ll> dat;
    const ll INITIAL_DAT = INFl;

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
        return min(vl, vr);
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, L;
    cin >> N >> L;

    vector<pair<pair<int, int>, ll> > vp(N);

    rep(i, 0, N) {
        int l, r;
        ll c;
        cin >> l >> r;
        cin >> c;

        vp[i].first.first = l;
        vp[i].first.second = r;
        vp[i].second = c;

    }

//    vector<ll> dp(L + 5,INFl);
//
//    dp[0] = 0ll;
    sort(all(vp));
    SegTree treeone(L + 5);
    treeone.update(0, 0);

    for (int i = 0; i < N; i++) {
        int cur = vp[i].first.first;
        int next = vp[i].first.second;
        ll cost = treeone.find(cur, L + 2);
        if (treeone.find(next, L + 2) > cost + vp[i].second) {
            treeone.update(next, cost + vp[i].second);
        }
    }

    cout << treeone.find(L, L + 1) << endl;


    return 0;
}