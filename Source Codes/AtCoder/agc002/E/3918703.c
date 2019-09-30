#include <stdio.h>
#include <stdlib.h>

signed compare(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

int main(){
	int N, i;
	scanf("%d", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
	qsort(a, N, sizeof(int), compare);
	for(i = 0; i < N; i++){
		if(a[i] < i){
			break;
		}
	}
	i--;
	int k = a[i] - i, l;
	for(l = 0; l < N; l++){
		if(a[l] < i){
			break;
		}
	}
	l = l - i - 1;
//	printf("(k, l) = (%d, %d)\n", k, l);
	if(k % 2 == 0 && l % 2 == 0){
		printf("Second\n");
	}
	else{
		printf("First\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^