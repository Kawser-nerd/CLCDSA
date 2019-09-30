#include<iostream>
#include<queue>
#include<bitset>
#include<algorithm>
#include<climits>
#include<vector>
#include<deque>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define fill(x,y) memset(x,y,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define dump(a) rep(i,a.size()){ cout<<a[i]<<" "; } cout<<endl;
#define dumparr(a,n) rep(i,n){ cout<<a[i]<<" "; } cout<<endl;
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define INF INT_MAX/3
#define EPS 1e-7

/* ??????????
 * node?????????edge??????????????(???????-????)???
 * O(n^2)
 */

int main(){
  ll xs,ys, xt,yt;
  ll n;
  ll x[1003], y[1003], r[1003];
  cin>>xs>>ys>>xt>>yt>>n;
  rep(i,n){
    cin>>x[i]>>y[i]>>r[i];
  }
  // x[0]~x[n-1]??, x[n]?start, x[n+1]?end
  x[n]=xs; y[n]=ys; r[n]=0;
  x[n+1]=xt; y[n+1]=yt; r[n+1]=0;

  // ??????
  double d[1003]; // s???????
  bool used[1003];
  rep(i,n+2) d[i]=1e200;
  fill(used, false);
  d[n] = 0;
  while(true) {
    /* dumparr(used, n+2); */
    /* dumparr(d,n+2); */
    ll v = -1; // ????????????
    rep(i,n+2){
      if(!used[i] && (v == -1 || d[i] < d[v])) v = i;
    }
    /* dbg(v); */
    if(v==-1) break; // ???
    used[v] = true;
    rep(u,n+2) { 
      /* dbg(sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]))); */
      double dist = mmax(0, sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]))-r[u]-r[v]);
      d[u] = mmin( d[u], d[v]+dist );
    }
  }
  /* dumparr(d, n+2); */
  printf("%.10f\n", d[n+1]);

  return 0;
}