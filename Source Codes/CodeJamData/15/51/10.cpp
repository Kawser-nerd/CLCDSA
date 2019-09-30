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

int T, N;
ll D;

const int MAXN = 2000000;

ll S[MAXN];
ll M[MAXN];
ll As, Cs, Rs, Am, Cm, Rm;
bool vis[MAXN];
int mi[MAXN];
int ma[MAXN];
bool in[MAXN];

void visit(int n) {
	if (vis[n])
		return;
	vis[n] = true;
	if (n == 0) {
		mi[n] = S[n];
		ma[n] = S[n];
	} else {
		visit(M[n]);
		mi[n] = min((int)S[n], mi[M[n]]);
		ma[n] = max((int)S[n], ma[M[n]]);
	}
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d %lld", &N, &D);
		scanf("%lld %lld %lld %lld", &S[0], &As, &Cs, &Rs);
		scanf("%lld %lld %lld %lld", &M[0], &Am, &Cm, &Rm);
		REP(i,0,N) {
			S[i+1] = (S[i]*As+Cs)%Rs;
			M[i+1] = (M[i]*Am+Cm)%Rm;
		}
		REP(n,1,N)
			M[n] = M[n]%n;
		REP(n,0,N) {
			vis[n] = false;
// 			printf("%d: %lld %lld\n", n, S[n], M[n]);
		}
		VPII vmi, vma;
		REP(n,0,N) {
			visit(n);
			vmi.push_back({mi[n], n});
			vma.push_back({ma[n], n});
			in[n] = false;
		}
		sort(vmi.begin(), vmi.end());
		sort(vma.begin(), vma.end());
		int res = 0;
		int nr = 0;
		int ima = 0;
		REP(imi,0,N) {
			int a = vmi[imi].first;
			while(ima < N && vma[ima].first <= a+D) {
				if (mi[vma[ima].second] >= a) {
// 					printf("put %d at %d\n", vma[ima].second, a);
					nr += !in[vma[ima].second];
					in[vma[ima].second] = true;
				}
				ima++;
			}
// 			printf("have %d at %d\n", nr, a);
			res = max(res, nr);
			
// 			printf("pop %d at %d\n", vmi[imi].second, a);
			nr -= in[vmi[imi].second];
			in[vmi[imi].second] = false;
		}
		printf("%d\n", res);
	}
	return 0;
}
