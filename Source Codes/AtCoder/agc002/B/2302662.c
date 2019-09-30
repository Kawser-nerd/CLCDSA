#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, M, x, y, i, ans = 0;
	scanf("%d%d", &N, &M);
	int *num = (int *)malloc(sizeof(int) * N);
	int *can_red = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		num[i] = 1;
		can_red[i] = 0;
	}
	can_red[0] = 1;
	for(i = 0; i < M; i++){
		scanf("%d%d", &x, &y);
		x--;
		y--;
		if(can_red[x] == 1){
			can_red[y] = 1;
		}
		if(num[x] == 1){
			can_red[x] = 0;
		}
		num[x]--;
		num[y]++;
	}
	for(i = 0; i < N; i++){
		ans += can_red[i];
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x, &y);
   ^