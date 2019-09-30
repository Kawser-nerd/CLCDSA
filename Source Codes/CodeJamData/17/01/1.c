#include <stdio.h>

int main(int argc, char **argv)
{
	char e[1024], x[1024], *p;
	unsigned int t, c, k, f, s, i, b;
	scanf("%u", &t);
	getchar();
	for (c = 0; c != t; c++)
	{
		p = e;
		while ((*p++ = getchar()) != ' ') {}
		p[-1] = 0;
		scanf("%u", &k);
		getchar();
		
		for (i = 0; i != k; i++)
		{
			x[i] = 0;
		}
		f = s = i = b = 0;
		do
		{
			f += x[i + k] = e[i] == '-' ^ (s ^= x[i]);
			s = e[i] == '-';
		} while (e[i++ + k]);
		while (e[i])
		{
			b |= e[i] == '-' ^ (s ^= x[i]);
			s = e[i] == '-';
			i++;
		}
		printf(b ? "Case #%u: IMPOSSIBLE\n" : "Case #%u: %u\n", c + 1, f);
	}
	return 0;
}
