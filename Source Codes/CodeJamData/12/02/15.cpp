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

#define IMPOSSIBLE -9999999

int main() {
	int nTests;
	scanf("%d ",&nTests);
	for (int test=1;test<=nTests;test++) {
		if (1) fprintf(stderr,"Case %d/%d\n",test,nTests);
		int nPeople, nSurprise, threshold;
		scanf("%d%d%d ",&nPeople,&nSurprise,&threshold);

		int maxThresh[nPeople+1][nSurprise+1];
		// n people *used*; n surprise *used*
		maxThresh[0][0] = 0;
		for (int j = 1; j <= nSurprise; j++) maxThresh[0][j] = IMPOSSIBLE;
		for (int i = 1; i <= nPeople; i++) {
			int curVal; scanf("%d",&curVal);
			for (int j = 0; j <= nSurprise; j++) {
				maxThresh[i][j] = maxThresh[i-1][j] + ((curVal+2)/3 >= threshold ? 1 : 0);
				if (j == 0 || curVal < 2 || curVal > 28) continue;
				maxThresh[i][j] = max(maxThresh[i][j], maxThresh[i-1][j-1] + ((curVal+4)/3 >= threshold ? 1 : 0));
			}
		}
		
		printf("Case #%d: %d\n",test,maxThresh[nPeople][nSurprise]);
	}
}
