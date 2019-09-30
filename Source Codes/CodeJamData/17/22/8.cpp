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
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("IMPOSSIBLE"); return;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

struct Solver {
  void solve() {
    string s = "RYBGVO";
    vi a(6);
    int n;
    cin>>n;
    cin>>a[0];
    cin>>a[5];
    cin>>a[1];
    cin>>a[3];
    cin>>a[2];
    cin>>a[4];
    rep(i,3) {
      int x = a[3+i];
      // cerr<<a[i]<<" "<<x<<endl;
      if (a[i] < x) dame;
      if (!x) continue;
      if (a[i] == x) {
        rep(j,3) if (i != j) {
          if (a[j] || a[j+3]) dame;
        }
        string ans;
        rep(j,a[i]) {
          ans += s[i];
          ans += s[i+3];
        }
        cout<<ans<<endl;
        // cerr<<a<<endl;
        return;
      }
      a[i] -= x;
    }
    int mx = 0, sum = 0;
    rep(i,3) maxs(mx,a[i]), sum += a[i];
    rep(i,3) a[i] *= 2;
    rep(i,3) if (a[i] == mx*2) a[i]++;
    if (mx*2 > sum) dame;
    string ans;
    int pre = -1;
    rep(i,sum) {
      P p(0,-1);
      rep(j,3) if (pre != j) maxs(p,P(a[j],j));
      int x = p.se;
      assert(x != -1);
      a[x] -= 2; pre = x;
      ans += s[x];
    }
    rep(i,3) {
      rep(j,sz(ans)) {
        if (ans[j] == s[i]) {
          string x;
          rep(k,a[i+3]) x += s[i], x += s[i+3];
          ans.insert(ans.begin()+j,rng(x));
          break;
        }
      }
    }
    assert(sz(ans) == n);
    assert(ans[0] != ans.back());
    cout<<ans<<endl;
  }
};

int main() {
  int ts;
  scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    printf("Case #%d: ",ti);
    solver.solve();
  }
  return 0;
}




















