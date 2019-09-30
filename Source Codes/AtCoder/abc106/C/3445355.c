#include <stdio.h>
#include <string.h>
int main()
{
	char	s[100+1];
	int	c, a;
	unsigned long long	k;
	int	i;

	scanf("%s", s);
	scanf("%lld", &k);

	a = 0;
	c = 0;
	for (i = 0; i < strlen(s); ++i) {
		if (s[i] == '1') {
			c++;
		}
		else {
			a = s[i];
			break;
		}
	}

	if (k <= c) {
		a = '1';
	}
	printf("%c\n", a);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &k);
  ^