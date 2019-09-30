#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int H, W, C, i, j, k, l, ans = 0;
	scanf("%d%d", &H, &W);
	int **black = (int **)malloc(sizeof(int *) * (H + 1));
	int **white = (int **)malloc(sizeof(int *) * (H + 1));
	for(i = 0; i <= H; i++){
		black[i] = (int *)malloc(sizeof(int) * (W + 1));
		white[i] = (int *)malloc(sizeof(int) * (W + 1));
		for(j = 0; j <= W; j++){
			black[i][j] = 0;
			white[i][j] = 0;
		}
	}
	for(i = 1; i <= H; i++){
		for(j = 1; j <= W; j++){
			scanf("%d", &C);
			if((i + j) % 2 == 0){
				black[i][j] = C;
			}
			else{
				white[i][j] = C;
			}
		}
	}
	for(i = 1; i <= H; i++){
		for(j = 1; j <= W; j++){
			black[i][j] += black[i - 1][j] + black[i][j - 1] - black[i - 1][j - 1];
			white[i][j] += white[i - 1][j] + white[i][j - 1] - white[i - 1][j - 1];
		}
	}
	for(i = 0; i < H; i++){
		for(j = 0; j < W; j++){
			for(k = i + 1; k <= H; k++){
				for(l = j + 1; l <= W; l++){
					if(black[k][l] - black[i][l] - black[k][j] + black[i][j]
						 == 
						 white[k][l] - white[i][l] - white[k][j] + white[i][j]){
						ans = max(ans, (k - i) * (l - j));
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:28:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &C);
    ^