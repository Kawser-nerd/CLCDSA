#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i, j, k, ans = 0, f;
	scanf("%d", &N);
	char **S = (char **)malloc(sizeof(char *) * N);
	char **T = (char **)malloc(sizeof(char *) * N);
	for(i = 0; i < N; i++){
		S[i] = (char *)malloc(sizeof(char) * (N + 1));
		scanf("%s", S[i]);
		T[i] = (char *)malloc(sizeof(char) * N);
	}
	for(k = 0; k < N; k++){
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				T[(i + k) % N][j] = S[i][j];
			}
		}
		f = 1;
		for(i = 0; i < N && f == 1; i++){
			for(j = 0; j < N && f == 1; j++){
				if(T[i][j] != T[j][i]){
					f = 0;
				}
			}
		}
		ans += f * N;
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S[i]);
   ^