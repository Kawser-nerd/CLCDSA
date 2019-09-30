#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int no_cases, case_no;
	scanf("%u", &no_cases);
	for (case_no = 0; case_no != no_cases; case_no++)
	{
		unsigned int r, c, i, j, k, s, h, l = 0, m, x;
		char cake[1024];
		
		scanf("%u%u", &c, &r);
		
		for (i = 0; i != c; i++)
		{
			getchar();
			h = 0;
			for (j = 0; j != r; j++)
			{
				h |= (cake[i << 5 | j] = getchar()) != '?';
			}
			if (h)
			{
				m = 0;
				for (j = 0; j != r; j++)
				{
					for (k = l; k <= i; k++)
					{
						if (cake[k << 5 | j] != '?')
						{
							break;
						}
					}
					if (k <= i)
					{
						x = cake[k << 5 | j];
		for (k = l; k <= i; k++)
		{
			for (s = m; s <= j; s++)
			{
				cake[k << 5 | s] = x;
			}
		}
						m = j + 1;
					}
				}
				for (k = l; k <= i; k++)
				{
					for (s = m; s <= j; s++)
					{
						cake[k << 5 | s] = x;
					}
				}
				l = i + 1;
			}
		}
		
		
		printf("Case #%u: \n", case_no + 1);
		l = 65536;
		for (i = 0; i != c; i++)
		{
			cake[i << 5 | r] = 0;
			if (cake[i << 5] == '?' && l == 65536)
			{
				l = i - 1 << 5;
			}
			puts(cake + (l == 65536 ? (i << 5) : l));
		}
	}
	return 0;
}
