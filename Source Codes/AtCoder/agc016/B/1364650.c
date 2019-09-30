#include <stdio.h>
#include <stdlib.h>

#define inf (int)(1e9 + 7)

int main(){
	int N, amax = 0, amin = inf, i;
	scanf("%d", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
		if(a[i] > amax){
			amax = a[i];
		}
		if(a[i] < amin){
			amin = a[i];
		}
	}
	if(amax - amin > 1){
		printf("No\n");
	}
	if(amax - amin == 0){
		if(amax == N - 1 || amax <= N / 2){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	if(amax - amin == 1){
		int aminnum = 0;
		for(i = 0; i < N; i++){
			if(a[i] == amin){
				aminnum++;
			}
		}
		if(1 <= amax - aminnum && amax - aminnum <= (N - aminnum) / 2){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^