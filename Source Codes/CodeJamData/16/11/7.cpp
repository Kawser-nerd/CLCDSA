#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int LEN = 1005;
char str[LEN];


void solve()
{
	scanf("%s", str);
	string cur = string(1, str[0] );
	int len = strlen(str);
	string ans = "";
	for (int i = 0; i < len; i++)
	{
		string x = string(1, str[i] );
		if (ans + x > x + ans)
			ans = ans + x;
		else
			ans = x + ans;
	}
	printf("%s\n", ans.c_str() );
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


