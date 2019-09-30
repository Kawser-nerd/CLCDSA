#include <iostream>
#include <string>
using namespace std;

const string w = "welcome to code jam";
int cnt[599][20];

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int N; cin >> N; string g;
	getline(cin, g);
	for (int t = 0; t < N; t++)
	{
		string s; getline(cin, s);
		memset(cnt, 0, sizeof cnt);
		cnt[0][0] = 1;
		int ans = 0;
		for (int i = 1; i <= s.size(); i++)
		{
			cnt[i][0] = 1;
			for (int j = 1; j <= w.size(); j++)
			{
				cnt[i][j] = cnt[i-1][j];
				if (s[i-1] == w[j-1])
					cnt[i][j] += cnt[i-1][j-1], cnt[i][j] %= 10000;
				//printf("cnt[%d][%d] = %d\n", i, j, cnt[i][j]);
			}
		}

		printf("Case #%d: %04d\n", t+1, cnt[s.size()][w.size()]);
	}
}