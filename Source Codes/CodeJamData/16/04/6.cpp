#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int k, c, s;
	cin >> k >> c >> s;
	if(s * c >= k)
	{
		int cur = 0;
		int base = k;
		while(cur < k)
		{
			long long now = 0;
			for(int i = 0; i < c; i++)
			{
				now = now * base + cur;
				cur ++;
				if(cur >= k)
					break;
			}
			cout << now+1 << (cur >= k ? "\n" : " ");
		}
	}
	else
		cout << "IMPOSSIBLE" << endl;
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
