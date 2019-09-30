#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void do_test(int t)
{
	long r, c, w;
	long score;

	scanf(" %ld %ld %ld", &r, &c, &w);

	score = r  * (c / w) + w - (c % w == 0);
	
	printf("Case #%d: %ld\n", t + 1, score);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
