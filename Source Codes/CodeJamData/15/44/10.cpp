// Problem : gcj r2 D
// Author : Leo Yu

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long LL;

#define link Link
#define next Next
#define elif else if

inline int read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}

LL	f[1000];
const int MOD = 1000000007;


LL	power(LL x, LL y)
{
	LL ans = 1;
	for (; y; y >>= 1)
	{
		if (y & 1)
			ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

int main()
{
	
	int T;
	cin >> T;
	for (int _ = 1; _ <= T; ++ _)
	{
		printf("Case #%d: ", _);
		int R = read(), C = read();
		LL	ans = 0;
		for (int i = 1; i <= C; ++ i)
		{
			int N = __gcd(C, i);
			f[0] = 1;
			for (int i = 1; i <= R + 2; ++ i)
			{
				f[i] = 0;
				if (i - 3 >= 0)	f[i] = (f[i] + f[i - 3]) % MOD;
				if (i - 4 >= 0)
				{
					if (N % 6 == 0)
						f[i] = (f[i] + f[i - 4] * 6) % MOD;
					if (N % 3 == 0)
						f[i] = (f[i] + f[i - 4] * 3) % MOD;
				}
				if (i - 5 >= 0)
					if (N % 4 == 0)
						f[i] = (f[i] + f[i - 5] * 4) % MOD;
			}
			ans = (ans + f[R]) % MOD;
			ans = (ans + f[R]) % MOD;
			ans = (ans + f[R + 2]) % MOD;
			ans = (ans + f[R - 2]) % MOD;
		}
		ans = ans * power(C, MOD - 2) % MOD;
		cout << ans << endl;
	}

	return 0;
}