#include <iostream>

using	namespace	std;

const	int	maxlen = 13;

int	ans, cases;
int	l;
char	s[maxlen + 1];
int	f[maxlen + 1];
long long	number[maxlen + 1];
int	flag[maxlen + 1];

void	calc(int dep)
{
	if (dep >= l)
	{
		int	k = 0;
		number[k] = s[0] - '0';
		flag[k] = 1;
		for (int i = 1; i < l; ++i)
		{
			if (f[i] == 0)
				number[k] = number[k] * 10 + (s[i] - '0');
			else
			{
				++k;
				number[k] = s[i] - '0';
				flag[k] = f[i];
			}
		}
		long long result = 0;
		for (int i = 0; i <= k; ++i)
			result += number[i] * flag[i];
		if (result % 2 == 0 || result % 3 == 0 || result % 5 == 0 || result % 7 == 0)
			++ans;
		return;
	}
	f[dep] = 0;	calc(dep + 1);
	f[dep] = 1;	calc(dep + 1);
	f[dep] = -1;	calc(dep + 1);
}

void	solve()
{
	scanf("%s", s);
	l = strlen(s);
	if (l == 1)
	{
		int	x = s[0] - '0';
		if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0)
			ans = 1;
		else
			ans = 0;
		printf("Case #%d: %d\n", ++cases, ans);
		return;
	}
	ans = 0;
	f[0] = 1;

	calc(1);

	printf("Case #%d: %d\n", ++cases, ans);
}

int	main()
{
	int	t;
	scanf("%d", &t);
	while (t--)	solve();
	return	0;
}

