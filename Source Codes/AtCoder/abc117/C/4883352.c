#include <stdio.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int main(void){
	int N,M;
	int ans = 0;
	int length;
	scanf("%d %d",&N,&M);
	int X[M];
	int Y[M-1];
	int i;
	for(i=0;i<M;i++){
		scanf("%d",&X[i]);
	}
	qsort(X,M,sizeof(int),compare_int);
	for(i=0;i<M;i++){
		if(i>0){
			Y[i-1]=abs(X[i]-X[i-1]);
		}
	}
	qsort(Y,M-1,sizeof(int),compare_int);
	length = abs(X[0]-X[M-1]);
	ans = length;
	int temp = M-2;
	for(i=0;i<N-1;i++){
		ans -=Y[temp];
		temp --;
	}
	if(N>M){
		printf("0");
		return 0;
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&X[i]);
   ^