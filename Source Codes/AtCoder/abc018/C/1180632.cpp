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

int R, C, K;
std::string s[512];
std::vector<std::vector<P>>res;
int ans;

bool check(int x, int y)
{
	int tmp = 0;
	for (int i = y - (K - 1); i <= y + (K - 1); ++i)
	{
		tmp = (i - (y - (K - 1)) < K ? i - (y - (K - 1)) : tmp - 1);
		if (res[x][i].first <= tmp || res[x][i].second <= tmp)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	in >> R >> C >> K;
	rep(i, R) { in >> s[i]; }

	res.resize(R);
	rep(i, R) { res[i].resize(C); }
	rep(i, R)
	{
		rep(j, C)
		{
			for (int u = i; u >= 0; --u)
			{
				if (s[u][j] == 'x') { break; }
				res[i][j].first += (s[u][j] == 'o' ? 1 : 0);
			}
			for (int d = i; d < R; ++d)
			{
				if (s[d][j] == 'x') { break; }
				res[i][j].second += (s[d][j] == 'o' ? 1 : 0);
			}
		}
	}
	for (int x = K - 1; x < R - K + 1; ++x)
	{
		for (int y = K - 1; y < C - K + 1; ++y)
		{
			if (check(x, y) == true) { ++ans; }
		}
	}

	out << ans << std::endl;
	return 0;
}