#include <stdio.h>
#include <stdlib.h>

#define max_size (int)(1e5)

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int N, i, j, ans = 0;
	int *AList = (int *)malloc(sizeof(int) * max_size);
	for(i = 0; i < max_size; i++){
		AList[i] = 0;
	}
	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
		A[i]--;
	}
	for(i = 0, j = 0; i < N; i++){
		while(AList[A[i]] > 0){
			AList[A[j]]--;
			j++;
		}
		AList[A[i]]++;
		ans = max(ans, i - j + 1);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^