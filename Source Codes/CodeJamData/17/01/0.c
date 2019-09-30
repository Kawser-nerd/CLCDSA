#include <stdio.h>
#include <string.h>

int main(void)
{
    int t;
    int curcase = 0;
    scanf("%d", &t);
    while (t != curcase)
    {
        char s[1001];
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
	    s[i] = s[i] == '-';
	}
	int flips = 0;
        int k;
	scanf("%d", &k);
	for (int i = 0; i < len - k + 1; i++)
	{
	    if (s[i])
	    {
	        for (int j = i; j < i + k; j++)
		{
		    s[j] = !s[j];
		}
		flips++;
	    }
	}
	int impossible = 0;
	for (int i = len - k + 1; i < len; i++)
	{
	    if (s[i])
	    {
	        impossible = 1;
	    }
	}
	printf("Case #%d: ", curcase + 1);
	if (impossible)
	{
	    printf("IMPOSSIBLE\n");
	}
	else
	{
	    printf("%d\n", flips);
	}
	curcase++;
    }
}
