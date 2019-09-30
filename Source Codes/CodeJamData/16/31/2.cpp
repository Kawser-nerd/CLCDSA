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

const int MAXN = 1005;

int a[MAXN];
set<pii> s;

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int t;
	scanf("%d", &t);
	forn (tt, t) {
		printf("Case #%d: ", tt + 1);
		int n;
		scanf("%d", &n);
		forn (i, n)
			scanf("%d", &a[i]), s.insert(mp(a[i], i));
		while (sz(s)) {
		 	auto it = --s.end();
		 	if (it->fs == 1) {
				if (sz(s) == 1) {
				 	printf("%c ", it->sc + 'A');
				 	s.clear();
				} else {
					if (sz(s) == 2) {
						auto it2 = it;
						it2--;
					 	printf("%c%c ", it->sc + 'A', it2->sc + 'A');
					 	s.clear();
					}
					else
						printf("%c ", it->sc + 'A'), s.erase(it);
		 		}
		 	} else {
		 		auto it2 = it;
		 		it2--;
		 		if (it2->fs == it->fs) {
		 			auto np1 = *it, np2 = *it2;
		 			s.erase(np1), s.erase(np2);
		 			s.insert(mp(np1.fs - 1, np1.sc));
		 			s.insert(mp(np2.fs - 1, np2.sc));
		 			printf("%c%c ", np1.sc + 'A', np2.sc + 'A');
		 		} else {
		 		   	auto np1 = *it;
		 		   	s.erase(np1);
		 		   	s.insert(mp(np1.fs - 1, np1.sc));
		 		   	printf("%c ", np1.sc + 'A');
		 		}	
		 	}
		}
		puts("");
	}	
	return 0;
}