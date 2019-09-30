#ifdef DEBUG
	#define D(x...) fprintf(stderr,x);
#else
	#define D(x...) 0
#endif
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main() {
	int nTests;
	scanf("%d",&nTests);
	for (int test=1;test<=nTests;test++) {
		if (1) fprintf(stderr,"Case %d/%d\n",test,nTests);
		long long nRuns, k; int nGroups;
		scanf("%lld%lld%d",&nRuns,&k,&nGroups);
		long long g[nGroups];
		for (int i = 0; i < nGroups; i++) {
			scanf("%lld",&g[i]);
		}

		// calculate the effect of each ride (directed 1-out graph)
		int next[nGroups];
		long long profit[nGroups];
		for (int start = 0; start < nGroups; start++) {
			long long tot=0;
			next[start] = start;
			for (int i = start; i < start+nGroups; i++) {
				if (tot + g[i%nGroups] > k) break;
				tot += g[i%nGroups];
				next[start] = i+1;
			}
			profit[start] = tot;
			next[start] %= nGroups;
		}

		vector<bool> visited = vector<bool>(nGroups,0);
		vector<int> history;
		vector<long long> cprofit;
		int loop_pt=-1;
		{ int curloc = 0; // where we are as we walk along the path
		for (int i = 0; ; i++) {
			if (visited[curloc]) {
				for (int j = 0; j < i; j++) {
					if (history[j]==curloc) loop_pt = j;
				}
				break;
			}
			visited[curloc] = 1;
			history.push_back(curloc);
			cprofit.push_back((i==0?0:cprofit[i-1])+profit[curloc]);
			curloc = next[curloc];
		}
		}

		long long ans;
		if (nRuns <= loop_pt) {
			ans = cprofit[nRuns-1];
		} else {
			long long loop_profit = cprofit[cprofit.size()-1] - (loop_pt==0?0:cprofit[loop_pt-1]);
			long long loop_len = cprofit.size() - loop_pt;
			ans = cprofit[loop_pt];
			nRuns -= loop_pt+1;
			ans += loop_profit * (nRuns/loop_len) + (cprofit[loop_pt+(nRuns%loop_len)]-cprofit[loop_pt]);
		}
		
		printf("Case #%d: %lld\n",test,ans);
	}
}
