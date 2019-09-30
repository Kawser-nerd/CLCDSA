#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable: 4018)
#ifdef NDEBUG
	#define _SECURE_SCL 0
#endif
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

int NN, TT;
const int MAXN = 2000000;
bool Marks[MAXN + 1];
int PCount;
int Primes[MAXN + 1];

int solve(long long N)
{
	if (N == 1) return 0;
	int MaxAns = 1;
	int MinAns = 0;
	for (int I = 0; (long long)Primes[I] * Primes[I] <= N; I++)
	{
		int Pr = Primes[I];
		MinAns++;
		long long M = N;
		while (M >= Pr)
		{
			MaxAns++;
			M /= Pr;
		}
	}
	return MaxAns - MinAns;
}

int main()
{
	memset(Marks, 1, sizeof(Marks));
	PCount = 0;
	for (int I = 2; I <= MAXN; I++)
		if (Marks[I])
		{
			Primes[PCount++] = I;
			for (int J = I + I; J <= MAXN; J += I)
				Marks[J] = false;
		}

	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		long long N;
		cin >> N;
		printf("Case #%d: %d\n", TT, solve(N));
	}
	return 0;
}
