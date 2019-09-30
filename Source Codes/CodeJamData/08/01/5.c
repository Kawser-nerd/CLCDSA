
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int s;
char engine[100][101];

#if 0
int bsearch(char *ref)
{
    int first = 0;
    int span = s;
    while (span > 1)
    {
	int i = first+span/2;
	int r = strcmp(ref, engine[i]);
	if (r == 0)
	    return i;
	if (r < 0)
	{
	    span = span/2;
	}
	else if (r > 0)
	{
	    first += span/2 + 1;
	    span = span/2 + span%1 - 1;
	}
    }
    return first;
}
#endif

int main(int argc, char **argv)
{
    int n;
    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++)
    {
	scanf("%d\n", &s);

	for (int j = 0; j < s; j++)
	    gets(engine[j]);
	qsort(engine, s, 101, strcmp);

	bool used[100];
	memset(used, 0, sizeof(used));
	int nused = 0;

	int count = 0;

	int q;
	scanf("%d\n", &q);
	for (int j = 0; j < q; j++)
	{
	    char buf[101];
	    gets(buf);
	    int idx = ((char *)bsearch(buf, engine, s, 101, strcmp) - (char *)engine)/101;
	    if (used[idx])
		continue;
	    nused++;
	    if (nused == s)
	    {
		count++;
		nused = 1;
		memset(used, 0, sizeof(used));
	    }
	    used[idx] = 1;
	}

	printf("Case #%d: %d\n", i, count);
    }
}

