#include <stdio.h>
#include <algorithm>

using namespace std;

int x, y;
int xx[1000], yy[1000];
char cc[1000];
bool hassol;

int main ()
{
	int t, ct = 0;
	int n;

	for (scanf ("%d", &t); t > 0; t --)
	{
		scanf ("%d", &n);
		for (int i = 0; i < n; i ++)
		{
			scanf ("%d%d%c%c", xx+i,yy+i,cc+i,cc+i);
		}

		hassol = false;

		for (int i = 400; i >= -400; i --)
			for (int j = 400; j >= -400; j --)
			{
				bool ok = true;
				for (int k = 0; k < n; k ++)
				{
					int xdist = std::abs(i - xx[k]);
					int ydist = std::abs(j - yy[k]);
					int mdist = max(xdist, ydist);

					if (mdist%2 == 0 && cc[k] == '#' || mdist%2 == 1 && cc[k] == '.')
					{
						ok = false;
						break;
					}
				}

				if (ok && (!hassol || (abs(i)+abs(j)) < (abs(x)+abs(y))))
				{
					hassol = true;
					x = i;
					y = j;
				}
			}

		if (hassol)
		{
			printf ("Case #%d: %d %d\n", ++ ct, x, y);
		}
		else
		{
			printf ("Case #%d: Too damaged\n", ++ ct);
		}
	}

	return 0;
}