#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS		64

char	s[MAXS];
int	n;

int	cnt;

void bt (int p, long long t, long long u, int g)
{
	if (p == n)
	{
		t += g * u;
		if (((t % 2) == 0) || ((t % 3) == 0) || ((t % 5) == 0) || ((t % 7) == 0))
		{
			cnt++;
		}
		return;
	}

	bt(p + 1, t, (u * 10) + (s[p] - '0'), g);

	if (p != 0)
	{
		t += g * u;
		bt(p + 1, t, (long long)(s[p] - '0'), +1);
		bt(p + 1, t, (long long)(s[p] - '0'), -1);
	}
}

int main (void)
{
	int	nc,
		h;

	for (scanf("%d", &nc), h = 1; h <= nc; h++)
	{
		scanf("%s", s);
		n = strlen(s);
		cnt = 0;
		bt(0, 0, 0, +1);
		printf("Case #%d: %d\n", h, cnt);
	}

	return 0;
}
