#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
bool check(ll x) {
	vi ls;
	while (x > 0) {
		ls.pb(x % 10);
		x /= 10;
	}
	for (int i = 0; i < sz(ls) - i - 1; i++) {
		if (ls[i] != ls[sz(ls) - i - 1]) {
			return false;
		}
	}
	return true;
}
int main()
{
	#ifdef home
		assert(freopen(TASK".in", "r", stdin));
		assert(freopen(TASK".out", "w", stdout));
	#endif
	ll MX = 1e14;
	vector<ll> ls;
	for (ll i = 1; i * i <= MX; i++) {
		if (check(i) && check(i * i)) {
			ls.pb(i * i);
		}
	}
	int T;
	cin>>T;
	for (int ti = 0; ti < T; ti++) {
		ll x, y;
		cin>>x>>y;
		cout<<"Case #"<<ti + 1<<": "<<lower_bound(all(ls), y + 1) - lower_bound(all(ls), x)<<endl;
	}     	
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}
 