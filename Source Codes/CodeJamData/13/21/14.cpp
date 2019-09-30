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

int T, A, N;
int si[200];

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d%d", &A, &N);
		REP(i, N)
			scanf("%d", si+i);
		sort(si, si+N);
		int erg = 1E9;
		for (int r = 0; r <= N; r++) {
			int o = N-r;
			int a = A;
			for (int i = 0; i < r; i++) {
				while(a <= si[i]) {
					if (a == 1) {
						o = 1E9;
						a = 2;
					} else {
						a += a-1;
						o++;
					}
				}
				a += si[i];
			}
			erg = min(erg, o);
		}
		printf("%d\n", erg);
	}
	return 0;
}
