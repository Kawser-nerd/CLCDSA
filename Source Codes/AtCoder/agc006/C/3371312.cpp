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

vector<ll> inv(vector<ll> v) {
    vector<ll> ret(v.size());

    for (int i = 0; i < v.size(); ++i) {
        ret[v[i]] = i;
    }

    return ret;
}

/*
 * ???
 */

vector<ll> mul(vector<ll> m1, vector<ll> m2) {
    int N = m1.size();
    vector<ll> v(N), tmp(N);
    rep(i, 0, N) v[i] = i;

    for (int i = 0; i < N; ++i) {
        tmp[m1[i]] = v[i];
    }
    swap(tmp, v);
    for (int i = 0; i < N; ++i) {
        tmp[m2[i]] = v[i];
    }

    vector<ll> ret = inv(tmp);
    return ret;
}

/*
 * ???
 */
vector<ll> pow(vector<ll> mapping, ll M) {
    vector<ll> base = mapping;
    vector<ll> ret(mapping.size());
    rep(i, 0, ret.size()) ret[i] = i;

    while (M > 0) {
        if (M & 1) {
            ret = mul(ret, base);
        }
        M >>= 1;
        base = mul(base, base);
    }

    return ret;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

//    if(true){
//        vector<ll> hya({0,3,4,1,2});
//        auto a = inv(hya);
//        return 0;
//    }

    ll N;
    cin >> N;

    vector<ll> x(N);
    rep(i, 0, N) cin >> x[i];

    ll M, K;
    cin >> M >> K;
    vector<ll> a(M);
    rep(i, 0, M) {
        cin >> a[i];
        a[i]--;
    }
    vector<ll> d(N - 1);
    rep(i, 0, N - 1) {
        d[i] = x[i + 1] - x[i];
    }

    vector<ll> base(N - 1);
    rep(i, 0, base.size()) base[i] = i;
    for (auto e : a) {
        swap(base[e], base[e - 1]);
    }
    base = inv(base);

    auto powed = pow(base, K);

    vector<ll> ans_k(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        ans_k[powed[i]] = i;
    }

    vector<ll> ans_diff(N - 1);
    rep(i, 0, N - 1) {
        ans_diff[i] = d[ans_k[i]];
    }
    vector<ll> ans(N);
    ans[0] = x[0];
    for (int i = 1; i < N; ++i) {
        ans[i] = ans[i - 1] + ans_diff[i - 1];
    }

    rep(i, 0, N) {
        cout << ans[i] << endl;
    }


    return 0;
}