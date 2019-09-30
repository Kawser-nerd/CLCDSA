#include <stdio.h>

int main(){
	int a, b, c, f = 0;
	char out;
	scanf("%d %d %d", &a, &b, &c);
	if(c == a + b)f++;
	if(c == a - b)f += 2;
	if(f == 0)c = '!';
	if(f == 1)c = '+';
	if(f == 2)c = '-';
	if(f == 3)c = '?';
	printf("%c\n", c);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &a, &b, &c);
  ^