#include <stdio.h>

int main(void){
	char str[15];
	int count = 0;
	for(int i = 0; i < 12; i++){
		scanf("%s", str);
		for(int j = 0; str[j] != '\0'; j++)
			if(str[j] == 'r'){
				count++;
				break;
			}
	}
	printf("%d\n", count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str);
   ^