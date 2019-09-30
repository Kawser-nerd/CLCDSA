#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>
#include <array>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;
typedef std::pair<int, int> P;

int N, M, f[112345];
LL res[112345], dp[112345];

int main()
{
	in >> N >> M;
	rep(i, N) { in >> f[i]; }

	dp[0] = 1;
	LL sum = 1, seek = 0;
	rep(i, N)
	{
		++res[f[i]];
		while (res[f[i]] > 1)
		{
			--res[f[seek]];
			sum -= dp[seek];
			sum %= MOD;
			sum = (sum + MOD) % MOD;
			++seek;
		}
		dp[i + 1] = sum;
		sum += dp[i + 1];
		sum %= MOD;
	}

	out << dp[N] << std::endl;
	return 0;
}