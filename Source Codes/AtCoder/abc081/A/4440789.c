#include<stdio.h>

int main()
{
	char s[100];
	scanf("%s",s);
	int counter = 0;
	if(s[0] == '1') counter++;
	if(s[1] == '1') counter++;
	if(s[2] == '1') counter++;
	printf("%d",counter);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^