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
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

long long p10[100];
vector<long long> palindromes;

long long MOD = 1000000007LL;

int reverse(int x) {
  int res = 0;
  while (x) { res *= 10; res += x%10; x/=10; }
  return res;
}

long long pary(long long x) {
  if (x%2) {
    long long a = (x-1)/2;
    long long b = x;
    return ((a % MOD) * (b % MOD)) % MOD;
  } else {
    long long a = x/2;
    long long b = x-1;
    return ((a % MOD) * (b % MOD)) % MOD;
  }
}

long long solve(long long L, long long R) {
  int x=0;
  while (palindromes[x] < L) ++x;
  bool parita = true;
  long long parne=0, neparne=0, kde=L;

  while (true) {
    long long kam = palindromes[x];
    ++x;
    if (kam > R) kam = R+1;
    if (parita) parne += (kam-kde+1); else neparne += (kam-kde+1);
    parita = !parita;
    kde = kam+1;
    if (kde > R+1) break;
  }
  return (pary(parne) + pary(neparne)) % MOD;
}

int main() {
  p10[0]=1;
  for (int i=1; i<=15; ++i) p10[i] = p10[i-1] * 10;
  for (int d=1; d<=9; ++d) palindromes.push_back(d);
  for (int d=1; d<=6; ++d) {
    for (int i=p10[d-1]; i<p10[d]; ++i) palindromes.push_back( i * p10[d] + reverse(i) );
    for (int i=p10[d-1]; i<p10[d]; ++i) for (int mid=0; mid<10; ++mid) palindromes.push_back( i * p10[d+1] + mid * p10[d] + reverse(i) );
  }
  palindromes.push_back( p10[13] + 1 );

  /*
  for (long long L=10; L<=14; ++L)
  for (long long R=L; L<=23; ++R) {
    long long ja = solve(L,R), on = 0;
    for (int a=L; a<=R; ++a) for (int b=a; b<=R; ++b) {
      int p = 0;
      for (int c=a; c<=b; ++c) if (c == reverse(c)) p = !p;
      if (!p) ++on;
    }
    assert(ja==on);
  }
  */

  int T;
  cin >> T;
  FOR(t,1,T) {
    long long L, R;
    cin >> L >> R;
    printf("Case #%d: %Ld\n",t,solve(L,R)); 
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
