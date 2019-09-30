#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#include <stdio.h>

long long dat[16384];
int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);

	int T;
	
	scanf("%d",&T);

	long long E, R;
	int N;

	while( T-- > 0 ) {
		// input

		scanf("%lld %lld %d",&E,&R,&N);
		for (int i=0;i<N;i++) {
			scanf("%lld",&dat[i]);
		}
		// process
		long long sol = 0;
		for (int i=0;i<N;i++) {
			long long mx;
			int mxi;
			mx = 0;
			mxi = -1;
			for (int j=0;j<N;j++) {
				if (dat[j] > mx) {
					mx = dat[j];
					mxi = j;
				}
			}
			if (mxi == -1) break;

			long long e, r, mr;
			e = E;
			for (int j=0;j<mxi;j++) {
				if (dat[j] < 0) {
					e += dat[j];
				}
				e += R;
				if (e > E) e = E;
			}
			r = mr = 0;
			for (int j=mxi+1;j<N;j++) {
				r += R;
				if (r > E) r = E;
				if (dat[j] < 0) {
					r += dat[j];
				}
				if (mr > r) mr = r;
			}
			e = e + mr;
			sol += e * dat[mxi];
			dat[mxi] = -e;
		}
		static int cs = 1;
		printf("Case #%d: ", cs++);
		// output
		printf ("%lld", sol);
		printf("\n");
	}
	return 0;
}