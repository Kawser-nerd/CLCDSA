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

int main(void)
{
	LL D;
	cin >> D;
	vector<LL>ten;
	ten.push_back(1);
	for (int i = 0; i <= 18; ++i)ten.push_back(ten.back() * 10);

	std::function<LL(LL, int, int)>f = [&](LL rem, int lev, int tot)
	{
		//?????
		LL base = ten[tot - 1 - lev] - ten[lev];
		if (base <= 0)
		{
			if (rem == 0)return (tot % 2) * 9 + 1LL;
			return 0LL;
		}
		//div 10^lev mod 10 ???
		LL mod = (rem / ten[lev]) % 10;
		if (rem < 0)
		{
			mod += 10;
			mod %= 10;
		}
		int ma = -mod;
		int mb = ma + 10;
		int za = 10 - abs(ma) - (lev == 0);
		int zb = 10 - abs(mb) - (lev == 0);
		LL ans = f(rem - ma * base, lev + 1, tot);
		ans *= za;
		if (mb < 10)
		{
			LL plus = f(rem - mb * base, lev + 1, tot);
			plus *= zb;
			ans += plus;
		}
		return ans;
	};

	LL ans = 0;
	for (int L = 2; L <= 18; ++L)
	{
		ans += f(D, 0, L);
	}
	cout << ans << endl;

	return 0;
}