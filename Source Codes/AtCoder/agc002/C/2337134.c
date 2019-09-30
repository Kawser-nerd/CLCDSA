#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, L, i;
	scanf("%d%d", &N, &L);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	int leave = 0;
	for(i = 1; i < N; i++){
		if(a[i - 1] + a[i] >= L){
			leave = i;
		}
	}
	if(leave == 0){
		printf("Impossible\n");
	}
	else{
		printf("Possible\n");
		for(i = 1; i < leave; i++){
			printf("%d\n", i);
		}
		for(i = N - 1; i > leave; i--){
			printf("%d\n", i);
		}
		printf("%d\n", leave);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &L);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^