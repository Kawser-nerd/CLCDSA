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
int P;
ll E[20000];
ll F[20000];
ll Fr[20000];
vector<ll> En;
vector<ll> Fn;
ll res[100];
int sgn[100];

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d:", test+1);
		scanf("%d", &P);
		ll tot = 0;
		REP(i,0,P)
			scanf("%lld", E+i);
		REP(i,0,P) {
			scanf("%lld", F+i);
			tot += F[i];
		}
		int K = 0;
		while(tot != (1ll<<K))
			K++;
		REP(ru,0,K) {
			bool allev = true;
			REP(i,0,P)
				if (F[i]%2)
					allev = false;
			ll d = allev ? 0 : E[1]-E[0];
			bool ok = true;
			En.clear();
			Fn.clear();
			REP(i,0,P)
				Fr[i] = F[i];
			if (d == 0) {
				REP(i,0,P) {
					if (F[i]%2)
						ok = false;
					else {
						En.push_back(E[i]);
						Fn.push_back(F[i]/2);
					}
				}
			} else if (d > 0) {
				int j = 0;
				REP(i,0,P) {
					if (Fr[i] == 0)
						continue;
					while(j < P && E[j] < E[i]+d)
						j++;
					if (E[j] != E[i]+d || Fr[j] < Fr[i])
						ok = false;
					else {
						Fr[j] -= Fr[i];
						En.push_back(E[i]);
						Fn.push_back(Fr[i]);
					}
				}
			} else {
				ok = false;
			}
			assert(ok);
			if (ok) {
				res[ru] = d;
// 				printf(" %lld", d);
			}
			P = En.size();
			REP(i,0,P) {
				E[i] = En[i];
				F[i] = Fn[i];
			}
		}
		map<ll,ll> bla;
		bla[0] = 0;
		REP(i,0,K) {
			map<ll,ll> nbla;
			for (auto &p : bla) {
				if (!nbla.count(p.first))
					nbla[p.first] = p.second;
				else
					nbla[p.first] = max(nbla[p.first], p.second);
				if (!nbla.count(p.first+res[i]))
					nbla[p.first+res[i]] = p.second + (1ll<<i);
				else
					nbla[p.first+res[i]] = max(nbla[p.first+res[i]], p.second + (1ll<<i));
			}
			bla = nbla;
		}
// 		REP(i,0,K)
// 			printf(" %lld", res[i]);
// 		printf("e[0] = %lld\n", E[0]);
		assert(bla.count(-E[0]));
		ll blub = bla[-E[0]];
// 		printf("blub = %lld\n", blub);
		REP(i,0,K)
			sgn[i] = ((blub>>i)&1) ? -1 : 1;
		vector<int> wt;
		REP(i,0,K)
			wt.push_back(res[i]*sgn[i]);
		sort(wt.begin(), wt.end());
		for (ll s : wt)
			printf(" %lld", s);
		printf("\n");
	}
	return 0;
}
