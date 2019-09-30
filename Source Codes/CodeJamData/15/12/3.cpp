#include <bits/stdc++.h>
using namespace std;

long long n, myRank;
long long x[100001];

void solve()
{
	cin >> n >> myRank;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	long long L = -1, R = 1000000000000000000LL, M;
	while(R - L > 1)
	{
		M = (L + R) / 2;
		long long cnt = 0;
		for(int i = 1; i <= n; i++)
			cnt += M / x[i] + 1;
		if(cnt >= myRank)
			R = M;
		else
			L = M;
	}

	long long cnt = 0;
	for(int i = 1; i <= n; i++)
		cnt += (R-1) / x[i] + 1;
	
	for(int i = 1; i <= n; i++)
		if(R % x[i] == 0)
		{
			cnt ++;
			if(cnt == myRank)
			{
				cout << i << endl;
				return;
			}
		}
	cout << cnt << ".." << myRank << endl;
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
