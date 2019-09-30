#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,a,n) for (int i = (a); i < (n); i++)

int T;
int N, K;
ll s[2000];
ll a[2000];
ll b[2000];

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d %d", &N, &K);
		REP(n,0,N-K+1) {
			scanf("%lld", &s[n]);
		}
		REP(i,0,K) {
			a[i] = b[i] = 0;
			ll t = 0;
			for (int n = i; n+K < N; n += K) {
				t += s[n+1]-s[n];
				a[i] = min(a[i], t);
				b[i] = max(b[i], t);
			}
		}
		ll d = 0, sb = 0;
		REP(i,0,K) {
			b[i] -= a[i];
			s[0] += a[i];
			d = max(d, b[i]);
			sb += b[i];
		}
		if (K*d-sb < (s[0]%K+K)%K)
			d++;
		printf("%lld\n", d);
	}
	return 0;
}
