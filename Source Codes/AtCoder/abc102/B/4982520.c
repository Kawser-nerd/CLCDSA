#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	scanf("%d", &N);
	int A[N];
	for(int i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
	
	int max=0, tmp;
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			tmp = abs(A[i] - A[j]);
			max = (tmp>max) ? tmp:max;
		}
	}
	printf("%d", max);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^