#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ldouble;

int sum[1000100], n, len;
char s[1000100];
bool vow[500];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	vow['a'] = vow['e'] = vow['i'] = vow['o'] = vow['u'] = true;
	int ts; scanf("%d\n", &ts);
	for (int tst = 0; tst < ts; tst++)
	{
		printf("Case #%d: ", tst + 1);
		scanf("%s%d\n", s, &n); len = strlen(s);
		for (int i = 0; i < len; i++)
			if (!vow[s[i]]) sum[i + 1] = sum[i] + 1;
			else sum[i + 1] = sum[i];
		for (int i = len; i >= n; i--)
			if (sum[i] - sum[i - n] == n) sum[i] = 1;
			else sum[i] = 0;
		for (int i = n - 1; i >= 0; i--)
			sum[i] = 0;
		sum[0] = 0;
		ll ans = 0;
		for (int i = 1; i <= len; i++)
		{
			if (sum[i] == 1) sum[i] = i;
			else sum[i] = sum[i - 1];
			ans += (ll)max(0, sum[i] - n + 1);
		}
		printf("%lld\n", ans);
	}

	return 0;
}