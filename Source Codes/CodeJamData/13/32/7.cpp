/*-----------TEMPLATE---------------*/
//#pragma comment(linker, "/STACK:16777216")

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define eprintf(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define forab(i, a, b) for (int i = (int)(a); i < ((int)(b)); ++i)
#define forit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define forn(i, n) for (int i = 0; i < ((int)(n)); ++i)
#define forabok(i, a, b, ok) for (int i = (int)(a); i < ((int)(b)) && (ok); ++i)
#define foritok(it, v, ok) for (typeof((v).begin()) it = (v).begin(); it != (v).end() && (ok); ++it)
#define fornok(i, n, ok) for (int i = 0; i < ((int)(n)) && (ok); ++i)
#define mp make_pair
#define pb push_back
#define sz(a) ((int)((a).size()))
#define X first
#define Y second
#define ibits(x) __builtin_popcount(x)
#define lbits(x) __builtin_popcountll(x)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

/*-----------TEMPLATE---------------*/


const char nap[] = "EWNS";
vector<int> ans;
vector<bool> used;

bool try_to_fill(int x, int y, int addx, int addy, int n, int sum) {
  int sumx = sum - y;
  ans.resize(n);
  used.resize(n + 1);
  for(int i = 0; i < n; i++) {
    ans[i] = addx;
  }
  for(int i = 0; i <= n; i++) {
    used[i] = false;
  }

//  eprintf("y = %d\n", y);
  for(int i = n; i > 0; i--) {
    if (y >= i && (!(y - i < i - 2) || y == i)) {
      y -= i;
      ans[i - 1] = addy;
      used[i] = true;
    }
  }

  int want = (sumx - x) / 2;
  for(int i = n; i > 0; i--) {
    if (want >= i && !used[i]) {
      want -= i;
      ans[i - 1] = addx ^ 1;
      used[i] = true;
//      eprintf("want = %d, i = %d\n", want, i);
    }
  }

  return want == 0; 
}

void do_find(int x, int y) {
  int sum = 0, n = 0;
  while ((sum < x + y) || (sum % 2 != (x + y) % 2)) {
    n++;
    sum += n;
  }

  bool ok = try_to_fill(x, y, 0, 2, n, sum);
  if (!ok) {
    ok = try_to_fill(y, x, 2, 0, n, sum);
  }                               
//  eprintf("%d %d\n",x,y);
  assert(ok);
}

void solve() {
  int x, y;
  scanf("%d %d", &x, &y);
  do_find(abs(x), abs(y));

  for(int i = 0; i < sz(ans); i++) {
    if ((ans[i] < 2 && x < 0) || (ans[i] >= 2 && y < 0)) {
      ans[i] ^= 1;
    }
    putchar(nap[ans[i]]);
  }
  puts("");
}                      

int main() 
{
  srand(time(NULL));
  #define TASK ""
  #ifdef HOME
  assert(freopen(TASK "in", "rt", stdin));
  assert(freopen(TASK "out", "wt", stdout));
  #endif

  int tests;
  scanf("%d",&tests);
  for(int test = 1; test <= tests; test++) {
    printf("Case #%d: ",test);
    solve();
  }
  return 0;
}