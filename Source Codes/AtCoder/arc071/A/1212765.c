#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int mins(int **s, int j, int n){
	int i, ans = 100;
	for(i = 0; i < n; i++){
		ans = min(ans, s[i][j]);
	}
	return ans;
}

int main(){
	int n, i, j;
	char c = 'a';
	scanf("%d\n", &n);
	int **s = (int **)malloc(sizeof(int *) * n);
	for(i = 0; i < n; i++){
		s[i] = (int *)malloc(sizeof(int) * 26);
		for(j = 0; j < 26; j++){
			s[i][j] = 0;
		}
		for(;;){
			scanf("%c", &c);
			if(c == '\n'){
				break;
			}
			s[i][(int)c - (int)('a')]++;
		}
	}
	for(j = 0; j < 26; j++){
		for(i = 0; i < mins(s, j, n); i++){
			printf("%c", (char)((int)('a') + j));
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n", &n);
  ^
./Main.c:32:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c", &c);
    ^