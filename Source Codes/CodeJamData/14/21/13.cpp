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
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,a,n) for (int i = (a); i < (n); i++)

int T;
char line[1000];
int N;
vector<pair<char,int> > v[1000];
vector<pair<char,int> > w;

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d", &N);
		bool ok = true;
		REP(i,0,N) {
			v[i].clear();
			scanf("%s", line);
			char prev = line[0];
			int nr = 0;
			for (int p = 0; ; p++) {
				if (prev != line[p]) {
					v[i].push_back(make_pair(prev, nr));
					prev = line[p];
					nr = 0;
				}
				nr++;
				if (!line[p])
					break;
			}
			if (v[i].size() != v[0].size())
				ok = false;
		}
		ll res = 0;
		if (ok) {
			REP(j,0,(int)v[0].size()) {
				w.clear();
				REP(i,0,N)
					w.push_back(v[i][j]);
				sort(w.begin(), w.end());
				if (w[0].first != w[N-1].first) {
					ok = false;
					break;
				}
				REP(i,0,N)
					res += abs(w[i].second - w[N/2].second);
			}
		}
		if (ok)
			printf("%lld\n", res);
		else
			printf("Fegla Won\n");
	}
	return 0;
}
