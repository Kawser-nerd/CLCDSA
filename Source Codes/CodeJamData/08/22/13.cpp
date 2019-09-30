#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef vector<int>		VI;

const int MAX = 1001000;

int comp[MAX] = {0};
VI primes;

int un[1001000];

int find(int x)
{
	if (un[x] == x)
		return x;
	return un[x] = find(un[x]);
}

void unite(int x, int y)
{
	if (rand() % 2)
		un[find(x)] = find(y);
	else
		un[find(y)] = find(x);
}

int main()
{
	for (long long n = 2; n < MAX; n++)
		if (!comp[n])
		{
			primes.push_back(n);
			for (long long i = n*n; i < MAX; i += n)
				comp[i] = 1;
		}

	int kases, kase = 0;
	for (cin >> kases; kases; kases--)
	{
		long long A, B, P;
		cin >> A >> B >> P;

		for (long long i = A; i <= B; i++)
			un[i-A] = i-A;
		for (int i = 0; i < primes.size(); i++)
			if (primes[i] >= P)
			{
				const int P = primes[i];
				long long pos = (A / P) * P;
				while (pos < A)
					pos += P;
				int ref = pos-A;
				pos += P;
				while (pos <= B)
				{
					unite(ref, pos-A);
					pos += P;
				}
			}

		int res = 0;
		for (long long i = A; i <= B; i++)
			if (un[i-A] == (i-A))
				res++;
		cout << "Case #" << ++kase << ": " << res << endl;
	}
	return 0;
}
