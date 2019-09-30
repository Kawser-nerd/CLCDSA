// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
template <class T> inline int BITCNT(T x) { int res=0; while (x) { res++; x&=x-1; } return res; }
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
// MODEXP expects: 0<number<2^31, 0<=power<2^63, 0<modulus<2^31
// MODEXP returns: (number^power) % modulus
long long MODEXP(long long number, long long power, long long modulus) { if (power==0) return 1LL % modulus; if (power==1) return number % modulus; long long tmp = MODEXP(number,power/2,modulus); tmp = (tmp*tmp) % modulus; if (power&1) tmp = (tmp*number) % modulus; return tmp; }
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int MOD = 10007;

int INV[12000];
int getfpow(int n) { int res=0; while (1) { n/=MOD; res+=n; if (!n) break; } return res; }

int F[100000047];

int comb(int n, int k) {
  if (k<0 || k>n) return 0;
  int p = getfpow(n) - getfpow(k) - getfpow(n-k);
  if (p>0) return 0;
  long long res = 1;
  res *= F[n];
  res %= MOD;
  res *= INV[F[k]];
  res %= MOD;
  res *= INV[F[n-k]];
  res %= MOD;
  return res;
}

int kon(int n, int k) {
  if ((n+k)%3) return 0;
  int steps = (n+k)/3;
  int left = 2*steps - n;
  return comb(steps,left);
}

int main() {
  FOR(i,1,MOD-1) INV[i] = MODEXP(i,MOD-2,MOD);
  F[0]=1;
  F[1]=1;
  FOR(i,2,100000045) {
    int x = i;
    while (x % MOD == 0) x /= MOD;
    F[i] = ( ((long long)F[i-1]) * x ) % MOD;
  }
  int T;
  cin >> T;
  FOR(t,1,T) {
    int H, W, R;
    cin >> H >> W >> R;
    vector< pair< int,int > > V;
    REP(r,R) {
      int x, y; cin >> x >> y;
      V.push_back(PII(x,y));
    }
    sort(V.begin(),V.end());
    long long res = 0;
    REP(hit,1<<R) {
      int bc = BITCNT(hit), pw = 1; while (bc--) pw *= -1;
      vector< pair<int, int> > Q;
      Q.push_back(PII(1,1));
      REP(r,R) if (hit & (1<<r)) Q.push_back(V[r]);
      Q.push_back(PII(H,W));
      int ok = 1;
      REP(i,SIZE(Q)-1) if (Q[i+1].first < Q[i].first || Q[i+1].second < Q[i].second) ok = 0;
      if (!ok) continue;
      long long toto = 1;
      REP(i,SIZE(Q)-1) {
        int right = Q[i+1].first-Q[i].first;
        int down = Q[i+1].second-Q[i].second;
        toto *= kon(right,down);
        toto %= MOD;
      }
      res += pw * toto;
      res += MOD;
      res %= MOD;
    }
    printf("Case #%d: %lld\n",t,res);
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
