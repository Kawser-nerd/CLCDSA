#include <cstdio>
#include <cmath>

void OpenFiles()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

__int64 Sqrt(__int64 num)
{
	__int64 l = 0, r = (__int64)sqrt((double)num)+300;
	while (l < r)
	{
		__int64 m = (l+r)/2;
		if (m*m < num)
			l = m+1;
		else
			r = m;
	}
	return l;
}


void Solve(int testId)
{
	__int64 l, p, c;
	scanf("%I64d%I64d%I64d", &l, &p, &c);
	int ans = 0;
	while (l*c < p)
	{
		p = Sqrt(l*p);
		ans++;
	}
	printf("Case #%d: %d\n", testId, ans);
}

int main()
{
	OpenFiles();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		Solve(i+1);

	return 0;
}