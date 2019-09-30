#include <stdio.h>
#include <stdlib.h>

int main(){
	int K, N, i, j, k, l;
	scanf("%d%d", &K, &N);
	char **v = (char **)malloc(sizeof(char *) * N);
	char **w = (char **)malloc(sizeof(char *) * N);
	int *lvl = (int *)malloc(sizeof(int) * N);
	int *lwl = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		v[i] = (char *)malloc(sizeof(char) * 10);
		w[i] = (char *)malloc(sizeof(char) * 28);
		scanf("%s", v[i]);
		scanf("%s", w[i]);
		for(j = 0; ; j++){
			if(v[i][j] == '\0'){
				lvl[i] = j;
				break;
			}
		}
		for(j = 0; ; j++){
			if(w[i][j] == '\0'){
				lwl[i] = j;
				break;
			}
		}
	}
	char **s = (char **)malloc(sizeof(char *) * K);
	int *lsl = (int *)malloc(sizeof(int) * K);
	for(i = 0; i < K; i++){
		s[i] = (char *)malloc(sizeof(char) * 4);
		lsl[i] = 1;
	}
	int flug = 0, n;
	while(flug == 0){
		flug = 1;
		for(i = 0; i < K; i++){
			for(j = 0; j < 3; j++){
				s[i][j] = '\0';
			}
		}
		for(i = 0; i < N; i++){
			for(j = 0, k = 0; j < lvl[i]; j++, k += l){
				n = (int)v[i][j] - (int)'1';
				for(l = 0; l < lsl[n]; l++){
					if(s[n][l] == '\0' || s[n][l] == w[i][k + l]){
						s[n][l] = w[i][k + l];
					}
					else{
						flug = 0;
					}
				}
			}
			if(k != lwl[i]){
				flug = 0;
				break;
			}
		}
		for(i = 0; ; i++){
			if(lsl[i] < 3){
				lsl[i]++;
				break;
			}
			else{
				lsl[i] = 1;
			}
		}
	}
	for(i = 0; i < K; i++){
		printf("%s\n", s[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &K, &N);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", v[i]);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", w[i]);
   ^