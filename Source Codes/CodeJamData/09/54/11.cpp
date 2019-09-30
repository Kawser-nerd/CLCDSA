#include <iostream>
#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<long long>	VI;

const long long MOD = 1000000007;

VI palin;

long long flip(long long x)
{
	long long res = 0, tx = x;
	while (tx)
	{
		res *= 10;
		res += tx % 10;
		tx /= 10;
	}
	tx = x;
	while (tx)
	{
		x *= 10;
		tx /= 10;
	}
	return res + x;
}
long long flip2(long long x)
{
	long long res = 0, tx = x / 10;
	while (tx)
	{
		res *= 10;
		res += tx % 10;
		tx /= 10;
	}
	tx = x / 10;
	while (tx)
	{
		x *= 10;
		tx /= 10;
	}
	return res + x;
}


long long even[11100100], odd[11100100];

int main()
{
	for (int x = 1; x < 1000000; x++)
		palin.push_back(flip(x));
	for (int x = 1; x < 10000000; x++)
		palin.push_back(flip2(x));
	sort(palin.begin(), palin.end());
//	cout << palin.back() << endl;

	int kases;
	cin >> kases;
	for (int kase = 1; kase <= kases; kase++)
	{
		long long L, R;
		cin >> L >> R;
		const int idxL = distance(palin.begin(), lower_bound(palin.begin(), palin.end(), L));
		const int idxR = distance(palin.begin(), upper_bound(palin.begin(), palin.end(), R)) - 1;

//		assert(palin[idxL] >= L && palin[idxR] <= R);

		long long res = 0;
		if (idxL > idxR)
		{
			long long len = R - L + 1;
			res = len * (len+1) / 2;
		}
		else
		{
			const int N = idxR - idxL;
			long long lenL = palin[idxL] - L;

			res = (lenL * (lenL+1) / 2) % MOD;
			even[0] = 0;
			odd[0] = (palin[idxL] - L + 1) % MOD;

			for (int i = 1; i <= N; i++)
			{
				long long mid = palin[idxL + i] - palin[idxL + i - 1] - 1;
				res = (res + ((even[i-1] * (mid+1)) % MOD)) % MOD;
				res = (res + mid * (mid+1) / 2) % MOD;
				even[i] = odd[i-1];
				odd[i] = (even[i-1] + mid+1) % MOD;

//				cout << i << " (" << palin[idxL+i] << "): " << even[i] << " " << odd[i] << endl;
			}

			long long lenR = R - palin[idxR];
			assert(lenR <= MOD);
			res = (res + ((even[N] * (lenR+1)) % MOD)) % MOD;
			res = (res + lenR * (lenR+1) / 2) % MOD;
		}

		cout << "Case #" << kase << ": " << (res % MOD) << endl;
	}
	return 0;
}

