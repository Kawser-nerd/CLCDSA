#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i, j, k, count;
	scanf("%d", &N);
	char **w = (char **)malloc(sizeof(char *) * N);
	for(i = 0; i < N; i++){
		w[i] = (char *)malloc(sizeof(char) * 31);
		scanf("%s", w[i]);
	}
	char *ans = (char *)malloc(sizeof(char) * (30 * N + 1));
	for(i = 0, k = 0; i < N; i++){
		for(j = 0, count = 0; w[i][j] != '\0'; j++){
			if(w[i][j] == 'b' || w[i][j] == 'c' || w[i][j] == 'B' || w[i][j] == 'C'){
				ans[k] = '1';
			}
			else if(w[i][j] == 'd' || w[i][j] == 'w' || w[i][j] == 'D' || w[i][j] == 'W'){
				ans[k] = '2';
			}
			else if(w[i][j] == 't' || w[i][j] == 'j' || w[i][j] == 'T' || w[i][j] == 'J'){
				ans[k] = '3';
			}
			else if(w[i][j] == 'f' || w[i][j] == 'q' || w[i][j] == 'F' || w[i][j] == 'Q'){
				ans[k] = '4';
			}
			else if(w[i][j] == 'l' || w[i][j] == 'v' || w[i][j] == 'L' || w[i][j] == 'V'){
				ans[k] = '5';
			}
			else if(w[i][j] == 's' || w[i][j] == 'x' || w[i][j] == 'S' || w[i][j] == 'X'){
				ans[k] = '6';
			}
			else if(w[i][j] == 'p' || w[i][j] == 'm' || w[i][j] == 'P' || w[i][j] == 'M'){
				ans[k] = '7';
			}
			else if(w[i][j] == 'h' || w[i][j] == 'k' || w[i][j] == 'H' || w[i][j] == 'K'){
				ans[k] = '8';
			}
			else if(w[i][j] == 'n' || w[i][j] == 'g' || w[i][j] == 'N' || w[i][j] == 'G'){
				ans[k] = '9';
			}
			else if(w[i][j] == 'z' || w[i][j] == 'r' || w[i][j] == 'Z' || w[i][j] == 'R'){
				ans[k] = '0';
			}
			else{
				count++;
				k--;
			}
			k++;
		}
		if(j != count){
			ans[k] = ' ';
			k++;
		}
	}
	if(k == 0){
		printf("\n");
	}
	else{
		for(i = 0; i < k - 1; i++){
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", w[i]);
   ^