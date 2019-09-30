#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define DEBUGF(s, ...) fprintf(stderr, "DEBUG #%d: " s, t+1, ##__VA_ARGS__)

void do_test(int t)
{
	char s[4000];
	char *p;

	scanf("%s", s);
	
	p = s + strlen(s);
	if (p > s)
		p--;
	while (p > s)
	{
		if (p[0] < p[-1])
		{
			char *px;
			for (px = p; *px; px++)
				*px = '9';
			p[-1]--;
		}
		p--;
	}

	p = s;
	if (p[0] == '0' && p[1])
		p++;

	printf("Case #%d: %s\n", t + 1, p);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
