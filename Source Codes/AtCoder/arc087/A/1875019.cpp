#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
using namespace std;

int N;
map<int, int> m;

signed main()
{
	cin >> N;
	REP(i, N)
	{
		int a;
		cin >> a;
		if (CONTAINS_MAP(m, a))
		{
			m[a]++;
		}
		else
		{
			m[a] = 1;
		}
	}

	int ans = 0;
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		int a = it->first;
		int b = it->second;

		if (a > b)
		{
			ans += b;
		}
		else
		{
			int n = b - a;
			int m = b;

			ans += MIN(n, m);
		}
	}
	cout << ans << endl;
}