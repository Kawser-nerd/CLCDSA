#include <stdio.h>

int main(){
	char a, b;
	
	scanf("%c %c", &a, &b);
	
	if(a==(b-32)) printf("Yes");
	else		  printf("No");
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %c", &a, &b);
  ^