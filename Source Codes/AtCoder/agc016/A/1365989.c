#include <stdio.h>
#include <stdlib.h>

int main(){
	char *s = (char *)malloc(sizeof(char) * 101);
	scanf("%s", s);
	int i, j, k, n, cont;
	char c;
	for(n = 0; ; n++){
		if(s[n] == '\0'){
			break;
		}
	}
	for(k = 0; ; k++){
		for(i = 0; i < 26; i++){
			c = (char)(i + (int)'a');
			cont = -1;
			for(j = 0; j - cont - 1 <= k && j < n; j++){
				if(s[j] == c){
					cont = j;
				}
			}
			if(cont >= n - k - 1){
				printf("%d\n", k);
				return 0;
			}
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^