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
int a[3000];
int b[3000];
bool mat[3000][3000];
bool vis[3000];
int t;
int erg[3000];

void visit(int i) {
	if (vis[i])
		return;
	vis[i] = true;
	REP(j, N)
		if (mat[i][j])
			visit(j);
	erg[i] = t;
	t++;
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d", &N);
		REP(i, N)
			scanf("%d", a+i);
		REP(i, N)
			scanf("%d", b+i);
		REP(i, N) {
			REP(j,N) mat[i][j] = false;
			vis[i] = false;
		}
		REP(i, N) {
			REP(j, i) {
				if (a[j] >= a[i])
					mat[j][i] = true;
			}
			for (int j = i-1; j >= 0; j--) {
				if (a[j] == a[i]-1) {
					mat[i][j] = true;
					break;
				}
			}
			for (int j = i+1; j < N; j++) {
				if (b[j] >= b[i])
					mat[j][i] = true;
			}
			for (int j = i+1; j < N; j++) {
				if (b[j] == b[i]-1) {
					mat[i][j] = true;
					break;
				}
			}
		}
		t = 1;
		REP(i, N)
			visit(i);
		REP(i, N) {
			if (i)
				printf(" ");
			printf("%d", erg[i]);
		}
		printf("\n");
	}
	return 0;
}
