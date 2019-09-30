#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

//????SegmentTree///////////
//lazy???????
template<typename T>
struct delay_segtree {
private:
    int N;
    vector<T> node, lazy;
    //-------????---------------------
    //????ex)INF,0
    T init_value = 0;
    T default_value = 0;
    T default_lazy = 0;
    static inline T merge(const T& u, const T& v) {
        return u^v;
    }
    static inline void lazy_transmit(T& u, const T& v) {
        u ^= v;
    }
    static inline void node_transmit(T& u,const T& v,int l,int r){
        u ^= v;
    }
    //------------------------------------
    // k ?????????????????
    void eval(int k, int l, int r) {
        // ????????????????????????
        // ????????
        if (lazy[k] != default_lazy) {
            node_transmit(node[k], lazy[k],l,r);
            // ????????????????
            if (r - l > 1) {
                lazy_transmit(lazy[2 * k + 1], lazy[k]);
                lazy_transmit(lazy[2 * k + 2], lazy[k]);
            }
            // ????????????????????????
            lazy[k] = default_lazy;
        }
    }
public:
    delay_segtree(int n) {
        for(N=1;N<n;N*=2);
        node.resize(2 * N, init_value);
        lazy.resize(2 * N, default_lazy);
    }
    delay_segtree(vector<int> v) {
        int sz = v.size();
        for(N=1;N<sz;N*=2);
        node.resize(2 * N, init_value);
        lazy.resize(2 * N, default_lazy);
        for (int i = 0; i < sz; i++)
            node[i + N - 1] = v[i];
        for (int i = N - 2; i >= 0; i--)
            node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
    }
    void update(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = N;
        // k ?????????????????
        eval(k, l, r);
        // ??????????
        if (b <= l || r <= a)
            return;
        // ???????????????????????????
        if (a <= l && r <= b) {
            lazy_transmit(lazy[k], x);
            eval(k, l, r);
        }
        // ?????????????????????????
        // ?????????????
        else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = merge(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    // update k th element
    void update(int k, T val) {
        k += N - 1; // leaf
        node[k] = val;
        while (k > 0) {
            k = (k - 1) / 2;
            node[k] = merge(node[k * 2 + 1], node[k * 2 + 2]);
        }
    }
    // [a, b)
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = N;
        eval(k, l, r);
        if (r <= a or b <= l)
            return default_value;
        if (a <= l and r <= b)
            return node[k];
        int m = (l + r) / 2;
        T vl = query(a, b, k * 2 + 1, l, m);
        T vr = query(a, b, k * 2 + 2, m, r);
        return merge(vl, vr);
    }

    T operator[](const int &k) {
        //???????????
        query(k, k + 1);
        return node[k + N - 1];
    }
};



int main(){
  int N,Q;cin>>N>>Q;
  delay_segtree<int> seg(N);
  repeat(q,Q){
    int l,r;cin>>l>>r;l--;
    seg.update(l,r,1);
  }
  repeat(i,N){
    cout<<seg[i];
  }
  cout<<endl;
  return 0;
}