#include<stdio.h>

int main()
{
	int i, j, N;
	int pos, count;
	int w, min;
	int wt[50];
	scanf("%d", &N);
	
	for (i=0; i < 50; i++)
		wt[i] = 0;
	
	count = 0;
	for (i=0; i < N; i++) {
		scanf("%d", &w);
		pos = -1, min = 100000;	//???????????? 
		for (j=0; j < count; j++) {
			if (wt[j] - w >= 0)
				if (wt[j] - w <= min) {
					pos = j;
					min = wt[j] - w;	
				}
		}
		if (pos == -1)
			wt[count++] = w;
		else
			wt[pos] = w; 
	}
	
	printf("%d\n", count);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &w);
   ^