#include <iostream>

using namespace std;

typedef long long ll;

ll R, K;
int N;
ll g[1 << 11];
ll c[1 << 11];
ll s[1 << 11];

ll solve()
{
	cin >> R >> K >> N;
	for (int i = 0; i < N; i++) { cin >> g[i]; g[i+N] = g[i]; }
	
	for (int i = 0; i < N; i++) 
	{
		int cur = 0;
		int k = 0;
		while (k < N && cur < K)
		{
			if (cur + g[i + k] <= K)
			{
				cur += g[i + k]; k++;
			}
			else
				break;
		}
		s[i] = (i + k) % N;
		c[i] = cur;
	}
	
	ll res = 0;
	int cur = 0;
	for (int i = 0; i < R; i++)
	{
		res += c[cur];
		cur = s[cur];
	}
	return res;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("CC.out", "w", stdout);
	
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		cout << "Case #" << test << ": " << solve() << endl;
	}
	
	return 0;
}