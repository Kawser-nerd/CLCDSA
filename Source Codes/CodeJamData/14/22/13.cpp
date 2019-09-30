#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,a,n) for (int i = (a); i < (n); i++)

int T;
ll A, B, C;

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%lld%lld%lld", &A, &B, &C);
		ll res = 0;
		REP(a,0,32) REP(b,0,32) REP(c,0,32) {
			if ((A>>a)%2 == 0 || (B>>b)%2 == 0 || (C>>c)%2 == 0)
				continue;
			ll ra = A&~((1ll<<(a+1))-1);
			ll rb = B&~((1ll<<(b+1))-1);
			ll rc = C&~((1ll<<(c+1))-1);
			ll h = 1;
			REP(i,0,32) {
				if (i < c) {
					if (i < a)
						h *= 2;
					if (i < b)
						h *= 2;
				} else {
					if (i >= a && i >= b) {
						if ((rc>>i)%2 != ((ra>>i)&(rb>>i))%2)
							h = 0;
					} else if (i < a && i < b) {
						if ((rc>>i)%2 == 0)
							h *= 3;
					} else if (i < a && i >= b) {
						if ((rc>>i)%2 == 1) {
							if ((rb>>i)%2 == 0)
								h = 0;
						} else {
							if ((rb>>i)%2 == 0)
								h *= 2;
						}
					} else if (i >= a && i < b) {
						if ((rc>>i)%2 == 1) {
							if ((ra>>i)%2 == 0)
								h = 0;
						} else {
							if ((ra>>i)%2 == 0)
								h *= 2;
						}
					}
				}
			}
// 			if (h)
// 				printf("%d,%d,%d: %lld\n", a, b, c, h);
			res += h;
		}
		assert(res <= A*B);
		printf("%lld\n", res);
	}
	return 0;
}
