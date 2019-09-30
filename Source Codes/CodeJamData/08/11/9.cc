#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORI(i,v) FOR(i,(int)v.size())
#define BEND(v) v.begin(),v.end()
typedef long long ll; typedef long double ld;

int cas = 0,n;
ll xs[1024],ys[1024];
void doit() {
  scanf("%d",&n);
  FOR(i,n) scanf("%lld",&xs[i]);
  FOR(i,n) scanf("%lld",&ys[i]);
  sort(&xs[0],&xs[n]);
  sort(&ys[0],&ys[n]);
  reverse(&ys[0],&ys[n]);

  ll ans = 0;
  FOR(i,n) ans += xs[i]*ys[i];
  printf("Case #%d: %lld\n",++cas,ans);
}
int T;
int main() {
scanf("%d",&T);
FOR(i,T)doit();
}
