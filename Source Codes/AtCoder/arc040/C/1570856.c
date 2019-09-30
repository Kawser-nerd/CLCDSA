#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i, j, r, ans = 0;
	scanf("%d", &N);
	char **S = (char **)malloc(sizeof(char *) * (N + 1));
	for(i = 0; i < N; i++){
		S[i] = (char *)malloc(sizeof(char) * (N + 1));
		scanf("%s", S[i]);
	}
	S[N] = (char *)malloc(sizeof(char) * (N + 1));
	for(i = 0; i < N; i++){
		r = -1;
		for(j = 0; j < N; j++){
			if(S[i][j] == '.'){
				r = j;
			}
		}
		if(r != -1){
			ans++;
			for(j = r; j < N; j++){
				S[i + 1][j] = 'o';
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S[i]);
   ^