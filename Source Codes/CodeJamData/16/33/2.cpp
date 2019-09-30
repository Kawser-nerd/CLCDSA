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

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int t;
	scanf("%d", &t);	
	forn (tt, t) {
		int j, p, s, k;
	 	scanf("%d%d%d%d", &j, &p, &s, &k);
	 	printf("Case #%d: ", tt + 1);
	 	if (k >= s) {
			printf("%d\n", j * p * s);
			forn (x1, j)
				forn (x2, p)
					forn (x3, s)
						printf("%d %d %d\n", x1 + 1, x2 + 1, x3 + 1);	 	 	
	 		continue;
	 	}
	 	printf("%d\n", j * p * k);
	 	forn (x1, j)
	 		forn (x2, p)
	 			forab (x3, x1 + x2, x1 + x2 + k)
	 				printf("%d %d %d\n", x1 + 1, x2 + 1, (x3 % s) + 1);
	}
	return 0;
}