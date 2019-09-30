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
	scanf("%d ",&nTests);
	for (int test=1;test<=nTests;test++) {
		if (1) fprintf(stderr,"Case %d/%d\n",test,nTests);
		
		int N;
		scanf("%d ",&N);
		int time[2] = {0,0}, pos[2] = {1,1};

		for (int i = 0; i < N; i++) {
			char c;
			int bot, but;
			scanf("%c ",&c);
			scanf("%d ",&but);
			bot = (c=='O')?0:1;
			time[bot] = max(time[1-bot],time[bot]+abs(but-pos[bot]));
			time[bot]++;
			pos[bot] = but;
		}
		
		printf("Case #%d: %d\n",test,max(time[0],time[1]));
	}
}
