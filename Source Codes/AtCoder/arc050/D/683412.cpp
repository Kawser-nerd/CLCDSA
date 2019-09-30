#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("0"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// Segment tree (RMQ type)
struct seg {
  vector<int> d; int x2;
  seg(){}
  seg(int mx) {
    x2 = 1; while(x2 < mx) x2 <<= 1;
    d.resize(x2<<1);
  }
  void fil() {
    drep(i,x2) d[i] = min(d[i<<1],d[i<<1|1]);
  }
  int get(int a, int b, int i=1, int l=0, int r=-1){
    if (r == -1) r = x2;
    if(a <= l && r <= b) return d[i];
    int c = (l+r)>>1;
    int res = INF;
    if(a < c) mins(res,get(a,b,i<<1,l,c));
    if(c < b) mins(res,get(a,b,i<<1|1,c,r));
    return res;
  }
};
//

// Suffix array
struct SA {
  string s;
  int n;
  vi id, rank, lcp;
  seg t;
  
  void cons() {
    s += '$';
    n = s.size();
    id = rank = vi(n);
    vi tmp(n);
    rep(i,n) id[i] = i, rank[i] = s[i];
    int k;
    auto comp = [&](int i, int j) {
      if(rank[i] != rank[j]) return rank[i] < rank[j];
      int ri = i + k < sz(rank) ? rank[i + k] : -1;
      int rj = j + k < sz(rank) ? rank[j + k] : -1;
      return ri < rj;
    };
    for (k = 1; k < n; k<<=1) {
      sort(rng(id),comp);
      tmp[id[0]] = 0;
      for (int i = 1; i < n; ++i) tmp[id[i]] = tmp[id[i-1]] + comp(id[i-1],id[i]);
      rank = tmp;
    }
    cons_lcp();
  }
  void cons_lcp() {
    lcp = vi(n);
    int h = 0;
    rep(i,n-1){
      int j = id[rank[i]-1];
      if(h > 0) h--;
      for(; i+h < n && j+h < n && s[i+h] == s[j+h]; h++);
      lcp[rank[i]-1] = h;
    }
    t = seg(n+5);
    rep(i,n) {
      t.d[t.x2+i] = lcp[i];
    }
    t.fil();
  }
  inline int get(int l, int r) {
    if (l > r) swap(l,r);
    return t.get(l,r);
  }
  inline int len(int i) {
    return n-i-1;
  }
  void solve() {
    vi ans;
    rep(i,n-1) ans.pb(i);
    auto c = [&](int i, int j) {
      int g = get(rank[i], rank[j]);
      // cout<<g<<endl;
      if (g == len(i)) {
        return rank[j] < rank[j+g];
      } else if (g == len(j)) {
        return rank[i+g] < rank[i];
      } else return rank[i] < rank[j];
    };
    sort(rng(ans), c);
    rep(i,sz(ans)) {
      printf("%d\n", ans[i]+1);
    }
    // cout<<"----"<<endl;
    // cout<<c(0,3)<<endl;
    // cout<<c(3,0)<<endl;
  }
};
//

int main() {
  int n;
  scanf("%d",&n);
  SA sa;
  cin >> sa.s;
  sa.cons();
  sa.solve();
  return 0;
}