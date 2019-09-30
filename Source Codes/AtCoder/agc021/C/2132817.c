#include <stdio.h>
#include <stdlib.h>

int raise(int a, int m){
	if(a % 2 == m){
		return a;
	}
	else{
		if(m == 0){
			return ((a + 1) / 2) * 2;
		}
		else{
			return (a / 2) * 2 + 1;
		}
	}
}

int main(){
	int N, M, A, B, i, j;
	scanf("%d%d%d%d", &N, &M, &A, &B);
	char **C = (char **)malloc(sizeof(char *) * N);
	for(i = 0; i < N; i++){
		C[i] = (char *)malloc(sizeof(char) * (M + 1));
		for(j = 0; j < M; j++){
			C[i][j] = '.';
		}
		C[i][M] = '\0';
	}
	if(N % 2 == 0 && M % 2 == 0){
		if(raise(A, 0) + raise(B, 0) <= N * M / 2 && A <= N * M / 2 && B <= N * M / 2){
			printf("YES\n");
			for(i = 0; i < N - 1; i += 2){
				for(j = 0; j < M - 1; j += 2){
					if(A > 1){
						C[i][j] = '<';
						C[i][j + 1] = '>';
						C[i + 1][j] = '<';
						C[i + 1][j + 1] = '>';
						A -= 2;
					}
					else if(A == 1){
						C[i][j] = '<';
						C[i][j + 1] = '>';
						A -= 1;
					}
					else if(B > 1){
						C[i][j] = '^';
						C[i + 1][j] = 'v';
						C[i][j + 1] = '^';
						C[i + 1][j + 1] = 'v';
						B -= 2;
					}
					else if(B == 1){
						C[i][j] = '^';
						C[i + 1][j] = 'v';
						B -= 1;
					}
				}
			}
			for(i = 0; i < N; i++){
				printf("%s\n", C[i]);
			}
		}
		else{
			printf("NO\n");
		}
	}
	if(N % 2 == 0 && M % 2 == 1){
		if(raise(A, 0) + raise(B, (N / 2) % 2) <= N * M / 2 && A <= N * (M - 1) / 2 && B <= N * M / 2){
			printf("YES\n");
			for(i = 0; i < N - 1; i += 2){
				if(B > 0){
					C[i][M - 1] = '^';
					C[i + 1][M - 1] = 'v';
					B--;
				}
			}
			for(i = 0; i < N - 1; i += 2){
				for(j = 0; j < M - 1; j += 2){
					if(A > 1){
						C[i][j] = '<';
						C[i][j + 1] = '>';
						C[i + 1][j] = '<';
						C[i + 1][j + 1] = '>';
						A -= 2;
					}
					else if(A == 1){
						C[i][j] = '<';
						C[i][j + 1] = '>';
						A -= 1;
					}
					else if(B > 1){
						C[i][j] = '^';
						C[i + 1][j] = 'v';
						C[i][j + 1] = '^';
						C[i + 1][j + 1] = 'v';
						B -= 2;
					}
					else if(B == 1){
						C[i][j] = '^';
						C[i + 1][j] = 'v';
						B -= 1;
					}
				}
			}
			for(i = 0; i < N; i++){
				printf("%s\n", C[i]);
			}
		}
		else{
			printf("NO\n");
		}
	}
	if(N % 2 == 1 && M % 2 == 0){
		if(raise(A, (M / 2) % 2) + raise(B, 0) <= N * M / 2 && A <= N * M / 2 && B <= (N - 1) * M / 2){
			printf("YES\n");
			for(j = 0; j < M - 1; j += 2){
				if(A > 0){
					C[N - 1][j] = '<';
					C[N - 1][j + 1] = '>';
					A--;
				}
			}
			for(i = 0; i < N - 1; i += 2){
				for(j = 0; j < M - 1; j += 2){
					if(A > 1){
						C[i][j] = '<';
						C[i][j + 1] = '>';
						C[i + 1][j] = '<';
						C[i + 1][j + 1] = '>';
						A -= 2;
					}
					else if(A == 1){
						C[i][j] = '<';
						C[i][j + 1] = '>';
						A -= 1;
					}
					else if(B > 1){
						C[i][j] = '^';
						C[i + 1][j] = 'v';
						C[i][j + 1] = '^';
						C[i + 1][j + 1] = 'v';
						B -= 2;
					}
					else if(B == 1){
						C[i][j] = '^';
						C[i + 1][j] = 'v';
						B -= 1;
					}
				}
			}
			for(i = 0; i < N; i++){
				printf("%s\n", C[i]);
			}
		}
		else{
			printf("NO\n");
		}
	}
	if(N % 2 == 1 && M % 2 == 1){
		if(A + B <= N * M / 2 && A <= N * (M - 1) / 2 && B <= (N - 1) * M / 2){
			printf("YES\n");
			for(j = 0; j < M - 1; j += 2){
				if(A > 0){
					C[N - 1][j] = '<';
					C[N - 1][j + 1] = '>';
					A--;
				}
			}
			for(i = 0; i < N - 1; i += 2){
				if(B > 0){
					C[i][M - 1] = '^';
					C[i + 1][M - 1] = 'v';
					B--;
				}
			}
			for(i = 0; i < N - 1; i += 2){
				for(j = 0; j < M - 1; j += 2){
					if(i == N - 3 && j == M - 3 && A == 1 && B == 1){
						C[N - 3][M - 3] = '<';
						C[N - 3][M - 2] = '>';
						C[N - 3][M - 1] = '^';
						C[N - 2][M - 3] = '^';
						C[N - 2][M - 2] = '.';
						C[N - 2][M - 1] = 'v';
						C[N - 1][M - 3] = 'v';
						C[N - 1][M - 2] = '<';
						C[N - 1][M - 1] = '>';
						A--;
						B--;
					}
					else if(i == N - 3 && j == M - 3 && A == 1 && B == 0){
						C[N - 3][M - 3] = '<';
						C[N - 3][M - 2] = '>';
						A--;
					}
					else if(i == N - 3 && j == M - 3 && A == 0 && B == 1){
						C[N - 3][M - 3] = '^';
						C[N - 2][M - 3] = 'v';
						B--;
					}
					else if(A > 1){
						C[i][j] = '<';
						C[i][j + 1] = '>';
						C[i + 1][j] = '<';
						C[i + 1][j + 1] = '>';
						A -= 2;
					}
					else if(B > 1){
						C[i][j] = '^';
						C[i + 1][j] = 'v';
						C[i][j + 1] = '^';
						C[i + 1][j + 1] = 'v';
						B -= 2;
					}
				}
			}
			for(i = 0; i < N; i++){
				printf("%s\n", C[i]);
			}
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &N, &M, &A, &B);
  ^