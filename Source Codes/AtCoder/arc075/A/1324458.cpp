//I Guds namn
#include <iostream>

using namespace std;

int dp[10 + 13], bp[10 + 13];

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for(int i = 0;i < n;i++)
	{
		int a; cin >> a;
		for(int j = 0;j < 10;j++)
			if(dp[j] or !j)
				bp[(j + a) % 10] = dp[j] + a;
		for(int j = 0;j < 10;j++)
			dp[j] = max(dp[j], bp[j]);
	}
	int ans = 0;
	for(int i = 1;i < 10;i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}