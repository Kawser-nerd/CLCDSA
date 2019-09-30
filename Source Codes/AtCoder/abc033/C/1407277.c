#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, ans = 0, is0 = 0;
	char *S = (char *)malloc(sizeof(char) * (int)(1e5 + 1));
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){
		if(S[i] == '+'){
			if(is0 == 0){
				ans++;
			}
			else{
				is0 = 0;
			}
		}
		else if(S[i] == '0'){
			is0 = 1;
		}
	}
	if(is0 == 0){
		ans++;
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^