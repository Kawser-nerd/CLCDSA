#include <stdio.h>
#include <stdlib.h>

int is_center(int i, int j, char **S){
	int h, w;
	for(h = -1; h <= 1; h++){
		for(w = -1; w <= 1; w++){
			if(S[i + h][j + w] == '.'){
				return 0;
			}
		}
	}
	return 1;
}

int has_neighbor(int i, int j, char **T){
	int h, w;
	for(h = -1; h <= 1; h++){
		for(w = -1; w <= 1; w++){
			if(T[i + h][j + w] == '#'){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int H, W, i, j;
	scanf("%d%d", &H, &W);
	char **S = (char **)malloc(sizeof(char *) * (H + 2));
	char **T = (char **)malloc(sizeof(char *) * (H + 2));
	char **U = (char **)malloc(sizeof(char *) * (H + 2));
	for(i = 0; i <= H + 1; i++){
		S[i] = (char *)malloc(sizeof(char) * (W + 2));
		T[i] = (char *)malloc(sizeof(char) * (W + 2));
		U[i] = (char *)malloc(sizeof(char) * (W + 2));
	}
	for(j = 0; j <= W + 1; j++){
		S[0][j] = '#';
		S[H + 1][j] = '#';
		T[0][j] = '.';
		T[H + 1][j] = '.';
	}
	for(i = 1; i <= H; i++){
		S[i][0] = '#';
		scanf("%s", &S[i][1]);
		S[i][W + 1] = '#';
		T[i][0] = '.';
		T[i][W + 1] = '.';
	}
	for(i = 1; i <= H; i++){
		for(j = 1; j <= W; j++){
			if(is_center(i, j, S)){
				T[i][j] = '#';
			}
			else{
				T[i][j] = '.';
			}
		}
	}
	for(i = 1; i <= H; i++){
		for(j = 1; j <= W; j++){
			if(has_neighbor(i, j, T)){
				U[i][j] = '#';
			}
			else{
				U[i][j] = '.';
			}
		}
	}
	for(i = 1; i <= H; i++){
		for(j = 1; j <= W; j++){
			if(S[i][j] != U[i][j]){
				printf("impossible\n");
				return 0;
			}
		}
	}
	printf("possible\n");
	for(i = 1; i <= H; i++){
		for(j = 1; j <= W; j++){
			printf("%c", T[i][j]);
		}
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &S[i][1]);
   ^