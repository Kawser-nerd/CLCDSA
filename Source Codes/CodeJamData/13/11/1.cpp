#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main() {
	long long mx;
	mx = 2;
	for (int i=0;i<18;i++) mx = mx * 10;
	mx ++;


	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	int T;
	
	scanf("%d",&T);

	long long r, t;
	while( T-- > 0 ) {
		//fprintf(stderr, "%d\n", T);
		// input
		scanf("%lld %lld", &r, &t);

		int sol = 0;
		long long xp;
		xp = 1073741824;
		while (xp > 0) {
			if (mx / r / xp / 2 > 0) {
				long long ux;
				
				ux = r * xp * 2 + 2 * xp * xp - xp;
				if (t >= ux) {
					t -= ux;
					sol += xp;
					r += 2*xp;
				}
			}
			xp = xp / 2;
		}

		// process

		static int cs = 1;
		printf("Case #%d: ", cs++);
		// output
		printf("%d", sol);
		printf("\n");
	}
	return 0;
}