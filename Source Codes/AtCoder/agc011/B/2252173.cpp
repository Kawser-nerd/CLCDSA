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
	int n;
	while (cin >> n) {
		a[n] = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for (int i = 1; i < n; i++) a[i] += a[i - 1];
		int ans = 1;
		for (int i = 0; i < n; i++)
		{
			if (a[i]*2 >= (a[i + 1] - a[i]))
				ans++;
			else
				ans = 1;
		}
		cout << ans-1 << endl;
	}
	return 0;
}