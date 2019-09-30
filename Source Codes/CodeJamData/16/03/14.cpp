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


int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;

  FOR(cas, 1, T) {
    cout << "Case #" << cas << ":\n";
   
    int n, j;
    cin >> n >> j;
    
    REP(mask, j) {
      VI num(n);
      num[0] = num[n - 1] = 1;
      REP(i, 10) {
        if (mask & (1 << i)) {
          num[2 * i + 1] = num[2 * i + 2] = 1;
        }
      }
      REP(i, n) cout << num[i];
      cout << ' ';
      FOR(i, 2, 10) cout << (i + 1) << ' ';
      cout << '\n';
    }
  }

  return 0;
}

/*************************************************************************/
