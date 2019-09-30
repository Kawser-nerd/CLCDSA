#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void){
	int N,K;
	scanf("%d %d",&N,&K);
	int h[N];
	int i,j;
	for(i=0;i<N;i++){
		scanf("%d",&h[i]);
	}
	//h[i]??????h[0]?h[K-1]???
	//h[1]?h[K-1+1]?????????????????????
	qsort(h,N, sizeof(int), compare_int);
	int min = abs(h[0] - h[K-1]);
	for(i=0;i<=N-K;i++){
		j = abs(h[0+i] - h[K-1+i]);
		if( min > j){
			min =j;
		}
	}
	printf("%d",min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&K);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&h[i]);
   ^