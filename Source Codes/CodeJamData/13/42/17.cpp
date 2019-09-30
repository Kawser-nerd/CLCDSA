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
ll N, P;

ll res(ll n, ll p) {
	if (p <= (1ll<<(n-1)))
		return 1;
	else
		return 2*res(n-1,p-(1ll<<(n-1)))+1;
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%lld%lld", &N, &P);
		if (P == (1ll<<N))
			printf("%lld %lld\n", (1ll<<N)-1, (1ll<<N)-1);
		else
			printf("%lld %lld\n", res(N, P)-1, (1ll<<N)-1-res(N,(1ll<<N)-P));
	}
	return 0;
}
