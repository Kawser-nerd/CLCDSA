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
#define sz(a) (int)(a).size()

#define pb push_back
#define mp make_pair
#define zero(a) memset(a, 0, sizeof(a))
#define all(a) (a).begin(), (a).end()

#define IS(a, i) (((a) >> (i)) & 1)

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

const int maxn = 100;

int Int( string s ) { int x; stringstream ss(s); ss >> x; return x; }
string Str( int x ) { stringstream ss; ss << x; return ss.str(); }

int n, n1, n2;
ll F, x[maxn], y[maxn];

int cnt = 0;
ll res;
vll a[maxn], b[maxn];

void go( int i, int deg, ll sum, ll *x, int n, vll *v )
{
  if (i == n - 1)
  {
    cnt++;
    if (sum <= F)
	  v[deg / 2].pb(sum);
	return;
  }
  #define GO(deg)     go(i + 1, deg, sum + (deg) * abs(x[i + 1] - x[i]), x, n, v)
  if (deg > 0)
    GO(deg);
  if (deg > 2)
    GO(deg - 2);
  GO(deg + 2);
}

void Do( vll A, vll B )
{
	int j = 0;
	forn(i, sz(A))
	{
	  while (j < sz(B) && A[i] + B[j] > F)
		j++;
	  if (j < sz(B))
		res = max(res, A[i] + B[j]);
	}
}

int main() 
{
  int tn;
  scanf("%d", &tn);
  
  forab (tt, 1, tn)
  {
	res = -1;
	
    cin >> n;
	forn(i, n)
	  cin >> x[i];
	sort(x, x + n);
	forn(i, n)
	  y[i] = x[n - i - 1];
	cin >> F;
	if (n == 2)
	{
	    ll tmp = 2 * abs(x[0] - x[1]);
		if (tmp <= F)
		  res = tmp;
	}
	else
    {    
		n1 = (n + 1) / 2;
		n2 = n + 1 - n1;	
		
/*
		forn(i, n1)
		  printf("%I64d ", x[i]);
		puts("");
		forn(i, n2)
		  printf("%I64d ", y[i]);
		puts("");
*/

		forn(i, maxn)
		  a[i].clear(), b[i].clear();
		
		go(0, 0, 0, x, n1, a);
		go(0, 0, 0, y, n2, b);
		
		forn(i, maxn)
		{
			sort(all(a[i]));
			sort(all(b[i])), reverse(all(b[i]));
		}
		forn(i, maxn)
		  Do(a[i], b[i]);
		forn(i, maxn - 1)
		  if (i)
		  {
		    Do(a[i], b[i + 1]);
		    Do(a[i + 1], b[i]);
		  }
	}
	
	if (res == -1)
	  printf("Case #%d: NO SOLUTION\n", tt);
	else
	  printf("Case #%d: "I64"\n", tt, res);
	  
	fprintf(stderr, "n=%d cnt=%d\n", n, cnt);
  }
  return 0;
}
