//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>
//#include <unordered_set>
#define INF 2147483647
#define MAXN  1000100
#define PII pair<int, int>
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 35;
ll a[MAXN];

int main()
{
	//ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef local_debug
	ifstream inputs("input.txt");
	cin.rdbuf(inputs.rdbuf());
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	while (cin >> n >> k) {
		ll ans = 0;
		for (int i = k + 1; i <= n; i++) {
			int sz = n / i;
			ans += sz * (i - k);
			int j = n % i;
			if (j - k + 1 > 0)
				ans += j - k + 1;
		}
		if (k == 0)
			ans -= n;
		cout << ans << endl;
	}
	return 0;
}