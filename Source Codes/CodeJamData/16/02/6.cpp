#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin >> s;
	int ret = 0;
	for(int i = 1; i < s.length(); i++)
		if(s[i] != s[i-1])
			ret ++;
	if(s[s.length()-1] == '-')
		ret ++;
	cout << ret << endl;
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
