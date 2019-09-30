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
		
		int nCombine, nDestroy, nThings;
		scanf("%d ",&nCombine);
		char combine[nCombine][3];
		for (int i = 0; i < nCombine; i++) {
			for (int j = 0; j < 3; j++) scanf("%c",&combine[i][j]);
			scanf(" ");
		}

		scanf("%d ",&nDestroy);
		char destroy[nDestroy][2];
		for (int i = 0; i < nDestroy; i++) {
			for (int j = 0; j < 2; j++) scanf("%c",&destroy[i][j]);
			scanf(" ");
		}
		
		scanf("%d ",&nThings);
		char stack[nThings];
		int stacksize=0;
		vector<int> present = vector<int>(26,0);
		for (int i = 0; i < nThings; i++) {
			scanf("%c",&stack[stacksize]);
			stacksize++;
			present[stack[stacksize-1]-'A']++;
			// perform replacements
			while (stacksize > 1) {
				int combineID=-1;
				for (int j = 0; j < nCombine; j++) {
					if (stack[stacksize-2]==combine[j][1] && stack[stacksize-1]==combine[j][0]) {
						combineID = j;
						break;
					}
					if (stack[stacksize-2]==combine[j][0] && stack[stacksize-1]==combine[j][1]) {
						combineID = j;
						break;
					}
				}
				if (combineID==-1) break;
				present[stack[stacksize-1]-'A']--;
				present[stack[stacksize-2]-'A']--;
				stacksize--;
				stack[stacksize-1] = combine[combineID][2];
				present[stack[stacksize-1]-'A']++;
			}

			for (int j = 0; j < nDestroy; j++) {
				if (present[destroy[j][0]-'A'] && present[destroy[j][1]-'A']) {
					stacksize = 0;
					present = vector<int>(26,0);
					break;
				}
			}
		}
		
		printf("Case #%d: [",test);
		for (int i = 0; i < stacksize; i++) {
			printf("%c",stack[i]);
			if (i != stacksize-1) printf(", ");
		}
		printf("]\n");
	}
}
