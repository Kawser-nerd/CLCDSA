#include <stdio.h>
#include <algorithm>
using namespace std;

int cas, x, n, m;
bool flag;

int main()
{
	freopen("D.in", "r", stdin); freopen("D.out", "w", stdout);
	scanf("%d", &cas);
	for (int T = 1; T <= cas; T ++)
	{
		scanf("%d%d%d", &x, &n, &m);
		flag = false;
		if (n * m % x == 0)
			if (x == 1)
			{
				flag = true;
			} else if (x == 2)
			{
				flag = true;
			} else if (x == 3)
			{
				if (n * m >= 6) flag = true;
			} else if (x == 4)
			{
				if (min(n, m) > 2) flag = true;
			} else if (x == 5)
			{
				if (min(n, m) > 3) flag = true;
				else if (min(n, m) == 3 && max(n, m) > 5) flag = true; 
			} else if (x == 6)
			{
				if (min(n, m) > 3) flag = true;
			}
		if (flag)
			printf("Case #%d: GABRIEL\n", T);
		else
			printf("Case #%d: RICHARD\n", T);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
