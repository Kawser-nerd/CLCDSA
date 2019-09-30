#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define DEBUGF(s, ...) fprintf(stderr, "DEBUG #%d: " s, t+1, ##__VA_ARGS__)

void do_test(int t)
{
	char s[4000];
	int f[4000] = { 0 };
	int k;
	int rs = 0;
	int count = 0;
	int i;
	int ns;

	scanf("%s %d", s, &k);
	
	ns = strlen(s);

	for (i = 0; i < ns; i++)
	{
		if (i <= ns - k)
		{
			f[i] = (s[i] == '-') ^ rs;
			rs ^= f[i];
			count += f[i];
		}
		else
		{
			if ((s[i] == '-') ^ rs)
			{
				printf("Case #%d: IMPOSSIBLE\n", t + 1);
				return;
			}
		}
		if (i + 1 >= k)
			rs ^= f[i + 1 - k];
	}

	printf("Case #%d: %d\n", t + 1, count);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
