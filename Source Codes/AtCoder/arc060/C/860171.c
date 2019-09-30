#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[100010], b[100010], x[100010], r[100010][20];

int *binary(int *seq, const int len, const int key) {
	int flag, left, mid, right;
	flag = 0; left = 0; right = len-1;
	mid = (left+right)/2;
//	printf("  %d %d %d\n", left, mid, right);
	while (left <= right && flag < 2) {
		if ((left+right)%2) {
			if (*(seq+mid) < key) left = mid + 1;
			else if (*(seq+mid) == key) { left = mid; flag++; }
			else if (*(seq+mid+1) > key) right = mid - 1;
			else if (*(seq+mid+1) == key) { right = mid; flag++; }
			else break;
		} else {
			if (*(seq+mid) < key) left = mid + 1;
			else if (*(seq+mid) > key) right = mid - 1;
			else { right = mid; flag++; }
		}
		mid = (left+right)/2;
//		printf("  %d %d %d\n", left, mid, right);
	}
	return seq+mid;
}

int main() {
	int D, from, i, j, k, L, max, N, *ptr, Q, to;
	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", &x[i]);
	scanf("%d%d", &L, &Q);
	for (j=0;j<Q;j++) scanf("%d%d", &a[j], &b[j]);

	for (i=0;i<N-1;i++) {
		ptr = binary(x, N, x[i]+L);
		r[i][0] = ptr-x+1;
	}
	r[N-1][0] = N+10;

	for (k=1;k<20;k++) {
		for (i=0;i<N-1;i++) {
			if (r[i][k-1] == N+10) r[i][k] = N+10;
			else r[i][k] = r[r[i][k-1]-1][k-1];
		}
		r[N-1][k] = N+10;
	}
//	for (i=0;i<N;i++) for (k=0;k<5;k++) printf("r[%d][%d] = %d\n", i, k, r[i][k]);
//	return 0;
//	printf("\n");

	for (k=0;k<20;k++) {
		if (r[0][k] == N) break;
	}
	max = k+1;

	for (j=0;j<Q;j++) {
		D = 0;
		if (a[j]>b[j]) { from = b[j]; to = a[j]; }
		else { from = a[j]; to = b[j]; }
		do {
			ptr = binary(r[from-1], max, to);
//			printf(" %d %d %d\n", from, to, *ptr);
			i = ptr-r[from-1];
			k = 1;
			while (i-->0) k *= 2;
			D += k;
			from = *ptr;
		} while (*ptr < to);
		printf("%d\n", D);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:33:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i=0;i<N;i++) scanf("%d", &x[i]);
                    ^
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &L, &Q);
  ^
./Main.c:35:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (j=0;j<Q;j++) scanf("%d%d", &a[j], &b[j]);
                    ^