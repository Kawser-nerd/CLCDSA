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

void addDigits(int num, set<int>& s) {
  while (num) {
    s.insert(num % 10);
    num /= 10;
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  FOR(cas, 1, n) {
    cout << "Case #" << cas << ": ";
    int a;
    set<int> s;
    cin >> a;
    if (a == 0) {
      cout << "INSOMNIA\n";
      continue;
    }
    for (int i = 1; ; i++) {
      addDigits(i * a, s);
      if (SIZE(s) == 10) {
        cout << (i * a) << '\n';
        break;
      }
    }
  }

  return 0;
}

/*************************************************************************/
