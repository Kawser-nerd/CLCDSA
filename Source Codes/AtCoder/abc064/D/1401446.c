#include<stdio.h>
int main(void) {
	int i;
	int n, a = 0, b = 0;
	char s[110];
	scanf("%d%s", &n, s);
	for (i = 0; i < n; i++)
	{
		if (s[i] == '(')	b++;
		else if (b > 0)	b--;
		else a++;
	}
 
	for (int j = 0; j < a; j++)	printf("(");
	printf("%s", s);
	for (int j = 0; j < b; j++)	printf(")");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%s", &n, s);
  ^