#define _CRT_SECURE_NO_DEPRECATE
#ifdef NDEBUG
	#define _SECURE_SCL 0
#endif
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

int NN, TT;
int N;
int As[10000], Bs[10000], Cs[10000], AList[10000], BList[10000];
bool Marks[10000];
int Total;

struct a_less
{
	bool operator()(int A, int B) const
	{
		return As[A] < As[B];
	}
};

struct b_less
{
	bool operator()(int A, int B) const
	{
		return Bs[A] < Bs[B];
	}
};

bool check(int Id, int A, int B, int C)
{
	return A >= As[Id] && B >= Bs[Id] && C >= Cs[Id];
}

void update(int Id, int A, int B, int C)
{
	bool Mark = check(Id, A, B, C);
	if (Mark != Marks[Id])
		if (Mark) Total++;
		else Total--;
	Marks[Id] = Mark;
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		int Result = 0;
		cin >> N;
		for (int I = 0; I < N; I++) cin >> As[I] >> Bs[I] >> Cs[I];
		for (int I = 0; I < N; I++) AList[I] = BList[I] = I;
		sort(AList, AList + N, a_less());
		sort(BList, BList + N, b_less());
		for (int C = 0; C <= 10000; C++)
		{
			int APos = 0;
			int BPos = N - 1;
			int A = 0;
			int B = 10000 - C;
			Total = 0;
			for (int I = 0; I < N; I++)
			{
				Marks[I] = check(I, A, B, C);
				if (Marks[I]) Total++;
			}
			if (Total > Result) Result = Total;
			while (A < 10000 - C)
			{
				A++;
				B--;
				while (APos < N && As[AList[APos]] <= A)
					update(AList[APos++], A, B, C);
				while (BPos >= 0 && Bs[BList[BPos]] >= B + 1)
					update(BList[BPos--], A, B, C);
				if (Total > Result) Result = Total;
			}
		}
		printf("Case #%d: %d\n", TT, Result);
	}
	return 0;
}