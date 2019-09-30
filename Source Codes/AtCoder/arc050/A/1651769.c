#include <stdio.h>

int main(){
	char C, c;
	scanf("%c %c", &C, &c);
/*	printf("%d\n", (int)C);
	printf("%d\n", (int)c);
	printf("%c\n", C);
	printf("%c\n", c);
*/	if((int)C + 32 == (int)c){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %c", &C, &c);
  ^