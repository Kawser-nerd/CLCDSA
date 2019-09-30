#include <stdio.h>

int main (void){

	char s[100000];
	scanf("%s",s);

	int count = 0;
	int i;

	for(i = 0; s[i] != '\0'; i++){

		if(s[i] != s[i + 1]){
			count++;
		}
	}

	printf("%d\n", count - 1);

	return 0;


} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^