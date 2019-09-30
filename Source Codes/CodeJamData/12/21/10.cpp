#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, n, t, i, j, S, s[200];

	cin >> T;
	for(t = 1; t <= T; t++)
	{
		cin >> n;
		S = 0;
		for(i = 0; i < n; i++)
		{
			cin >> s[i];
			S += s[i];
		}
		printf("Case #%d:", t);
		for(i = 0; i < n; i++)
		{
			double l = 0.0, r = 1.1, mid;
			for(int it = 0; it < 200; it++)
			{
				mid = (l + r) / 2;
				double myScore = s[i] + S * mid;
				double otherNeed = mid;
				for(j = 0; j < n; j++)
				{
					if (i == j) continue;
					if (s[j] >= myScore) continue;
					otherNeed += (myScore - s[j]) / S;
				}
				if (otherNeed > 1 + 1e-12)
					r = mid;
				else
					l = mid;
			}
			printf(" %.8lf", r * 100);
		}
		puts("");
	}

	return 0;
}