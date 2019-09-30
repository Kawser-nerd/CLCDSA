/* Sergio Ligregni */
/* Using ANSI C */

#include <stdio.h>
#include <string.h>

struct dir
{
	char name[1005];
	int padre, depth;
} arre[50000];

char cur[1005];

main ()
{
	int T, t=0, N, M, i, k, z, d, h, p, mk;

	char c;

	scanf("%d", &T);

	while (t++<T)
	{
		bzero(arre, sizeof(arre));

		mk = 0;

		scanf("%d%d\n", &N, &M);

		k=i=0;

		strcpy(arre[k].name, "/");
		arre[k].padre = -1;
		arre[k].depth = 0;
		++k;

		while(i<N)
		{
			z=d=p=0;
			while ((c=getchar())!='\n' && c!=EOF)
			{
				if (c=='/')
				{
					++d;
					cur[z] = 0;
					if (z)
					{
						z = 0;
						for (h=0; h<k; ++h)
						{
							if (!strcmp(arre[h].name, cur) && arre[h].depth == d && arre[h].padre == p)
								break;
						}
						if (h==k)
						{
							strcpy(arre[h].name, cur);
							arre[h].padre = p;
							arre[h].depth = d;
							++k;
						}
						p = h;
					}
				}
				else
					cur[z++] = c;
			}

			++d;
			cur[z] = 0;
			if (z)
			{
				z = 0;
				for (h=0; h<k; ++h)
				{
					if (!strcmp(arre[h].name, cur) && arre[h].depth == d && arre[h].padre == p)
						break;
				}
				if (h==k)
				{
					strcpy(arre[h].name, cur);
					arre[h].padre = p;
					arre[h].depth = d;
					++k;
				}
				p = h;
			}

			++i;
		}
		
		/*for (z=0; z<k; ++z)
			printf("%2d - %s, %d, %d\n", z, arre[z].name, arre[z].padre, arre[z].depth);*/

		i = 0;

		while(i<M)
		{
			z=d=p=0;
			while ((c=getchar())!='\n' && c!=EOF)
			{
				if (c=='/')
				{
					++d;
					cur[z] = 0;
					if (z)
					{
						z = 0;
						for (h=0; h<k; ++h)
						{
							if (!strcmp(arre[h].name, cur) && arre[h].depth == d && arre[h].padre == p)
								break;
						}
						if (h==k)
						{
							strcpy(arre[h].name, cur);
							arre[h].padre = p;
							arre[h].depth = d;
							++k;
							++mk;
						}
						p = h;
					}
				}
				else
					cur[z++] = c;
			}

			++d;
			cur[z] = 0;
			if (z)
			{
				z = 0;
				for (h=0; h<k; ++h)
				{
					if (!strcmp(arre[h].name, cur) && arre[h].depth == d && arre[h].padre == p)
						break;
				}
				if (h==k)
				{
					strcpy(arre[h].name, cur);
					arre[h].padre = p;
					arre[h].depth = d;
					++k;
					++mk;
				}
				p = h;
			}

			++i;
		}
		printf("Case #%d: %d\n", t, mk);
	}

	return 0;
}

