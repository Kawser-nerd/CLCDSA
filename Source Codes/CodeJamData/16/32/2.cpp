#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 105;

int a[MAX_N][MAX_N];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int t;
	scanf("%d", &t);
	forn (tt, t) {
		ll b, m;
		scanf(I64 I64, &b, &m);
		printf("Case #%d: ", tt + 1);
		if (m > (1ll << (b - 2))) {
			puts("IMPOSSIBLE");
			continue;
		}
		puts("POSSIBLE");
		forn (i, b)
			forn (j, b)
				a[i][j] = 0;
		forn (i, b - 1)
			forab (j, i + 1, b - 1)
				a[i][j] = 1;
		fornr (i, b - 2)
			if (m >= (1ll << i)) {
				m -= (1ll << i);
				a[i + 1][b - 1] = 1;
			}
		assert(m <= 1);
		if (m == 1)
			a[0][b - 1] = 1;
		forn (i, b) {
			forn (j, b)
				printf("%d", a[i][j]);
			puts("");
		}
	}	

	return 0;
}