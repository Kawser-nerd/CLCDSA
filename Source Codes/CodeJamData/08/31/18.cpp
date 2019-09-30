#include <iostream>
#include <algorithm>

using	namespace	std;

const	int	maxl = 1000;

int	cases;
int	x[maxl + 1];
long long	sum[maxl + 1];

void	solve()
{
	int	p, k, l;
	scanf("%d%d%d", &p, &k, &l);
	for (int i = 1; i <= l; ++i)	scanf("%d", &x[i]);
	sort(&x[1], &x[l + 1], greater<int>());
	sum[0] = 0;
	for (int i = 1; i <= l; ++i)	sum[i] = sum[i - 1] + x[i];
	long long ans = 0;
	int	a = 0, b = k;
	for (int i = 1; i <= p; ++i)
	{
		if (b > l)
		{
			ans += i * (sum[l] - sum[a]);
			break;
		}
		else
		{
			ans += i * (sum[b] - sum[a]);
			a += k;	b += k;
		}
	}


	printf("Case #%d: %lld\n", ++cases, ans);
}


int	main()
{
	int	t;
	scanf("%d", &t);
	while (t--)	solve();
	return	0;
}

