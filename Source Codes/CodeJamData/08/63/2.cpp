#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define for_each(it, v) for (vector<int>::iterator it = (v).begin(); it != (v).end(); ++it)


const int MAX_N = 17;

int n;
int x;
double p;
double f[MAX_N][1 << MAX_N];
int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("c-large.out", "w", stdout);
	int testNum;
	scanf("%d", &testNum);
	for (int testInd = 1; testInd <= testNum; testInd++)
	{
		printf("Case #%d: ", testInd);
		scanf("%d%lf%d", &n, &p, &x);
		f[0][0] = 0;
		f[0][1] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < (1 << i); j++)
			{
				f[i][j] = 0;
				for (int k = 0; k <= j; k++)
					f[i][j] = max(f[i][j], f[i - 1][(j + k) / 2] * p + f[i - 1][(j - k) / 2] * (1 - p));
			}
			f[i][0] = 0;
			f[i][1 << i] = 1;
		}
		for (int j = (1 << n); j >= 0; j--)
			if ((long long) 1000000 * j <= (((long long) x) << n))
			{
				printf("%.6lf\n", f[n][j]);
				break;
			}
	}
	return 0;
}



