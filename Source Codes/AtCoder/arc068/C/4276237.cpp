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
#include <bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
template<typename T> class segtree {
private:
    int n,sz,h;
    vector<T> node, lazy;
    void eval(int k) {
        if(lazy[k]){
            node[k] += lazy[k];
            if(k < n) {
                lazy[k*2] += lazy[k] / 2, lazy[k*2+1] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
    
public:
    segtree(int N) : sz(N), h(0) {
        n = 1;
        while(n < sz) n *= 2, h++;
        node.resize(2*n, 0), lazy.resize(2*n, 0);
        for(int i = 0; i < sz; i++) node[i+n] = 0;
        for(int i = n-1; i >= 1; i--) node[i] = node[2*i] + node[2*i+1];
    }
    void range(int a, int b, T x, int k=1, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k);
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b){
            lazy[k] += (r-l)*x;
            eval(k);
        }else{
            range(a, b, x, 2*k, l, (l+r)/2);
            range(a, b, x, 2*k+1, (l+r)/2, r);
            node[k] = node[2*k] + node[2*k+1];
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = 0, res2 = 0;
        while(a < b) {
            if(a & 1) eval(a), res1 += node[a++];
            if(b & 1) eval(--b), res2 += node[b];
            a >>= 1, b >>= 1;
        }
        return res1 + res2;
    }
    void print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    vector<pii>a;
    cin >> n >> m;
    a.resize(n);
    rep(i,n){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end(),[&](pii b,pii c){
        return b.second-b.first < c.second-c.first;
    });
    int pos = 0;
    segtree<int>seg(m+1);
    for(int d = 1; d <= m; d++){
        int ans = 0;
        while(pos < n and a[pos].second - a[pos].first + 1 < d){
            seg.range(a[pos].first,a[pos].second+1,1);
            pos++;
        }
        ans = n-pos;
        for(int k = d; k <= m; k += d){
            ans += seg.query(k,k+1);
        }
        cout << ans << "\n";
    }
}