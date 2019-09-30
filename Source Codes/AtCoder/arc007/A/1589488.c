#include<stdio.h>

int main()
{
	char x;
	char s[51];
	int i;

	x = getchar();
	getchar();
	scanf("%s", s);

	for(i = 0; i < 50; i++)
		if(s[i] == x)
			continue;
		else if(s[i] == '\0')
			break;
		else
			putchar(s[i]);

	putchar('\n');

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^