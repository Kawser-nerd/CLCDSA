#include <stdio.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b){return *(int*)a - *(int*)b;}
int main(void){
	int n,m,ans=0;
	scanf("%d %d",&n,&m);
	int x[m];
	for(int i=0;i<m;i++)scanf("%d",&x[i]);
	qsort(x, m, sizeof(int), compare_int);
	int diff[m-1];
	for(int i=0;i<m-1;i++){
		diff[i] = x[i+1] - x[i];
	}
	qsort(diff, m-1, sizeof(int), compare_int);
	for(int i=0;i<m-n;i++){
		ans += diff[i];
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:8:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=0;i<m;i++)scanf("%d",&x[i]);
                      ^