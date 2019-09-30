// Adrian Kügel
#include <string.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <assert.h>
#include <limits.h>
#include <complex>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;

typedef set<int> SI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef complex<double> tComp;
typedef pair<short, int> PCI;

int c[100], s[100], t[100];
char used[100];

int main() {
	int tc;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d: ", scen);
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d %d %d", &c[i], &s[i], &t[i]);
		int m;
		scanf("%d", &m);
		for (int i=0; i<m; ++i)
			scanf("%d %d %d", &c[i+n], &s[i+n], &t[i+n]);
		int bestscore = 0;
		for (int draw=0; draw<=m; ++draw) {
			memset(used, 0, sizeof(used));
			int ptr = n;
			int score = 0;
			int turns = 1;
			int cards = n;
			while(turns && cards > 0) {
				// play all cards which give more turns
				int max_score = -1, ind;
				int max_score_dc = -1, ind2;
				for (int i=0; i<ptr; ++i) {
					if (used[i]) continue;
					if (t[i] > 0) {
						used[i] = 1;
						--cards;
						--turns;
						turns += t[i];
						score += s[i];
						int add = min(n + m - ptr, c[i]);
						ptr += add;
						cards += add;
					}
					else {
						if (s[i] > max_score) {
							max_score = s[i];
							ind = i;
						}
						if (c[i] > 0 && s[i] > max_score_dc) {
							ind2 = i;
							max_score_dc = s[i];
						}
					}
				}
				if (ptr-n < draw && max_score_dc >= 0) {
					int add = min(n + m - ptr, c[ind2]);
					ptr += add;
					cards += add;
					score += s[ind2];
					used[ind2] = 1;
					--turns;
					--cards;
				}
				else if (max_score >= 0) {
					int add = min(n + m - ptr, c[ind]);
					ptr += add;
					cards += add;
					score += s[ind];
					used[ind] = 1;
					--cards;
					--turns;
				}
			}
			if (score > bestscore)
				bestscore = score;
		}
		printf("%d\n", bestscore);
	}
	return 0;
}
