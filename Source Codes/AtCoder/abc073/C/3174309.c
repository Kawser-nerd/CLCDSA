#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*16??????????????*/
int compare_int(const void *a, const void *b){return *(int*)a - *(int*)b;}

int main(void){
	int N,i,ans=0,j;
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	qsort(A, N, sizeof(int), compare_int);
	int c = 1;
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(A[i] == A[j]) c++;
			else break;
		}
		ans += c%2;
		c = 1;
		i = j-1;
	}
	
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A[i]);
   ^