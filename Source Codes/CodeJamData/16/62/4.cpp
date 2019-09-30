#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e7 + 100;
const ll MOD = 1e9 + 7;

ifstream fin ("B.in");
ofstream fout ("B.out");

int N, K;
ll res[MAXN];

ll cpow (ll b, ll e)
{
	ll pow = b, res = 1;
	while (e)
	{
		if (e % 2 == 1)
			res = (res * pow) % MOD;
		e /= 2;
		pow = (pow * pow) % MOD;
	}
	return res;
}

ll inv (ll x)
{
	return cpow (x, MOD - 2);
}

int main()
{
	for (int i = 0; i < MAXN; i++)
	{
		res[i] = 0;
	}
	
	res[1] = 1;
	ll cres = 1;
	for (int i = 2; i < MAXN; i++)
	{
		cres = (cres * inv (i - 1)) % MOD;
		if (i % 2 == 0)
			res[i] = (MOD + res[i-1] - cres) % MOD;
		else
			res[i] = (res[i-1] + cres) % MOD;
	}
	
	int ntest; fin >> ntest;
	for (int test = 0; test < ntest; test++)
	{
	
	fin >> N >> K;
	fout << "Case #" << test + 1 << ": ";
	
	ll ans = (res[K] * res[N-K+1]) % MOD;
	ans = (MOD + 1 - ans) % MOD;
	fout << ans << "\n";
	
	}
	
	return 0;
}
