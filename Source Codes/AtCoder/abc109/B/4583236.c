#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	int n;
	char word[100][15];
	char last = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%s", word[i]);
	for(int i = 0; i < n - 1; i++){
		if(word[i][strlen(word[i]) - 1] != word[i + 1][0]){
			printf("No\n");
			return 0;
		}
		for(int j = 0; j < i; j++){
			if(strcmp(word[i], word[j]) == 0){
				printf("No\n");
				return 0;
			}
		}
	}
	for(int i = 0; i < n - 1; i++){
		if(strcmp(word[i], word[n - 1]) == 0){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", word[i]);
   ^