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
typedef pair<string,string> P;
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

struct Solver {
  int n;
  string maxfil(string s) {
    rep(i,n) if (s[i] == '?') s[i] = '9';
    return s;
  }
  string minfil(string s) {
    rep(i,n) if (s[i] == '?') s[i] = '0';
    return s;
  }
  inline ll val(string& s) {
    ll res = 0;
    rep(i,n) res = res*10+s[i]-'0';
    return res;
  }
  inline ll diff(P& a) {
    return abs(val(a.fi)-val(a.se));
  }
  void up(P& a, P b) {
    ll da = diff(a), db = diff(b);
    if (da < db) return;
    if (da > db) a = b;
    else if (a > b) a = b;
  }
  void solve() {
    string s, t;
    cin >> s >> t;
    n = sz(s);

    P ans(maxfil(s),maxfil(t));
    string ns = s;
    string nt = t;
    rep(i,n) {
      rep(j,10)rep(k,10) {
        if (s[i] != '?' && s[i]-'0' != j) continue;
        if (t[i] != '?' && t[i]-'0' != k) continue;
        ns[i] = '0'+j;
        nt[i] = '0'+k;
        up(ans, P(maxfil(ns),minfil(nt)));
        up(ans, P(minfil(ns),maxfil(nt)));
      }
      if (s[i] == '?') {
        if (t[i] == '?') {
          ns[i] = nt[i] = '0';
        } else {
          ns[i] = nt[i];
        }
      } else {
        if (t[i] == '?') {
          nt[i] = ns[i];
        } else {
          if (s[i] != t[i]) break;
        }
      }
    }
    cout<<ans.fi<<" "<<ans.se<<endl;
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





