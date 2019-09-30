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
		int off=0;
		scanf("%d",&N);
		for (int i = 0; i < N; i++) {
			int tmp;
			scanf("%d",&tmp);
			if (tmp != i+1) off++;
		}
		
		// you have got to be kidding me
		printf("Case #%d: %d\n",test,off);
	}
}
