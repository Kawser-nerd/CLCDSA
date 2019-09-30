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
		
		long long N, pD, pG;
		scanf("%lld %lld %lld",&N,&pD,&pG);

		bool cando = 1;
		long long D = 1;
		while ((pD*D)%100 != 0) D++;

		if (D > N) {
			cando = 0;
		} else if ((pG == 0 || pG == 100) && (pD != pG)) {
			cando = 0;
		}
		
		printf("Case #%d: %s\n",test,cando?"Possible":"Broken");
	}
}
