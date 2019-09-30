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

int T, N, M;

vector<PII> qu;
const ll MO = 1000002013;

ll vo(ll a, ll b, ll p) {
	return ((b-a)*(b-a-1)/2) % MO * p % MO;
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d%d", &N, &M);
		qu.clear();
		ll start = 0;
		REP(i, M) {
			int a, b, p;
			scanf("%d%d%d", &a, &b, &p);
			qu.push_back(PII(a,-p));
			qu.push_back(PII(b,p));
			start += vo(a,b,p);
			start %= MO;
		}
		ll end = 0;
		sort(qu.begin(),qu.end());
		stack<PII> st;
		FOREACH(q,qu) {
			int a = q->first, p = q->second;
			if (p < 0) {
				p = -p;
				st.push(PII(a,p));
			} else {
				while(p > 0) {
					if (st.top().second <= p) {
						end += vo(st.top().first, a, st.top().second);
						end %= MO;
						p -= st.top().second;
						st.pop();
					} else {
						end += vo(st.top().first, a, p);
						end %= MO;
						st.top().second -= p;
						p = 0;
					}
				}
			}
		}
		printf("%lld\n", ((end-start)%MO+MO)%MO);
	}
	return 0;
}
