#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i, j, k, ans = 0;
	scanf("%d", &N);
	char **x = (char **)malloc(sizeof(char *) * N);
	for(i = 0; i < N; i++){
		x[i] = (char *)malloc(sizeof(char) * 10);
		scanf("%s", x[i]);
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < 9; j++){
			if(x[i][j] == 'x'){
				x[i][j] = '.';
				ans++;
			}
			else if(x[i][j] == 'o'){
				for(k = i; k < N; k++){
					if(x[k][j] != 'o'){
						break;
					}
					else{
						x[k][j] = '.';
					}
				}
				ans++;
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
   scanf("%s", x[i]);
   ^