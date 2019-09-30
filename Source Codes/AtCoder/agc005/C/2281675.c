#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, a, mina = 100000, maxa = 0, i;
	scanf("%d", &N);
	int *anum = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		anum[i] = 0;
	}
	for(i = 0; i < N; i++){
		scanf("%d", &a);
		anum[a]++;
		mina = min(mina, a);
		maxa = max(maxa, a);
	}
	if((maxa + 1) / 2 != mina){
		printf("Impossible\n");
		return 0;
	}
	if(maxa % 2 == 0){
		if(anum[mina] != 1){
			printf("Impossible\n");
			return 0;
		}
	}
	else{
		if(anum[mina] != 2){
			printf("Impossible\n");
			return 0;
		}
	}
	for(i = mina + 1; i <= maxa; i++){
		if(anum[i] < 2){
			printf("Impossible\n");
			return 0;
		}
	}
	printf("Possible\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^