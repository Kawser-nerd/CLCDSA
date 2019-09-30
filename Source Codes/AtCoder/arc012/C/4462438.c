#include <stdio.h>
#include <stdlib.h>

int five(char **B, int i, int j){
	int d, k, f;
	int dx[4] = {1, 1, 1, 0};
	int dy[4] = {-1, 0, 1, 1};
	for(d = 0; d < 4; d++){
		f = 1;
		for(k = 1; k < 5; k++){
			if(B[i][j] != B[i + dx[d] * k][j + dy[d] * k]){
				f = 0;
			}
		}
		if(f == 1){
			return 1;
		}
	}
	return 0;
}

int check(char **B, char c, int N, int M){
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(B[M + i][M + j] == c && five(B, M + i, M + j) == 1){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int N = 19, M = 5, i, j, o_num = 0, x_num = 0, f;
	char **B = (char **)malloc(sizeof(char *) * (N + 2 * M));
	for(i = 0; i < N + 2 * M; i++){
		B[i] = (char *)malloc(sizeof(char) * (N + 2 * M + 1));
		for(j = 0; j < N + 2 * M; j++){
			B[i][j] = '.';
		}
	}
	for(i = 0; i < N; i++){
		scanf("%s", &B[M + i][M]);
		B[M + i][M + N] = '.';
		for(j = 0; j < N; j++){
			if(B[M + i][M + j] == 'o'){
				o_num++;
			}
			else if(B[M + i][M + j] == 'x'){
				x_num++;
			}
		}
	}
	if(o_num == x_num){
		if(x_num == 0){
			printf("YES\n");
			return 0;
		}
		if(check(B, 'o', N, M) == 1){
			printf("NO\n");
			return 0;
		}
		f = 1;
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				if(B[M + i][M + j] == 'x'){
					B[M + i][M + j] = '.';
					if(check(B, 'x', N, M) == 0){
						f = 0;
					}
					B[M + i][M + j] = 'x';
				}
			}
		}
		if(f == 1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	else if(o_num == x_num + 1){
		if(check(B, 'x', N, M) == 1){
			printf("NO\n");
			return 0;
		}
		f = 1;
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				if(B[M + i][M + j] == 'o'){
					B[M + i][M + j] = '.';
					if(check(B, 'o', N, M) == 0){
						f = 0;
					}
					B[M + i][M + j] = 'o';
				}
			}
		}
		if(f == 1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &B[M + i][M]);
   ^