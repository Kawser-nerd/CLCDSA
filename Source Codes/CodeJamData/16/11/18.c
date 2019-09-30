#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void do_test(int t)
{
	char buf[4000] = { 0 };
	char *start = &buf[1999];
	char *end = &buf[1999];
	int c;

	do {
		c = getchar();
	} while (c == '\n');

	do {
		*start = c;
		if (strcmp(start, start + 1) < 0)
		{
			if (start == end)
				start--;
			*end++ = c;
		}
		else
		{
			if (start == end)
				end++;
			start--;
		}

		c = getchar();
	} while (c != '\n');

	printf("Case #%d: %s\n", t + 1, start + 1);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
