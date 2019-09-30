#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int n,k;
	int *L,ans = 0,max,maxi;
	scanf("%d%d",&n,&k);
	L = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)	scanf(" %d",&L[i]);
	for (int i = 0; i < k; ++i){
		max = -1;
		for (int i = 0; i < n; ++i){
			if(max < L[i]){
				max = L[i];
				maxi = i;
			}
		}
		ans += max;
		L[maxi] = -1;
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:14:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (int i = 0; i < n; ++i) scanf(" %d",&L[i]);
                              ^