#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define rep(i,a,b) for (ll i=(a); i<(b); i++)
typedef pair<int,int> PII;
typedef pair<int,pair<int,int> > PIII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<VI> MATRIX;
typedef vector<char> VC;
typedef vector<VC> CMATRIX;

const ll M = 1000000007;
ll mpow(ll x, ll y, ll m) {
    x %= m;
    ll result = 1;
    while (y > 0) {
        if (y & 1) result = (result * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return result;
}

// mod inverse ?m????x???
ull minverse(ull x, ull m) {
    return mpow(x, m-2, m);
}


// ??? O(n)
ll c (ll n, ll k, ll m) {
    static ll memo[1000][1000];
    if (memo[n][k]!=0) return memo[n][k];
    else if(n==k)      return memo[n][k]=1;
    else if(k==0)      return memo[n][k]=1;
    else               return memo[n][k]=(c(n-1,k-1,m)+c(n-1,k,m))%m;
}


// ????? O(n+k)
ll hcomp(ll n, ll k, ll m) {
    return c(k+n-1,k,m);
}

// ??????? O(n)
ll hcomp2(ll n, ll k, ll m) {
    //return c(k+n-1,k,m);
    ll res=1;
    for (ll j=1; j<n; j++){
        res = (res * (k+j)) % m;
        res = (res * minverse(j, m)) % m;
    }
    return res;
}

//=========== ???????? ============================

template <typename T>
class SegTree {
    private:
    int _n;
    T _init_val;
    vector<T> _data;
    function<T(T,T)> _f;

    T _query(int a, int b, int k, int l, int r) {
        // [a b)?[l r]??????
        if (r<=a || b <=l) return _init_val;

        // [a b)?[l r]???
        if (a<=l && r<=b) return _data[k];

        T vl = _query(a,b, k*2+1, l, (l+r)/2);
        T vr = _query(a,b, k*2+2, (l+r)/2, r);

        return _f(vl,vr);
    }

    public:
    SegTree (int n, T init_val, function<T(T, T)> f) {
        _init_val = init_val;
        _n = 1;
        _f = f;

        while(_n < n) _n *= 2;
        _data.resize(2*_n, init_val);
    }

    T get (int k) {
        return _data[k + _n -1];
    }

    void update(int k, T a) {
        k += _n-1;
        _data[k] = a;
        while(k>0){
            k = (k-1)/2;
            _data[k] = _f( _data[k*2+1], _data[k*2+2] );
        }
    }

    // [a b)????f???
    T query(int a,int b) {
        return _query(a,b,0,0,_n);
    }

    // ??????????????x???????????
    int lower_bound (T x) {
        return _lower_bound(x,0);
    }

    int _lower_bound (T x, int k){
        if (k >= _n-1){
            return k- (_n-1); // ?
        } else if (_data[k] < x) {
            return _n;        // ????
        } else if (x <= _data[k*2+1]){
            return _lower_bound(x,k*2+1);
        } else {
            return _lower_bound(x- _data[k*2+1] ,k*2+2);
        }
    }
};

//============================================
vector<int> fib(100,0);
signed main() {
    int k;
    cin>>k;
    fib[0] = fib[1] = 1;
    rep(i,2,99){
        fib[i] = fib[i-1] + fib[i-2];
    }
    if(k==0) { cout<<1<<" "<<0<<endl; }
    else cout<<fib[k+1]<<" "<<fib[k]<<endl;
    return 0;
}