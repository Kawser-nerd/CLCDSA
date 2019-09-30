#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FGETS(s,n,p)	s[0] = 0;fgets(s,n,p)

int cal(int L, int map[15][26], int wordz, char word[5000][20])
{
	int count = 0;
	int i, j;
	for (i = 0; i < wordz; i++)
	{	// word[i] in or not
		int p_hit = 1;
		for (j = 0; j < L; j++)
		{
			if (map[j][word[i][j]-'a'] <= 0)
			{
				p_hit = 0;
				break;
			}
		}
		if (p_hit)
		{
			count++;
		}
	}
	return count;
}

int main(int argc, char *argv[])
{
	char buf[4096];
	FILE *in = stdin;
	int c, L, D, N;
	char word[5000][20];
	int wordz;
	int a_order[256];

	FGETS(buf, 4096, in);
	sscanf(buf, "%d %d %d", &L, &D, &N);
	wordz = 0;
	memset(word, 0, sizeof(word));
	for (c = 0; c < D; c++)
	{
		FGETS(buf, 4096, in);
		sscanf(buf, "%s", word[wordz++]);
	}
	{
		for (c = 0; c < 255; c++)
		{
			a_order[c] = -1;
		}
		for (c = 0; c < L; c++)
		{
			a_order[(int)word[0][c]] = c;
		}
	}

	for (c = 0; c < N; c++)
	{
		char tmp[4096];
		int map[15][26];

//	Data preparaion put here
		FGETS(buf, 4096, in);
		sscanf(buf, "%s", tmp);
		// gen map
		{
			int i;
			int bracket = 0;
			int p = 0;
			memset(map, 0, sizeof(map));
			for (i = 0; i < strlen(tmp); i++)
			{
				if (tmp[i] == '(')
				{
					bracket++;
				}
				else if (tmp[i] == ')')
				{
					bracket--;
					p++;
				}
				else if (tmp[i] >= 'a' && tmp[i] <= 'z')
				{
					map[p][(int)tmp[i]-'a'] = 1;
					if (!bracket) p++;
				}
				else
				{
					// Unknown character, skip it
				}
				if (p >= L) break;
			}
		}

		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
		printf("%d\n", cal(L, map, wordz, word));

	}
	return 0;
}
