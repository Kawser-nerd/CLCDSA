#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int m[2][1000];

bool cmp(const int &a, const int &b)
{
	return a > b;
}


int main()
{
	freopen("c:\\1.txt", "r", stdin);
	freopen("c:\\1_out.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int te = 1; te <= t; te++)
	{
		int n;
		scanf("%d\n", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m[0][i]);
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m[1][i]);
		}

		sort(m[0], m[0]+n);
		stable_sort(m[1], m[1]+n, cmp);

		long long s = 0;

		for (int i = 0; i < n; i++)
		{
			s += ((long long) m[0][i])*((long long) m[1][i]);
		}


		printf("Case #%d: %lld\n", te, s);
	}




	return 0;
}