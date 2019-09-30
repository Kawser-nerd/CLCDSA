#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define SIZE(c) (int) (c).size()
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

using namespace std;

typedef long long int LLI;
typedef pair < int , int > PII;
typedef pair < LLI , LLI > PLL;

typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < PII > VP;
typedef vector < LLI > VL;
typedef vector < PLL > VPL;

typedef vector < VI > VVI;
typedef vector < VL > VVL;
typedef vector < VB > VVB;
typedef vector < VP > VVP;

/*************************************************************************/

LLI mypow(LLI a, LLI p) {
  LLI ans = 1;
  while(p--) ans *= a;
  return ans;
}


int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;

  FOR(cas, 1, T) {
    cout << "Case #" << cas << ": ";
   
    LLI base, expo, pos;
    cin >> base >> expo >> pos;

    if (pos * expo < base) {
      cout << "IMPOSSIBLE\n";
      continue;
    }

    LLI cur = 0;
    REP(digit, base) {
      cur += digit * mypow(base, digit % expo);
      if (digit % expo == expo - 1 || digit == base - 1) {
        cout << (cur + 1) << ' ';
        cur = 0;
      }
    }
    cout << '\n';
  }

  return 0;
}

/*************************************************************************/
