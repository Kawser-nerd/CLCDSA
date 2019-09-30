#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

void Solve()
{
	int n, k;
	int64 b, t;
	cin >> n >> k >> b >> t;
	vector<int64> x(n), v(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vi w(n, 0);
	vi a;
	for (int i = 0; i < n; i++)
	{
		w[i] = (v[i] * t >= b - x[i]) ? 1 : 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (!w[i]) continue;
		int cnt = 0;
		for (int j = i + 1; j < n; j++)
			if (!w[j]) cnt++;
		a.pb(cnt);
	}
	sort(all(a));
	if (sz(a) < k)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	int res = 0;
	for (int i = 0; i < k; i++)
		res += a[i];
	cout << res << "\n";
}

int main()
{
	int nc;
	cin >> nc;
	for (int it = 0; it < nc; it++)
	{
		printf("Case #%d: ", it + 1);
		Solve();
	}
	return 0;
}
