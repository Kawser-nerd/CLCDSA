#include <stdio.h>
#include <stdlib.h>
#define max_size (int)(2e5 + 1)

int main(){
	int i, S = 0, ans = 0;
	char *X = (char *)malloc(sizeof(char) * max_size);
	scanf("%s", X);
	for(i = 0; X[i] != '\0'; i++){
		if(X[i] == 'S'){
			S++;
		}
		else{
			if(S > 0){
				S--;
			}
			else{
				ans++;
			}
		}
	}
	printf("%d\n", 2 * ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", X);
  ^