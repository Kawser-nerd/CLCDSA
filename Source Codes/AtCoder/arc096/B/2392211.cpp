#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template<typename T>
class segtree {
public:
    //???10^5???
    static const int MAX_N = 1 << 17;
    
    int n;
    T dat[2 * MAX_N - 1];
    
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        for (int i = 0; i < 2 * n - 1; i++) {
            dat[i] = -(1LL<<60);
        }
    }
    
    // k??(0-indexed)?a???
    void update(int k, T a) {
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    //[a,b)????
    // k???????l,r??????[l,r)?????????????
    //????query(a, b, 0, 0, n)?????=>??n?seg.n
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return -(1LL<<60);
        if (a <= l && r <= b)
            return dat[k];
        else {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main(){
    int n;
    ll c;
    cin >> n >> c;
    vector<ll>x(n),v(n);
    rep(i,n){
        scanf("%lld %lld",&x[i],&v[i]);
    }
    ll ans = 0;
    vector<ll>a(n);
    ll temp = 0;
    rep(i,n){
        temp += v[i];
        a[i] = temp -x[i];
        ans = max(a[i],ans);
    }
    segtree<ll> seg;
    segtree<ll>seg2;
    seg2.init(n);
    seg.init(n);
    rep(i,n){
        seg.update(i,a[i]);
    }
    vector<ll>b(n);
    temp = 0;
    rep(i,n){
        temp += v[n-1-i];
        b[i] = temp-(c-x[n-1-i]);
        ans = max(b[i],ans);
        seg2.update(i,b[i]);
    }
    rep(i,n-1){
        ans = max(ans,b[i]-(c-x[n-1-i])+seg.query(0,n-1-i));
        ans = max(ans,a[i]-x[i]+seg2.query(0,n-1-i));
    }
    cout << ans << endl;
    
}