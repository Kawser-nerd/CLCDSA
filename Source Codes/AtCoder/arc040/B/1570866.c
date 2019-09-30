#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, R, i, j, ans = 0;
	scanf("%d%d", &N, &R);
	char *S = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S);
	int r = -1;
	for(i = 0; i < N; i++){
		if(S[i] == '.'){
			r = i;
		}
	}
	if(r == -1){
		printf("0\n");
		return 0;
	}
	for(i = 0; i < N; i++, ans++){
		if(S[i] == '.' || i >= r - R + 1){
			for(j = i; j < i + R && j < N; j++){
				S[j] = 'o';
			}
			ans++;
		}
		for(j = 0; S[j] == 'o'; j++){}
		if(j == N){
			printf("%d\n", ans);
			return 0;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &R);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^