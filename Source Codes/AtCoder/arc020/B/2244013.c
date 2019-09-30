#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, C, i, j, k, ans = (int)(1e9), now;
	scanf("%d%d", &N, &C);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			if(i != j){
				now = 0;
				for(k = 0; k < N; k++){
					if(k % 2 == 0){
						if(a[k] != i){
							now += C;
						}
					}
					else{
						if(a[k] != j){
							now += C;
						}
					}
				}
				ans = min(ans, now);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &C);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^