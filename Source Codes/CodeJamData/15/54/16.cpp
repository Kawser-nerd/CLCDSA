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


const int maxn = (1 << 20) + 100;
int _x[maxn], _c[maxn];
vector <int> v;
bool used[maxn];



void solve()
{
	memset(used, false, sizeof used);
	v.clear();
	int p;
	scanf("%d", &p);
	for (int i = 0; i < p; i++)
		scanf("%d", &_x[i] );
	for (int i = 0; i < p; i++)
		scanf("%d", &_c[i] );

	for (int i = 0; i < p; i++)
		for (int j = 0; j < _c[i]; j++)
			v.push_back(_x[i] );
	sort(v.begin(), v.end() );
	int ck = 0;
	while ((1 << ck) < (int) v.size() )
		ck++;

	int n = (int) v.size();
	for (int i = 0; i < ck; i++)
	{
		int j = 1;
		while (used[j] )
			j++;
		int x = v[j];
		printf("%d ", x);
		j = 0;
		int k = 1;
		while (j < n)
		{
			if (used[j] )
			{
				j++;
				continue;
			}
			k = max(k, j + 1);
			while (v[k] != v[j] + x || used[k] )
			{
				k++;
			}
			used[k] = true;
			j++;
			continue;
		}
	}
	printf("\n");
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


