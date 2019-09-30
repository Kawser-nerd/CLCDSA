#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<i_i, int> p_i;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<char> vc;
typedef vector<vector<char> > vvc;
typedef vector<double> vd;
typedef vector<vector<double> > vvd;
template<class T> using vv=vector<vector< T > >;
typedef deque<int> di;
typedef deque<deque<int> > ddi;

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        s << v[i]; if (i < len - 1) s << "\t";
    }
    return s;
}

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
    int len = vv.size();
    for (int i = 0; i < len; ++i) {
        s << vv[i] << endl;
    }
    return s;
}

template<long long M>
struct ModInt {
    long long x;
    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % M : M - (-y) % M) {}
    ModInt &operator += (const ModInt &rhs){ if((x += rhs.x) >= M) x -= M; return *this; }
    ModInt &operator -= (const ModInt &rhs){ if((x += M - rhs.x) >= M) x -= M; return *this; }
    ModInt &operator *= (const ModInt &rhs){ x = 1LL*x*rhs.x % M; return *this; }
    ModInt &operator /= (const ModInt &rhs){ x = (1LL*x*rhs.inv().x) % M; return *this; }
    ModInt operator - () const { return ModInt(-x); }
    ModInt operator + (const ModInt &rhs) const { return ModInt(*this) += rhs; }
    ModInt operator - (const ModInt &rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator * (const ModInt &rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator / (const ModInt &rhs) const { return ModInt(*this) /= rhs; }
    bool operator < (const ModInt &rhs) const { return x < rhs.x; }
    ModInt inv() const {
        long long a = x, b = M, u = 1, v = 0, t;
        while(b){ t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        return ModInt(u);
    }
    ModInt pow(long long t) const {
        ModInt e = *this, res = 1;
        for(; t; e *= e, t>>=1) if(t&1) res *= e;
        return res;
    }
};
template <long long M>
ostream &operator << (ostream &os, const ModInt<M> &rhs){
    return os << rhs.x;
}
template <long long M>
istream &operator >> (istream &is, ModInt<M> &rhs){
    long long s; is >> s; rhs = ModInt<M>(s); return is;
};

int main() {
    const ll mod = 1000000007;
    vll factorial(200010, 1);
    FOR (i, 1, 200010) {
        factorial[i] = factorial[i-1] * i % mod;
    }
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    int rn = min(h-a, w-b);
    ModInt<mod> ans(0);
    rep (i, rn) {
        int h1, h2, w1, w2;
        h2 = a + i;
        h1 = h - h2 - 1;
        w1 = b + i;
        w2 = w - w1 - 1;
        ModInt<mod> comb(1);
        comb *= factorial[h1+w1];
        comb /= factorial[h1];
        comb /= factorial[w1];
        comb *= factorial[h2+w2];
        comb /= factorial[h2];
        comb /= factorial[w2];
        ans += comb;
    }
    printf("%lld\n", ans.x);

    return 0;
}