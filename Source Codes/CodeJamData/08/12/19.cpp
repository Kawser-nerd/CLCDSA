#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int p[2009];
int m[2009][2009];
int dots[2009];


//!!!!!!!!!!!!!!


int main()
{
	freopen("c:\\2.txt", "r", stdin);
	freopen("c:\\2_out.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int te = 1; te <= t; te++)
	{
		memset(m, 0, sizeof(m));

		int n,cu;
		scanf("%d %d", &n, &cu);

		for (int i = 0; i < cu; i++)
		{
			int z;
			scanf("%d", &z);
			dots[i] = z;

			for (int j = 0; j < z; j++)
			{
				int a,b;
				scanf("%d %d", &a, &b);
				if (b==1) dots[i]--;

				m[i][a] = b+1;
			}
		}

		bool impos = false;

		for (int i = 1; i <= n; i++) p[i] = 1;

		bool changed;

		do
		{

		changed = false;

		for (int i = 0; i < cu; i++)
		{
			if (dots[i] == 0)
			{
				dots[i] = -1;

				int j = 1;
				while (j <= n && m[i][j] != 2) j++;
				if (j == n+1)
				{
					impos = true;
				}
				else
				{
					changed = true;
					p[j] = 2;
					for (int k = 0; k < cu; k++)
					{
						if (m[k][j]==1)
						{
							m[k][j] = 0;
							dots[k]--;
						}
					}
				}
			}
		}

		}
		while (changed);

		if (impos)
		{
			printf("Case #%d: IMPOSSIBLE\n", te);
		}
		else
		{
			// TEST!!!
			printf("Case #%d: ", te);
			for (int i = 1; i < n; i++) printf("%d ", p[i]-1);
			printf("%d\n", p[n]-1);

		}


	}




	return 0;
}
