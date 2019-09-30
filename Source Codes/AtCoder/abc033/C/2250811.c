#include <stdio.h>
int main() {
	char s[100010];
	long int ans = 0;
	int x = 0;
	scanf("%s", &s);
	x = s[0] - '0';
	for (int i = 2; s[i]!='\0'; i += 2)
	{
		x = x ? 1 : 0;
		if (s[i - 1] == '+')
		{
			if (x) ans++;
			x = s[i] - '0';
		}
		else
		{
			x *= s[i] - '0';
		}
	}
	if (x) ans++;
	printf("%ld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100010]’ [-Wformat=]
  scanf("%s", &s);
        ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &s);
  ^