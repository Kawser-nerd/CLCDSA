#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char tabel[64][64];

int main()
{
	int t;
	scanf("%i", &t);
	for (int test = 1; test <= t; test++)
	{
		int r, c;
		bool impossible = false;
		printf("Case #%i:\n", test);
		scanf("%i %i", &r, &c);
		for (int i = 0; i < r; i++)
			scanf("%s", tabel[i]);
		strcpy(tabel[r], "");
		for (int i = 0; i < r && !impossible; i++)
		{
			for (int j = 0; j < c && !impossible; j++)
			{
				if (tabel[i][j] == '#')
				{
					if (tabel[i + 1][j] == '#' && tabel[i][j + 1] == '#' && tabel[i + 1][j + 1] == '#')
					{
						tabel[i][j]         = '/';
						tabel[i][j + 1]     = '\\';
						tabel[i + 1][j]     = '\\';
						tabel[i + 1][j + 1] = '/';
					}
					else
					{
						printf("Impossible\n");
						impossible = true;
					}
				}
			}
		}
		if (!impossible)
		for (int i = 0; i < r; i++)
			printf("%s\n", tabel[i]);
	}
	return 0;
}
