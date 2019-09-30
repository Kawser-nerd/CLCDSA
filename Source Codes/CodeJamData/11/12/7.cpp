#include <stdio.h>
#include <string>
#include <set>
#include <cstring>

int n, m;
char str[10000][20];
char tmp[10000][20];
int point[10000];
char fur[27];

using namespace std;

set<string> SS;

int main ()
{
	int t, ct = 0;

	for (scanf ("%d", &t); t > 0; t --)
	{
		scanf ("%d%d", &n, &m);

		for (int i = 0; i < n; i ++)
			scanf ("%s", str[i]);

		printf ("Case #%d:", ++ ct);

		for (int cc = 0; cc < m; cc ++)
		{
			scanf ("%s", fur);

			for (int i = 0; i < n; i ++)
			{
				point[i] = 0;
				for (int j = 0; j < 26; j ++)
					if (strchr(str[i], fur[j]) != NULL)
						point[i] --;
			}

			for (int i = 0; i < n; i ++)
			{
				int j = 0;
				for (; str[i][j]; j ++)
					tmp[i][j] = '_';
				tmp[i][j] = '\0';
			}

			for (int i = 0; i < 26; i ++)
			{
				SS.clear();

				for (int j = 0; j < n; j ++)
				{
					bool x = false;
					for (int k = 0; str[j][k] && !x; k ++)
						if (str[j][k] == fur[i])
							x = true;

					if (x)
						SS.insert (tmp[j]);
				}

				for (int j = 0; j < n; j ++)
				{
					if (SS.find(tmp[j]) != SS.end())
					{
//						printf ("%s %s ++\n", str[j], tmp[j]);
						point[j] ++;
					}

					for (int k = 0; str[j][k]; k ++)
						if (str[j][k] == fur[i])
							tmp[j][k] = str[j][k];
				}
			}

//			for (int i = 0; i < n; i ++)
//				printf (" %d", point[i]);

			int bi = 0;
			for (int i = 1; i < n; i ++)
				if (point[i] > point[bi]) bi = i;
			printf (" %s", str[bi]);
		}

		printf ("\n");
	}

	return 0;
}