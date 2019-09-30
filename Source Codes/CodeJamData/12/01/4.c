#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int goog_to_eng(int c)
{
	static const char * const english =    "abcdefghijklmnopqrstuvwxyz";
	static const char * const googlerese = "ynficwlbkuomxsevzpdrjgthaq";
	const char * const p = strchr(googlerese, c);

	if (p)
		return english[p - googlerese];
	else
		return c;
}

void do_test(int t)
{
	int c;

	printf("Case #%d: ", t + 1);

	do {
		c = getchar();

		if (c == EOF)
			break;

		if (isupper(c))
			putchar(toupper(goog_to_eng(tolower(c))));
		else
			putchar(goog_to_eng(c));
	} while (c != '\n');
}

int main()
{
	int t, i, c;

	scanf("%d", &t);
	do {
		c = getchar();
	} while (c != EOF && c != '\n');
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
