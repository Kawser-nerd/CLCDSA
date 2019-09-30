#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
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

  int n;
  cin >> n;

  FOR(cas, 1, n) {
    cout << "Case #" << cas << ": ";
    
    string s;
    cin >> s;
    int ans = 0;
    FOR(i, 1, SIZE(s) - 1) ans += s[i] != s[i - 1];
    ans += s.back() == '-';

    cout << ans << '\n';
  }

  return 0;
}

/*************************************************************************/
