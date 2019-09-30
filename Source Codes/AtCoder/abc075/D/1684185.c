#include <stdio.h>
#include <limits.h>

int main(void) {
	int i, ix, jx, iy, jy, l, m, N, K;
	long long x[50], y[50], lx, ly, sx, sy, R, S;
	scanf("%d%d", &N, &K);
	for (i=0;i<N;i++) {
		scanf("%lld%lld", &x[i], &y[i]);
	}

	S = LLONG_MAX;
	for (ix=1;ix<N;ix++) {
		for (jx=0;jx<ix;jx++) {
			if (x[ix] < x[jx]) {
				lx = x[jx]; sx = x[ix];
			} else {
				lx = x[ix]; sx = x[jx];				
			}
			for (iy=1;iy<N;iy++) {
				for (jy=0;jy<N;jy++) {
					if (y[iy] < y[jy]) {
						ly = y[jy]; sy = y[iy];
					} else {
						ly = y[iy]; sy = y[jy];				
					}
					R = (lx-sx)*(ly-sy);
					m = 0;
					for (l=0;l<N;l++) {
						if (x[l] <= lx && x[l] >= sx && y[l] <= ly && y[l] >= sy) m++;
					}
					if (m>=K) {
						if (R<S) S = R;
					}							
				}
			}
		}
	}

	printf("%lld\n", S);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &x[i], &y[i]);
   ^