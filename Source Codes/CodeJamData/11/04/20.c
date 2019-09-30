#include <iostream>
using namespace std;

int main()
{
	int icase, ncase;
	int i, n;
	int fflag;
	int arr[1005];
	double res;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		res = 0;
		scanf("%d", &n);
		for(i = 0;i < n;i++)
		{
			scanf("%d", &arr[i]);
			if (arr[i] != i + 1)
				res += 1;
		}
		printf("Case #%d: %.6lf\n", icase, res);
	}
	return 0;
}
