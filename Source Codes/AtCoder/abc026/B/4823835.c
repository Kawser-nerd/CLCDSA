#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare_int(const void *a, const void *b){return *(int*)b - *(int*)a;}
int main(void){
	int N,i;
	scanf("%d",&N);
	int r[N];
	double ans,R=0;
	for(i=0;i<N;i++)scanf("%d",&r[i]);
	qsort(r,N,sizeof(int), compare_int);
	for(i=0;i<N;i++){
		if(i%2==0){
			R += r[i]*r[i];
		}else{
			R -= r[i]*r[i];
		}
	}
	ans = M_PI*R;
	printf("%.20lf\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:10:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++)scanf("%d",&r[i]);
                  ^