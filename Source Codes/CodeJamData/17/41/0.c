#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	int T, iT;
	scanf("%d",&T);
	int a[10];
	for (iT = 0; iT < T; iT++) {
		memset(a, 0, sizeof(a));
		int N, P;
		scanf("%d %d",&N,&P);
		int i;
		for (i = 0; i < N; i++) {
			int temp;
			scanf("%d",&temp);
			temp %= P;
			a[temp]++;
		}
		int res = 0;
		int now;
		if (P == 2) {
			
			now = a[0];
			res += now;
			a[0] -= now;

			now = a[1] / 2;
			res += now;
			a[1] -= 2 * now;

			if (a[1] > 0) res++;

		} else if (P == 3) {

			now = a[0];
			res += now;
			a[0] -= now;

			now = a[1];
			if (a[2] < now) now = a[2];
			res += now;
			a[1] -= now;
			a[2] -= now;

			now = a[1] / 3;
			res += now;
			a[1] -= 3 * now;

			now = a[2] / 3;
			res += now;
			a[2] -= 3 * now;

			if (a[1] + a[2] > 0) res++;

		} else if (P == 4) {

			now = a[0];
			res += now;
			a[0] -= now;

			now = a[1];
			if (a[3] < now) now = a[3];
			res += now;
			a[1] -= now;
			a[3] -= now;

			now = a[2] / 2;
			res += now;
			a[2] -= 2 * now;

			now = a[1] / 2;
			if (a[2] < now) now = a[2];
			res += now;
			a[1] -= 2 * now;
			a[2] -= now;

			now = a[3] / 2;
			if (a[2] < now) now = a[2];
			res += now;
			a[3] -= 2 * now;
			a[2] -= now;

			now = a[1] / 4;
			res += now;
			a[1] -= 4 * now;

			now = a[3] / 4;
			res += now;
			a[3] -= 4 * now;

			if (a[1] + a[2] + a[3] > 0) res++;

		}
		printf("Case #%d: %d\n",iT+1,res);
	}
	return 0;
}