#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

int n, x, y;
double dp[5001][5001];

void solve()
{
	cin >> n >> x >> y;
	if(x < 0)
		x = -x;
	int layer = x + y;
	int isCenter = (x == 0);
	for(int i = 0; i < layer; i += 2)
		n -= i*2 + 1;
	double ans = 0;
	if(n <= 0)
		ans = 0;
	else if(n >= 2*layer+1)
		ans = 1;
	else if(isCenter)
		ans = 0;
	else
	{

		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j <= layer; j++)
			{
			
				if(i-j == layer)
					dp[i+1][j+1] += dp[i][j];
				else if(j == layer)
					dp[i+1][j] += dp[i][j];
				else
				{
					dp[i+1][j] += dp[i][j] * 0.5;
					dp[i+1][j+1] += dp[i][j] * 0.5;
				}
			}
		for(int i = y+1; i <= layer; i++)
			ans += dp[n][i];
	}
	cout << ans << endl;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int CaseID = 1; CaseID <= TestCase; CaseID ++)
	{
		cout << "Case #" << CaseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}

