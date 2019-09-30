#include <stdio.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b){return *(int*)a - *(int*)b;}
int main(void){
	int n,i,k;
	scanf("%d %d",&n,&k);
	int h[n];
	for(i=0;i<n;i++)scanf("%d",&h[i]);
	qsort(h, n, sizeof(int), compare_int);
	int ans=h[k-1]-h[0];
	for(i=0;i+k<=n;i++){
		int a = h[i+k-1] - h[i];
		if(a < ans)ans = a;
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&k);
  ^
./Main.c:8:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&h[i]);
                  ^