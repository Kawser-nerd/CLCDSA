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

int T, N;
int a1[1000];
int a2[1000];
int r[1000];

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d", &N);
		int st = 0;
		REP(i,N) {
			scanf("%d %d", &a1[i], &a2[i]);
			r[i] = 0;
		}
		bool ok = true;
		int erg = N;
		//REP(runde,N) {
		while(st < 2*N) {
			bool fo = false;
			REP(i,N) {
				if (r[i] < 2 && a2[i] <= st) {
					st += 2-r[i];
					r[i] = 2;
					fo = true;
					break;
				}
			}
			if (fo)
				continue;
			int bi = -1, bn = -1;
			REP(i,N) {
				if (r[i] < 1 && a1[i] <= st && a2[i] > bn) {
					bi = i;
					bn = a2[i];
				}
			}
			if (bi == -1) {
				ok = false;
				break;
			}
			st += 1;
			r[bi] = 1;
			erg++;
		}
		if (ok)
			printf("%d\n", erg);
		else
			printf("Too Bad\n");
	}
	return 0;
}
