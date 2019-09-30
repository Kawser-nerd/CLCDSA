#include <iostream>
#include <cstring>

using namespace std;

int pl[1000000], pp, pc[1000001];

void getprimelist ()
{
	pp = 0;
	
	memset(pc, 0, sizeof(pc));
	for (int i = 2; i <= 1000000; i ++)
		if (!pc[i])
		{
			pl[pp ++] = i;
			for (int j = i + i; j <= 1000000; j += i)
				pc[j] = 1;
		}
}

int ans (long long n)
{
	if (n == 1) return 0;

	int re = 1;
	
	for (int i = 0; i < pp && pl[i]*(long long)pl[i] <= n; i ++)
	{
		long long tmp = pl[i] * (long long)pl[i];
		while (tmp <= n)
		{
			re ++;
			tmp *= pl[i];
		}
	}
	
	return re;
}

int main ()
{
	int t, ct = 0;
	long long n;
	
	getprimelist();
	
	for (cin >> t; t > 0; t --)
	{
		cin >> n;
		cout << "Case #" << ++ ct << ": " << ans(n) << endl;
	}
	
	return 0;
}
