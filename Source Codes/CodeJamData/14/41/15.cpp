#include <cstdio>
#include <algorithm>
using namespace std;

int x, n, s[10000];
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d", &n, &x);
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		sort(s, s + n);
		int st = 0, ed = n;
		while(true)
		{
			ed--;
			while(st < ed && s[st] + s[ed] > x)
				ed--;
			if(st >= ed)
				break;
			st++;
		}
		printf("Case #%d: %d\n", t, n - st);
	}
	return 0;
}
