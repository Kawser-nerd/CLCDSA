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
    int n;
    vector<ll> data, datb;
    const ll INITIAL_DAT = 0L;

    SegTree(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data = vector<ll>(2 * n);
        datb = vector<ll>(2 * n);
        for (int i = 0; i < 2 * n - 1; ++i) data[i] = datb[i] = INITIAL_DAT;
    }

    //???SegTree??????
    ll calc(ll vl, ll vr) {
        return vl + vr;
    }

    //[a,b)?k??????
    //???????????add(a,b,x,0,0,???size)?
    void add(int a, int b, int x, int k, int l, int r) {
        if (a <= l && r <= b) {
            data[k] += x;
        } else if (l < b && a < r) {
            datb[k] += (min(b, r) - max(a, l)) * x;
            add(a, b, x, k * 2 + 1, l, (l + r) / 2);
            add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        }
    }

    void add(int a, int b, int x) {
        add(a, b, x, 0, 0, n);
    }

    //[a,b)????????
    //k??????,l,r??????[l,r)??????????????
    //??????????query(a,b,0,0,n)??????
    ll query(int a, int b, int k, int l, int r) {
        //[a,b)?[l,r)????????INITIAL_DAT
        if (r <= a || b <= l) return INITIAL_DAT;

        //[a,b)?[l,r)?????????INT_MAX
        if (a <= l && r <= b) return data[k] * (r - l) + datb[k];
        else {
            //????????2?????????,?????????
            ll res = (min(b, r) - max(a, l)) * data[k];
            res += query(a, b, k * 2 + 1, l, (l + r) / 2);
            res += query(a, b, k * 2 + 2, (l + r) / 2, r);
            return res;
        }
    }

    //[a,b)????????
    ll sum(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> vpi(M + 5);

    rep(i, 0, N) {
        int l, r;
        cin >> l >> r;
        int size = r - l + 1;
        vpi[size].emplace_back(l, r);
    }
    int kakutei = N;
    SegTree segTree(M + 5);
    rep(i, 1, M + 1) {
        ll ans = kakutei;
//        ans += segTree.sum()
        for(int m = i; m <= M; m += i){
            ans += segTree.sum(m,m+1);
        }
        for(auto e : vpi[i]){
            int l = e.first;
            int r = e.second;
            segTree.add(l,r+1,1);
        }
        kakutei -= vpi[i].size();
        cout << ans << endl;
    }


    return 0;
}