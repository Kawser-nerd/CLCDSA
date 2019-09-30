#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using D = double;
using ii = pair<int, int>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int MOD = 1000000007;

const int maxn = 10005;

int ans[maxn][maxn];
int sumcols[maxn];

inline int powmod(int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1) ans = ((ll)ans * a) % MOD;
		a = ((ll)a * a) % MOD;
		b >>= 1;
	}
	return ans;
}

int divide(int a, int b)
{
	return ((ll)a * powmod(b, MOD - 2)) % MOD;
}

int main()
{
	
	ans[0][0] = 1;
	for (int i = 0; i < maxn; i++) sumcols[i] = 0;
	for (int i = 0; i < maxn; i++)
	{
		int sumrow = 0;
		for (int j = 0; j < maxn; j++)
		{
			if (j > 1) sumrow = (sumrow + ans[i][j - 2]) % MOD;
			if (i > 1) sumcols[j] = (sumcols[j] + ans[i - 2][j]) % MOD;
			int dto = i + j;
			if (dto > 0)
			{
				int cur = (sumcols[j] + sumrow) % MOD;
				ans[i][j] = divide(cur, dto);
			}
// 			cout << i << ' ' << j << ' ' << ans[i][j] << endl;
		}
	}
	
	int NT;
	scanf("%d", &NT);
	
	for (int T = 1; T <= NT; T++)
	{
		printf("Case #%d:", T);
		
		int n, k;
		scanf("%d%d", &n, &k);
		k--;
		
		printf(" %d\n", (1 - ans[k][n - k - 1] + MOD) % MOD);
		
		fprintf(stderr, "%d/%d tests completed!\n", T, NT);
	}

}
