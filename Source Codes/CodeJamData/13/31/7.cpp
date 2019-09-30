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


const int maxn = (int)2e6;
char s[maxn];
const char vowels[] = "aeiou";

bool is_cons(char c) {
  return find(vowels, vowels + strlen(vowels), c) == vowels + strlen(vowels);
}

void solve() {
  int n, len;
  scanf("%s %d",s,&n);             
  len = strlen(s);

  int last = -1, count = 0;
  long long ans = 0;
  
  for(int i = 0; i < len; i++) {
    count += is_cons(s[i]);
    if (i >= n) {
      count -= is_cons(s[i - n]);
    }

    if (count == n) {
      ans += (i - n - last + 1) * (long long )(len - i);
      last = i - n + 1;
    }
  }
  printf("%I64d\n", ans);
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