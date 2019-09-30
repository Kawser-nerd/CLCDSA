#include <stdio.h>
#include <stdlib.h>
#define max_size (int)(1e5 + 1)

int main(){
	int i, ans = 0;
	char *S = (char *)malloc(sizeof(char) * max_size);
	scanf("%s", S);
	for(i = 1; S[i] != '\0'; i++){
		if(S[i] != S[i - 1]){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^