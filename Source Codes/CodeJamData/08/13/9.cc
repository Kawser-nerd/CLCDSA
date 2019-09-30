#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORI(i,v) FOR(i,(int)v.size())
#define BEND(v) v.begin(),v.end()
#define dump(x) cerr << #x << " = " << (x) << endl;
typedef long long ll; typedef long double ld;

typedef vector<ll> VL; typedef vector<VL> VVL;
typedef VVL Mat;
const ll MOD = 1000;
Mat mult(Mat m, Mat n) {
  int N = m.size();
  Mat o(N,VL(N,0));
  
  FOR(i,N) FOR(j,N) FOR(k,N) {
    assert(m[i][k] >= 0);
    assert(n[k][j] >= 0);
    o[i][j] = (o[i][j] + m[i][k] * n[k][j]) % MOD;
    assert(o[i][j] >= 0);
  }
  
  return o;
}
Mat matexp(Mat m, ll t) {
  int N=m.size();
  Mat r(N,VL(N,0));
  FOR(i,N) r[i][i] = 1;
  
  while (t) {
    if (t%2) {
      r = mult(r, m);
    }
    m = mult(m,m);
    t /= 2;
  }
  
  return r;
}

int cas = 0;
ll n;
void doit() {
  scanf("%lld",&n);

  Mat M(2,VL(2,0));
  M[0][1] = 1;
  M[1][0] = (MOD-4)%MOD;
  M[1][1] = 6;

  M = matexp(M, n);

  ll ans = 2*M[0][0] + 6*M[0][1];
  assert(ans >= 0);
  ans = (ans-1+MOD)%MOD;
  assert(ans >= 0);

  printf("Case #%d: %03lld\n",++cas,ans);
}
int T;
int main() {
scanf("%d",&T);
FOR(i,T)doit();
}
