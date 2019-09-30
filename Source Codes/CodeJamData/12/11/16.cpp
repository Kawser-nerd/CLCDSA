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
#define MOD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,n) for (int i = 0; i < (n); i++)

int T;
long double p[100010];

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		int A, B;
		scanf("%d %d", &A, &B);
		REP(i,A)
			scanf("%Lf", &p[i]);
		long double erg = B+2;
		long double pp = 1;
		for (int s = 0; s <= A; s++) {
			long double h = A-2*s+B+1+(B+1)*(1-pp);
			pp *= p[s];
			//printf("%Lf\n", h);
			erg = min(erg, h);
		}
		printf("%.9Lf\n", erg);
	}
	return 0;
}
