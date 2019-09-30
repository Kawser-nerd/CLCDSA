#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

vector<LL> palindromy;

void generuj_palindromy(){
  FOR(i,1,10000000){
  //FOR(i,1,1000){
    VI v;
    int x = i;
    while (x){
      v.PB(x % 10);
      x /= 10;
    }
    reverse(ALL(v));
    REP(foo,2){
      VI v2 = v;
      FORD(j,SIZE(v)-1-foo,0) v2.PB(v[j]);
      LL acc = 0;
      REP(j,SIZE(v2)){
        acc = 10LL * acc + v2[j];
      }
      palindromy.PB(acc);
   //   if (palindromy.size() % 1000 == 0) printf("%d\n",SIZE(palindromy));
    }
  }
}

const int MOD = 1000000007;

int main(){
  generuj_palindromy();
  sort(ALL(palindromy));
  //REP(i,20) printf("%lld ",palindromy[i]);
  //puts("");
  int testy;
  scanf("%d",&testy);
  REP(numer,testy){
    printf("Case #%d: ", numer+1);
    LL l,r;
    scanf("%lld %lld",&l,&r);
    LL parzyste = 0;
    LL nieparzyste = 0;
    LL last = l-1;
    int ile = 0;

    int pos = 0;
    while (pos < SIZE(palindromy)){
      LL x = palindromy[pos];
      if (x < l){
        pos++;
        continue;
      }
      if (x > r){
        if (ile) {
          nieparzyste = (nieparzyste + (r+1-last)) % MOD;
        } else {
          parzyste = (parzyste + (r+1-last)) % MOD;
        }
        break;
      }
      int dlug = (x - last) % MOD;
      if (ile){
        nieparzyste = (nieparzyste + dlug) % MOD;
      } else {
        parzyste = (parzyste + dlug) % MOD;
      }
      last = x;
      ile = 1-ile;
      pos++;
    }

   // printf("suma=%lld r-l+1=%lld\n",nieparzyste+parzyste,r-l+1);
    LL res = parzyste * (parzyste-1) / 2 + nieparzyste * (nieparzyste-1) / 2;
    printf("%lld\n",res % MOD);
  }
  return 0;
}
