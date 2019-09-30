#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <algorithm>
#include <bitset>
#define MOD 1000000007
 
using ii = std::pair<int, int>;
 
long long int facto[200001];
 
//(x^m) % p
long long int mul(long long int x, long long int m, long long int p)
{
	long long int ans = 1;
 
	while (m > 0)
	{
		if (m % 2 != 0)
		{
			ans *= x;
			ans %= p;
		}
 
		x *= x;
		x %= p;
		m /= 2;
	}
	return ans;
}
 
//(w+h)!/(w!*h!) % mod
long long int count(long long int w, long long int h)
{
	long long int up = facto[w + h - 2];
	long long int down = (facto[w - 1] * facto[h - 1]) % MOD;
 
	return (up * mul(down, MOD - 2, MOD)) % MOD;
}
 
int main()
{
	int h, w, a, b;
	scanf("%d %d %d %d", &h, &w, &a, &b);
 
	facto[0] = 1;
 
	for (int i = 1; i <= h + w; i++)
		facto[i] = (facto[i - 1] * i) % MOD;
 
	long long int total = 0;
 
	for (int k = 1; k <= h-a; k++)
	{
		long long int f = (count(b, k) * count(w - b, h - k + 1) % MOD);
		total = (total + f) % MOD;
	}
 
	printf("%lld", total);
 
	return 0;
}