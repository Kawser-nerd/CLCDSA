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
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int boss[1000124];
int getboss(int x) {
  if (x==boss[x]) return x;
  return boss[x] = getboss(boss[x]);
}

#define SIEVE_MAX 1234580
#define ISPRIME(n) (!(__sito[(n)>>4] & (1<<(((n)>>1)&7)))) /* only works for odd values */
unsigned char __sito[ (SIEVE_MAX>>4) + 47 ];

int main(void) {
  memset(__sito,0,sizeof(__sito));
  int __odm = int(3+sqrt(double(SIEVE_MAX)));
  for(int i=3;i<=__odm;i+=2) if(ISPRIME(i)){ int j=i*i; while(j<SIEVE_MAX){ __sito[j>>4]|=(1<<((j>>1)&7)); j+=i<<1; }}
  vector<int> primes(1,2); for (int i=3; i<SIEVE_MAX; i+=2) if (ISPRIME(i)) primes.push_back(i);

  int T;
  cin >> T;
  FOR(t,1,T) {
    long long A, B, P;
    cin >> A >> B >> P;
    for (long long x=A; x<=B; x++) boss[x-A] = x-A;
    for (int i=0; i<SIZE(primes); i++) {
      long long p = primes[i];
      if (p < P) continue;
      long long lo = ((A+p-1)/p)*p;
      for (long long hi=lo+p; hi<=B; hi+=p) {
        int aa = lo-A, bb = hi-A;
        aa = getboss(aa);
        bb = getboss(bb);
        boss[bb] = aa;
      }
    }
    int res = 0;
    for (long long x=A; x<=B; x++) if (boss[x-A] == x-A) res++;
    cout << "Case #" << t << ": " << res << endl;
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
