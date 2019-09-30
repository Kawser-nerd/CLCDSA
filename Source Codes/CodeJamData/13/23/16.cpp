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

int W = 0, N;
char woerter[600000][30];
char text[5000];
int dp[5000][5];

int main() {
	FILE *fd = fopen("garbled_email_dictionary.txt","r");
	for (W = 0; fscanf(fd, "%s ", woerter[W]) == 1; W++)
		;
	fprintf(stderr, "W = %d\n", W);
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%s ", text);
		N = strlen(text);
		REP(i, N+1)
			REP(v, 5)
				dp[i][v] = 1E9;
		dp[0][4] = 0;
		REP(i, N+1) {
			if (i%200 == 0)
				fprintf(stderr, "i=%d\n", i);
			REP(w, W) {
				int vs = -100, vf = -100;
				int l = strlen(woerter[w]);
				if (l+i > N)
					continue;
				bool ok = true;
				int d = 0;
				for (int k = 0; woerter[w][k]; k++) {
					if (woerter[w][k] != text[i+k]) {
						d++;
						if (i+k-vs < 5) {
							ok = false;
							break;
						}
						vs = i+k;
						if (vf == -100)
							vf = i+k;
					}
				}
				REP(v, 5) {
					int vss = vs;
					if (vss == -100)
						vss = i-v-1;
					if (ok && (vf == -100 || vf-(i-v-1) >= 5)) {
						int &t = dp[i+l][min(i+l-vss-1,4)];
						t = min(t, dp[i][v]+d);
					}
				}
			}
		}
		int erg = 1E9;
		REP(v,5)
			erg = min(erg, dp[N][v]);
		printf("%d\n", erg);
	}
	return 0;
}
