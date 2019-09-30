#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[100010], b[100010];

typedef struct {
	int a;
	int b;
} square;
square topleft[900010];

int sqcmp(const void *a, const void *b) {
	int A = (*(square *)a).a - (*(square *)b).a;
	int B = (*(square *)a).b - (*(square *)b).b;
	if (A>0 || (A==0 && B>0)) return 1;
	else if (A==0 && B==0) return 0;
	else return -1;
}

int main() {
	int i, j, k, N;
	long long H, W, num[10]={0};
	scanf("%lld%lld%d", &H, &W, &N);
	for (i=0;i<N;i++) scanf("%d%d", &a[i], &b[i]);

	j = 0;
	for (i=0;i<N;i++) {
		if (a[i]>2 && b[i]>2) {
			topleft[j].a = a[i]-2;
			topleft[j].b = b[i]-2;
			j++;
		}
		if (a[i]>1 && a[i]<H && b[i]>2) {
			topleft[j].a = a[i]-1;
			topleft[j].b = b[i]-2;
			j++;
		}
		if (a[i]<H-1 && b[i]>2) {
			topleft[j].a = a[i];
			topleft[j].b = b[i]-2;
			j++;
		}
		if (a[i]>2 && b[i]>1 && b[i]<W) {
			topleft[j].a = a[i]-2;
			topleft[j].b = b[i]-1;
			j++;
		}
		if (a[i]>1 && a[i]<H && b[i]>1 && b[i]<W) {
			topleft[j].a = a[i]-1;
			topleft[j].b = b[i]-1;
			j++;
		}
		if (a[i]<H-1 && b[i]>1 && b[i]<W) {
			topleft[j].a = a[i];
			topleft[j].b = b[i]-1;
			j++;
		}
		if (a[i]>2 && b[i]<W-1) {
			topleft[j].a = a[i]-2;
			topleft[j].b = b[i];
			j++;
		}
		if (a[i]>1 && a[i]<H && b[i]<W-1) {
			topleft[j].a = a[i]-1;
			topleft[j].b = b[i];
			j++;
		}
		if (a[i]<H-1 && b[i]<W-1) {
			topleft[j].a = a[i];
			topleft[j].b = b[i];
			j++;
		}
	}
	qsort(topleft, j, sizeof(square), sqcmp);

	for (i=0;i<j;i++) {
		for (k=i+1;k<j;k++) {
			if (topleft[k].a != topleft[i].a || topleft[k].b != topleft[i].b) break;
		}
		num[k-i]++;
		i = k-1;
	}

	num[0] = (H-2)*(W-2);
	for (i=1;i<10;i++) num[0] -= num[i];

	for (i=0;i<10;i++) printf("%lld\n", num[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%d", &H, &W, &N);
  ^
./Main.c:25:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i=0;i<N;i++) scanf("%d%d", &a[i], &b[i]);
                    ^