#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long N;
int n;


long long worst(long long x)
{
	long long u = x, d = N - x - 1;
	long long ans = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (u == 0) // OK
		{
			d = d / 2;
		}
		else // MB
		{
			ans |= (1LL << i);

			d = (d + 1) / 2;
			u = (u - 1) / 2;
		}
	}
	return ans;
}


long long best(long long x)
{
	long long u = x, d = N - x - 1;
	long long ans = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (d == 0) // OK
		{
			ans |= (1LL << i);
			u = u / 2;
		}
		else // MB
		{
			u = (u + 1) / 2;
			d = (d - 1) / 2;
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		long long p;
		scanf("%d%lld", &n, &p);
		N = (1LL << n);

		long long l = 0, r = N;

		while (r - l > 1)
		{
			long long m = (l + r) / 2LL;
			if (worst(m) < p)
				l = m;
			else
				r = m;
		}
		long long ansWorst = l;

		l = 0, r = N;

		while (r - l > 1)
		{
			long long m = (l + r) / 2LL;
			if (best(m) < p)
				l = m;
			else
				r = m;
		}
		long long ansBest = l;

		printf("Case #%d: %lld %lld\n", t + 1, ansWorst, ansBest);
	}



	return 0;
}