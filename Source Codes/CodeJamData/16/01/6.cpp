#include <bits/stdc++.h>
using namespace std;

bool have[10];

void add(int x)
{
	while(x)
	{
		have[x % 10] ++;
		x /= 10;
	}
}

bool check()
{
	for(int i = 0; i < 10; i++)
		if(!have[i])
			return false;
	return true;
}

int calc(int x)
{
	memset(have, false, sizeof(have));
	if(x == 0) return -1;
	for(int i = 1; ; i++)
	{
		add(x * i);
		if(check())
			return i;
	}
	return -1;
}

void solve()
{
	int n;
	cin >> n;
	if(n == 0)
		cout << "INSOMNIA" << endl;
	else
		cout << calc(n) * n << endl;
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
