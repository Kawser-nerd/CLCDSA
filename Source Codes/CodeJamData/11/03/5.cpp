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
		
		int N; scanf("%d",&N);

		int sum=0, smallest=0, xors=0;
		for (int i = 0; i < N; i++) {
			int tmp; scanf("%d",&tmp);
			sum += tmp;
			xors ^= tmp;
			if (i == 0 || smallest > tmp) smallest = tmp;
		}
		
		if (N == 1 || xors != 0) {
			printf("Case #%d: NO\n",test);
		} else {
			printf("Case #%d: %d\n",test,sum - smallest);
		}
	}
}
