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

struct item
{
	int Begin, End, Len, Sp;
};

struct item_less
{
	bool operator()(const item& A, const item& B) const
	{
		return A.Sp < B.Sp;
	}
};

int NN, TT;
int Len, N, Sp, RunSp;
double MaxT;
item P[10000];

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		cin >> Len >> Sp >> RunSp >> MaxT >> N;
		for (int I = 0; I < N; I++)
		{
			cin >> P[I].Begin >> P[I].End >> P[I].Sp;
			P[I].Len = P[I].End - P[I].Begin;
			Len -= P[I].Len;
		}
		P[N].Len = Len;
		P[N].Sp = 0;
		N++;
		sort(P, P + N, item_less());
		double TotTime = 0;
		for (int I = 0; I < N; I++)
		{
			double Time = P[I].Len / double(P[I].Sp + RunSp);
			if (Time > MaxT)
			{
				double Temp = (P[I].Sp + RunSp) * MaxT;
				Time = MaxT + (P[I].Len - Temp) / double(P[I].Sp + Sp);
				MaxT = 0;
			}
			else
				MaxT -= Time;
			TotTime += Time;
		}
		printf("Case #%d: %.12f\n", TT, TotTime);
	}
	return 0;
}
