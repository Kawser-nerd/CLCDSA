#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

int N, M;
LL cost[15][15];
LL sum[1 << 15];
LL dp[1 << 15][15];

int main(void)
{
	cin >> N >> M;
	LL total = 0;
	for (int i = 0; i < M; ++i)
	{
		LL a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		cost[a][b] = cost[b][a] = c;
		total += c;
	}
	for (int S = 0; S < (1 << N); ++S)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if ((S & (1 << i)) && (S & (1 << j)))
				{
					sum[S] += cost[i][j];
				}
			}
		}
		sum[S] /= 2;
	}
	memset(dp, 0xc0, sizeof(dp));
	dp[1][0] = 0;
	for (int S = 0; S < (1 << N); ++S)
	{
		for (int i = 0; i < N; ++i)
		{
			const auto& now = dp[S][i];
			//dp[S][i]????
			//1: ?????j??????
			for (int j = 0; j < N; ++j)
			{
				if (S & (1 << j))continue;//??????????
				if (!cost[i][j])continue;//i-j??????????
				auto& next = dp[S | (1 << j)][j];
				next = max(next, now + cost[i][j]);
			}
			//2:i?????sub??????
			int sup = S ^ ((1 << N) - 1);
			int sub = sup;
			do
			{
				//sub?i???????
				LL plus = sum[sub | (1 << i)];
				auto& next = dp[S | sub][i];
				next = max(next, now + plus);
				//??????
				sub = (sub - 1) & sup;
			} while (sub != sup && sub != 0);
		}
	}
	//dp[{1..N}][?]
	LL ans = dp[(1 << N) - 1][N - 1];
	cout << (total - ans) << endl;
	return 0;
}