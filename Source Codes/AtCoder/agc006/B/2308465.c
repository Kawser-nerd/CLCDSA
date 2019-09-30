#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, x, i, j;
	scanf("%d%d", &N, &x);
	if(x == 1 || x == 2 * N - 1){
		printf("No\n");
	}
	else{
		printf("Yes\n");
		int *is_used = (int *)malloc(sizeof(int) * 2 * N);
		int *ans = (int *)malloc(sizeof(int) * 2 * N);
		for(i = 1; i < 2 * N; i++){
			is_used[i] = 0;
			ans[i] = -1;
		}
		if(x == 2){
			ans[N] = 2;
			ans[N + 1] = 1;
			is_used[2] = 1;
			is_used[1] = 1;
		}
		else{
			ans[N] = x;
			ans[N + 1] = x + 1;
			ans[N - 1] = x - 1;
			ans[N + 2] = x - 2;
			is_used[x] = 1;
			is_used[x + 1] = 1;
			is_used[x - 1] = 1;
			is_used[x - 2] = 1;
		}
/*		for(i = 1; i < 2 * N; i++){
			printf("%d  ", is_used[i]);
		}
		printf("\n");
		for(i = 1; i < 2 * N; i++){
			printf("%d  ", ans[i]);
		}
		printf("\n");
*/		for(i = 1, j = 1; i < 2 * N; i++){
			if(ans[i] > 0){
				printf("%d\n", ans[i]);
			}
			else{
				while(is_used[j] == 1 && j < 2 * N){
					j++;
				}
				printf("%d\n", j);
				j++;
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &x);
  ^