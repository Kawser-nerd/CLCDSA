#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void do_test(int t)
{
	int flips = -1;
	int last_char = 0;
	int c;

	while (c = getchar(), c == '+' || c == '-')
	{
		flips += c != last_char;
		last_char = c;
	}

	if (last_char == '-')
		flips++;
	
	printf("Case #%d: %d\n", t + 1, flips);
}

int main()
{
	int t, i;

	scanf("%d ", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
