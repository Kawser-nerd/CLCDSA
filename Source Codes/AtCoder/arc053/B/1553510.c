#include <stdio.h>
#include <stdlib.h>

#define max_size (int)(1e5 + 1)

int main(){
	int i, n, odd = 0;
	int *num = (int *)malloc(sizeof(int) * 26);
	for(i = 0; i < 26; i++){
		num[i] = 0;
	}
	char *S = (char *)malloc(sizeof(char) * max_size);
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){
		num[(int)S[i] - (int)'a']++;
	}
	n = i;
	for(i = 0; i < 26; i++){
		if(num[i] % 2 == 1){
			odd++;
		}
	}
	if(odd == 0){
		printf("%d\n", n);
	}
	else{
		printf("%d\n", 2 * (((n - odd) / 2) / odd) + 1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^