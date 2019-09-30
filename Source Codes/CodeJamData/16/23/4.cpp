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
{for(T&x:v)i>>x;return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;for(T&x:v)s<<' '<<x;return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// binary matching
struct match {
  vector<int> used;
  vector<vector<int> > to;
  vector<int> p;
  int n, m;
  match(int n, int m):used(n),to(n),p(m,-1),n(n),m(m){}
  void add(int a, int b) { to[a].pb(b);}
  bool dfs(int v){
    if(used[v]) return false;
    used[v] = 1;
    rep(i,to[v].size()) {
      int u = to[v][i];
      if (p[u] == -1 || dfs(p[u])){
        p[u] = v;
        return true;
      }
    }
    return false;
  }
  int solve(){
    int res = 0;
    rep(i,n) {
      rep(j,n) used[j] = 0;
      if(dfs(i)) ++res;
    }
    return res;
  }
};
//

struct Solver {
  map<string,int> m1, m2;
  int get(map<string,int>& mp, string& s) {
    if (mp.count(s)) return mp[s];
    return mp[s] = sz(mp)-1;
  }
  void solve() {
    int n;
    scanf("%d",&n);
    vi a(n), b(n);
    rep(i,n) {
      string s;
      cin >> s;
      a[i] = get(m1,s);
      cin >> s;
      b[i] = get(m2,s);
    }
    int l = sz(m1), r = sz(m2);
    match mt(l,r);
    rep(i,n) {
      mt.add(a[i],b[i]);
    }
    int ans = l+r-mt.solve();
    ans = n-ans;
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





