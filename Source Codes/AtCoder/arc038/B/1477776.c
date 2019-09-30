#include <stdio.h>
#include <stdlib.h>

int can_win(char **S, int **T, int x, int y){
	if(T[x][y] == -1){
		if(S[x][y] == '#'){
			T[x][y] = 0;
		}
		else if((can_win(S, T, x + 1, y) | can_win(S, T, x + 1, y + 1) | can_win(S, T, x, y + 1)) == 0){
			T[x][y] = 1;
		}
		else{
			T[x][y] = 0;
		}
	}
	return T[x][y];
}

int main(){
	int H, W, i, j;
	scanf("%d%d", &H, &W);
	char **S = (char **)malloc(sizeof(char *) * (H + 1));
	int **T = (int **)malloc(sizeof(int *) * (H + 1));
	for(i = 0; i <= H; i++){
		S[i] = (char *)malloc(sizeof(char) * (W + 1));
		T[i] = (int *)malloc(sizeof(int) * (W + 1));
		if(i < H){
			scanf("%s", S[i]);
		}
		else{
			for(j = 0; j < W; j++){
				S[i][j] = '#';
			}
		}
		S[i][W] = '#';
		for(j = 0; j <= W; j++){
			T[i][j] = -1;
		}
	}
	if(can_win(S, T, 0, 0) == 1){
		printf("Second\n");
	}
	else{
		printf("First\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:28:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s", S[i]);
    ^