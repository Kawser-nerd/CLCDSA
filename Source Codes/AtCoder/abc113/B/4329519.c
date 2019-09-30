#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int t;
	int no;
} data_t;

data_t h[1000] = {0};

int sort_dec(const void *a, const void *b)
{
	int dta = ((data_t*)a)->t;
	int dtb = ((data_t*)b)->t;
//	printf("%d %d\n",dta, dtb);
	return (dta - dtb);
}

int main()
{
	int n = 0;
	int t = 0;
	int a = 0;
	int temp = 0;
	int i = 0;
	scanf("%d", &n);
	scanf("%d %d", &t, &a);
	a = a * 1000;
	t = t * 1000;
	for(i = 0; i < n; i++) {
		scanf("%d",&temp);
		h[i].t = abs((t - (temp * 6)) - a);
		h[i].no = i+1;
//		printf("%d %d\n", h[i].t, h[i].no);
	}

	qsort(h, n, sizeof(data_t), sort_dec);
	printf("%d\n",h[0].no);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &t, &a);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&temp);
   ^