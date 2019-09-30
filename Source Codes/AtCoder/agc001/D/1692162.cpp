#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 110, M = 100010;
vector<int>v, u;
int num, n, k, x;
int main()
{
	scanf("%d%d", &n, &k);
	if (n == 1)
		return puts("1\n1\n1"), 0;
	if (k == 1)
	{
		scanf("%d", &x);
		printf("%d\n%d\n%d %d", x, 2, x - 1, 1);
		return 0;
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &x);
		v.push_back(x);
		if (x & 1)
			swap(v[0], v[i - 1]);
		num += x & 1;
	}
	for (int i = 1; i < k; i++)
		if (v[i] & 1)
			swap(v[i], v[k - 1]);
	if (num > 2)
		puts("Impossible");
	else
	{
		for (int i : v)
			printf("%d ", i);
		printf("\n%d\n", v[0] == 1 ? k - 1 : k);
		if (v[0] != 1)
			printf("%d ", v[0] - 1);
		for (int i = 1; i < k; i++)
			printf("%d ", v[i] + (i == k - 1));
	}
}