#include <stdio.h>

int main(){
	int R, C, D, A, i, j, ans = 0;
	scanf("%d%d%d", &R, &C, &D);
	for(i = 0; i < R; i++){
		for(j = 0; j < C; j++){
			scanf("%d", &A);
			if((i + j - D) % 2 == 0 && i + j <= D && A > ans){
				ans = A;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &R, &C, &D);
  ^
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &A);
    ^