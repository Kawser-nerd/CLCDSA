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
		if (0) fprintf(stderr,"Case %d/%d\n",test,nTests);
		
		int N, K;
		scanf("%d%d",&N,&K);
		bool ans = 0;
		int tester = (1<<N)-1;
		if ((tester&K)==tester) {
			ans = 1;
		}

		if (N==30&&ans) fprintf(stderr,"%d?\n",K);
		
		printf("Case #%d: %s\n",test,ans?"ON":"OFF");
	}
}
