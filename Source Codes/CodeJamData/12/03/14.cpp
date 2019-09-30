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
		int A, B; scanf("%d%d",&A,&B);
		int lastPowTen = 1; while (lastPowTen*10 <= A) {lastPowTen *= 10;}
		
		int ans = 0;
		for (int lo = A; lo <= B; lo++) {
			int hi = lo;
			do {
				hi = (hi / lastPowTen) + 10 * (hi % lastPowTen);
				if (lo < hi && hi <= B) {
					ans++;
				}
			} while (lo != hi);
		}
		
		printf("Case #%d: %d\n",test,ans);
	}
}
