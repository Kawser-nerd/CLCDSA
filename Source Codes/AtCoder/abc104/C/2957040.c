#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int D, G, i, j, S, now_solve, now_score, ans = (int)(1e9);
	scanf("%d%d", &D, &G);
	int *p = (int *)malloc(sizeof(int) * D);
	int *c = (int *)malloc(sizeof(int) * D);
	for(i = 0; i < D; i++){
		scanf("%d%d", &p[i], &c[i]);
	}
	for(S = 0; S < (1 << D); S++){
		now_solve = 0;
		now_score = 0;
		for(i = 0; i < D; i++){
			if((S | (1 << i)) == S){
				now_solve += p[i];
				now_score += c[i] + 100 * (i + 1) * p[i];
			}
		}
//		printf("S = %d\n", S);
//		printf("(solve, score) = (%d, %d)\n", now_solve, now_score);
		for(i = D - 1; i >= 0 && now_score < G; i--){
			if((S & (1 << i)) == 0){
				for(j = 0; j < p[i] && now_score < G; j++){
					now_solve++;
					now_score += 100 * (i + 1);
				}
			}
		}
		ans = min(ans, now_solve);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &D, &G);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &p[i], &c[i]);
   ^