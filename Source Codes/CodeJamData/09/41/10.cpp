#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

int n;
char ma[51][51];

void Load()
{
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			char c = getchar();
			while (! ((c == '0') || (c == '1'))) c = getchar();
			ma[i][j] = c;
		}
	}
}

void Swap(int i, int j)
{
	int k;
	for (k = 0; k < n; k++)
	{
		int t = ma[i][k];
		ma[i][k] = ma[j][k];
		ma[j][k] = t;
	}
}

void Solve()
{
	int i, j, k;
	int ans = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			int f = 1;
		    for (k = 0; k < n; k++)
		    {
		    	if (ma[j][k] == '1' && k > i)
		    	{
		    		f = 0;
		    		break;
		    	}
		    }
		    if (f == 1)
		    {
		    	for (k = j - 1; k >= i; k--) 
		    	{
		    		Swap(k + 1, k);
		    		ans++;
		    	}
		    	break;
		    }
		}
	}
	printf("%d", ans);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
	}
	return 0;
}