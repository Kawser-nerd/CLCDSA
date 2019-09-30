#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cmath>

#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define zero(a) memset(a, 0, sizeof(a))
#define all(a) (a).begin(), (a).end()

#define IS(a, i) (((a) >> (i)) & 1)

typedef long long ll;
typedef vector <int> vi;

int Int( string s ) { int x; stringstream ss(s); ss >> x; return x; }
string Str( int x ) { stringstream ss; ss << x; return ss.str(); }

int k;
ll C;

int main() 
{
  int tn;
  scanf("%d", &tn);
  
  forab (tt, 1, tn)
  {
    scanf("%d"I64, &k, &C);
	fprintf(stderr, "k=%d C="I64"\n", k, C);

	int cnt = 0;
	ll sum = 0, ans = 0, i = 1;
	while (1)
	{
	  if (i * k <= sum)
	    i = sum / k + 1;
	  if (i > C)
	    break;
	  
	  ll num = k - sum / i;
	  assert(num > 0);
	  sum += num * i, ans += num;
//	  fprintf(stderr, "%d: i="I64" num="I64" sum="I64"\n", ++cnt, i, num, sum);
	}
	printf("Case #%d: "I64"\n", tt, ans);
  }
  return 0;
}
