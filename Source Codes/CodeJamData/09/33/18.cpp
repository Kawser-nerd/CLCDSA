#include <cstdio>
#include <iostream>

using namespace std;

int TESTS;

int dp[128][128];
int pr[128];

int free (int from, int to) {
	int &ret = dp[from][to];
	if (ret < 0) {
		if (from == to) ret = 0;
		else {
			ret = 0x3f3f3f3f;
			for (int i = from; i < to; ++i) {
				int cur = pr[i] - pr[from - 1] - 1;
				cur += pr[to] - pr[i] - 1;
				cur += free (from, i);
				cur += free (i + 1, to);
				if (cur < ret) ret = cur;
			}
		}
	}
	return ret;
}

int main()
{
	freopen ("C-large.in", "rt", stdin);
	freopen ("C-large.out", "wt", stdout);

	cin >> TESTS;
	for (int test = 1; test <= TESTS; ++test)
	{
		int p, q;
		cin >> p >> q;
		for (int i = 1; i <= q; ++i)
			cin >> pr[i];
		pr[0] = 0;
		pr[q + 1] = p + 1;
		memset (dp, 0xff, sizeof (dp));
		cout << "Case #" << test << ": " << free (1, q + 1) << endl;
	}

	return 0;
}