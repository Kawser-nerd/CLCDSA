#include <bits/stdc++.h>
using namespace std;

int n;
long long x[1000001];

void solve()
{
	cin >> n;
	long long way1 = 0, way2 = 0;
	long long maxReduce = 0;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	for(int i = 2; i <= n; i++)
		if(x[i] < x[i-1])
		{
			maxReduce = max(maxReduce, x[i-1] - x[i]);
			way1 += x[i-1] - x[i];
		}
	for(int i = 2; i <= n; i++)
		way2 += min(x[i-1], maxReduce);
	
	
	cout << way1 << " " << way2 << endl;
	
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
