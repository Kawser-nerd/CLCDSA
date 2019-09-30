#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
typedef long double ld;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}


int N;
ld F;
char li[1000000];
int s[1000000];

/*int chk(ld d) {
	vector<pair<ld,ld> > v;
	REP(i,0,N+1) {
		v.push_back({s[i]-i*(F-d), s[i]-i*(F+d)});
	}
	sort(v.begin(), v.end());
	ld mar = -1e100;
	for (auto &p : v) {
		if (mir >= p.second)
	}
}*/

const ld EPS = 1e-18;

void docase() {
	scanf("%d %Lf %s ", &N, &F, li);
	s[0] = 0;
	REP(i,0,N)
		s[i+1] = s[i]+(li[i] == '1');
	/*ld a = -1e-50, b = 1;
	REP(ru,0,1000) {
		ld m = (a+b)/2;
		if (chk(m) != -1)
			b = m;
		else
			a = m;
	}
	assert(chk(a) == -1 && chk(b) != -1);
	printf("%lld\n", chk(b));*/
	ld be = 2;
	int bei = -1;
	REP(i,0,N+1) REP(j,i+1,N+1) {
		ld h = abs((ld)(s[j]-s[i])/(j-i)-F);
// 		printf("%d-%d => h=%Lf\n", i, j, h);
		if (be > h+EPS) {
			be = h;
			bei = i;
// 			printf("be = %.30Lf, bei = %d\n", be, bei);
		} else if (be > h-EPS) {
			be = h;
			setmin(bei, i);
		}
	}
	printf("%d\n", bei);
}

int main() {
	int T;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
