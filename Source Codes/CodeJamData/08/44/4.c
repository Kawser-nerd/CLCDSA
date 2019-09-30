#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b)	(((a) < (b)) ? (a) : (b))
#define MAX(a,b)	(((a) > (b)) ? (a) : (b))

#define INFINITO	0x3F3F3F3F

#define MAXT		8
#define MAXS		1024

char	s[MAXS];
int	n;

int	v[MAXT];
char	mrc[MAXT];
int	t;

int	res;

char	s2[MAXS];

int rle (void)
{
	int	r;
	char	u;
	int	i,
		j;

	for (i = 0; s[i] != '\0'; i += t)
	{
		for (j = 0; j < t; j++)
		{
			s2[i + j] = s[i + v[j]];
		}
	}
	s2[i] = '\0';

	u = '\0';
	r = 0;
	for (i = 0; s2[i] != '\0'; i++)
	{
		if (s2[i] != u)
		{
			u = s2[i];
			r++;
		}
	}

	return r;
}

void bt (int p)
{
	int	r;
	int	i;

	if (p == t)
	{
		r = rle();
		res = MIN(res, r);
		return;
	}

	for (i = 0; i < t; i++)
	{
		if (mrc[i])
		{
			continue;
		}
		mrc[i] = 1;
		v[p] = i;
		bt(p + 1);
		mrc[i] = 0;
	}
}

int main (void)
{
	int	nc,
		h;

	gets(s);
	for (sscanf(s, "%d", &nc), h = 1; h <= nc; h++)
	{
		gets(s);
		sscanf(s, "%d", &t);
		gets(s);
		memset(mrc, 0, sizeof(mrc));
		res = INFINITO;
		bt(0);
		printf("Case #%d: %d\n", h, res);
	}

	return 0;
}
