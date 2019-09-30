#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N, i, j, ans = 0;
	char t1[] = "TAKAHASHIKUN";
	char t2[] = "Takahashikun";
	char t3[] = "takahashikun";
	scanf("%d", &N);
	char **w = (char **)malloc(sizeof(char *) * N);
	for(i = 0; i < N; i++){
		w[i] = (char *)malloc(sizeof(char) * 101);
		scanf("%s", w[i]);
		if(i == N - 1){
			for(j = 0; w[i][j] != '.'; j++){}
			w[i][j] = '\0';
		}
		if(strcmp(w[i], t1) == 0 || strcmp(w[i], t2) == 0 || strcmp(w[i], t3) == 0){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", w[i]);
   ^