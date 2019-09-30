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

//true->Yes
//false->No
inline bool ask(LL x)
{
	cout << "? " << x << endl;
	char c[2];
	cin >> c;
	return c[0] == 'Y';
}

inline void answer(LL x)
{
	cout << "! " << x << endl;
	exit(0);
}

int main(void)
{
	if (ask(10000000000LL))
	{
		//N = 10^k
		LL ten = 1;
		for (int k = 1; true; ++k)
		{
			ten *= 10;
			bool ret = ask(ten - 1);
			if (ret)
			{
				answer(ten / 10);
			}
		}
	}
	else
	{
		//N ? 10^k
		LL ten = 1;
		LL up = -1;
		for (int k = 1; true; ++k)
		{
			ten *= 10;
			bool ret = ask(ten);
			if (!ret)
			{
				up = ten;
				break;
			}
		}
		LL dn = up / 10;
		while (dn + 1 < up)
		{
			LL mid = (up + dn) / 2;
			if (ask(mid * 10))
			{
				up = mid;
			}
			else
			{
				dn = mid;
			}
		}
		answer(up);
	}
	return 0;
}