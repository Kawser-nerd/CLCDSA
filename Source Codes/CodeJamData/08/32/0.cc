/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
//#include <string>
//#include <map>
//#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;
typedef long long ll;

void init() {
}



int N;
char num[50];
ll ways[50][2][3][5][7];

int Mod(int b, int e, int m) {
  int r = 0;
  for (int i = b; i < e; ++i) {
    r = (10*r+(num[i]-'0')) % m;
  }
  return r;
}

ll Ways(int pos, int mod2, int mod3, int mod5, int mod7) {
  //  printf("go %d %d %d %d %d\n",	 pos, mod2, mod3, mod5, mod7);
  assert(mod2 >= 0 && mod2 <= 1);
  assert(mod3 >= 0 && mod3 <= 2);
  assert(mod5 >= 0 && mod5 <= 4);
  assert(mod7 >= 0 && mod7 <= 6);
  if (pos == N) return mod2 == 0 || mod3 == 0 || mod5 == 0 || mod7 == 0;
  ll &res = ways[pos][mod2][mod3][mod5][mod7];
  if (res == -1) {
    res = 0;
    for (int np = pos+1; np <= N; ++np) {
      int m2 = Mod(pos, np, 2);
      int m3 = Mod(pos, np, 3);
      int m5 = Mod(pos, np, 5);
      int m7 = Mod(pos, np, 7);
      res += Ways(np, (mod2+m2) % 2, (mod3+m3) % 3, (mod5+m5) % 5, (mod7+m7) % 7);
      assert(res <= 4052555153018976267LL);
      if (pos > 0) {
	res += Ways(np, (mod2+2-m2) % 2, (mod3+3-m3) % 3, (mod5+5-m5) % 5, (mod7+7-m7) % 7);
	assert(res <= 4052555153018976267LL);
      }
    }
  }
  return res;
}

void solve(int P) {
  
  scanf("%s", num);
  N = strlen(num);
  memset(ways, -1, sizeof(ways));
  
  printf("Case #%d: %lld\n", P, Ways(0, 0, 0, 0, 0));
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
