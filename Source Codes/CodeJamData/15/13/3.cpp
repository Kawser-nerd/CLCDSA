#include <bits/stdc++.h>
using namespace std;

int n;
double x[3001], y[3001];
double pi = atan(1) * 4;

int solve(vector <double> lis)
{
	if(n == 1)
		return 0;
	lis.push_back(100);
	int p = 0;
	int ret = 1000000;
	for(int i = 0; i < n; i++)
	{
		while(lis[p+1] <= lis[i] + pi - 1e-8)
			p ++;
		ret = min(ret, p - i);
	}
	return ret;
}

void solve()
{
	cin >> n;
	cout << endl;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for(int i = 1; i <= n; i++)
	{
		vector <double> dir;
		for(int j = 1; j <= n; j++)
			if(i != j)
			{
				double v = atan2(y[j] - y[i], x[j] - x[i]);
				dir.push_back(v);
				dir.push_back(v + 2 * pi);
			}
		sort(dir.begin(), dir.end());
		cout << solve(dir) << endl;
	}
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	int start = clock();
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	int ret = MAIN();
	#ifdef LOCAL_TEST
		cout << "[Finished in " << clock() - start << " ms]" << endl;
	#endif
	return ret;
}
