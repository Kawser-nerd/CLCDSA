#include <stdio.h>
using namespace std;

#define MAXN 1005

int cas, n, l, r, mid, ans;
char ch[MAXN]; int a[MAXN];

bool solve(int x)
{
	int res = x;
	for (int i = 0; i <= n; i ++)
		if (a[i] > 0)
			if (res >= i)
				res += a[i];
			else
				return false;
	return true;
}

int main()
{
	freopen("A.in", "r", stdin); freopen("A.out", "w", stdout);
	scanf("%d", &cas);
	for (int T = 1; T <= cas; T ++)
	{
		scanf("%d", &n);
		scanf("%s", ch);
		for (int i = 0; i <= n; i ++) a[i] = ch[i] - '0';
		l = 0, r = n * 10;
		while (l <= r)
		{
			mid = (l + r) >> 1;
			if (solve(mid))
				ans = mid, r = mid - 1;
			else
				l = mid + 1; 
		}
		printf("Case #%d: %d\n", T, ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;	
} 
