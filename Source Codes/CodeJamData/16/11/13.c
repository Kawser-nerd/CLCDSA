// Problem A. The Last Word

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char win[1011] = {0};

void create(char ch)
{
	int k;
	char before[1011] = {0}, after[1011] = {0};
	sprintf(before, "%c%s", ch, win);
	sprintf(after, "%s%c", win, ch);
	for (k = 0; k < 1011; k ++)
		win[k] = 0;
	if (strcmp(before, after) < 0)
		sprintf(win, "%s", after);
	else
		sprintf(win, "%s", before);
}

int main(int argc, char *argv)
{
	int i, T;
	scanf("%d", &T);
	for (i = 0; i < T; i ++)
	{
		int pt = 0, l = 0;
		char S[1011] = {0};
		scanf("%s", S);
		for (l = 0; l < 1011; l ++)
			win[l] = 0;
		win[0] = S[pt ++];
		while (S[pt] != 0)
			create(S[pt ++]);
		printf("Case #%d: %s\n", i + 1, win);
	}
	return 0;
}