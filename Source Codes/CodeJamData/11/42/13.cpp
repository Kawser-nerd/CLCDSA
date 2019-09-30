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
int N, M, ExpMass;
int P[500][500];
long long Q1[501][501], Q2[501][501], QQ[501][501];

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		cin >> N >> M >> ExpMass;
		for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++)
		{
			char Ch;
			cin >> Ch;
			P[X][Y] = Ch - '0';
		}
		memset(Q1, 0, sizeof(Q1));
		memset(Q2, 0, sizeof(Q2));
		memset(QQ, 0, sizeof(QQ));
		for (int X = 1; X <= N; X++) for (int Y = 1; Y <= M; Y++)
		{
			long long Temp = P[X - 1][Y - 1] * (X - 1);
			Q1[X][Y] = Q1[X - 1][Y] + Q1[X][Y - 1] + Temp - Q1[X - 1][Y - 1];
			Temp = P[X - 1][Y - 1] * (Y - 1);
			Q2[X][Y] = Q2[X - 1][Y] + Q2[X][Y - 1] + Temp - Q2[X - 1][Y - 1];
			Temp = P[X - 1][Y - 1];
			QQ[X][Y] = QQ[X - 1][Y] + QQ[X][Y - 1] + Temp - QQ[X - 1][Y - 1];
		}
		int Answer = 1;
		for (int X = 0; X < N - 1; X++) for (int Y = 0; Y < M - 1; Y++)
		{
			for (int L = Answer + 1; L <= N; L++)
			{
				if (X + L > N || Y + L > M) break;
				long long Mass = QQ[X + L][Y + L] - QQ[X][Y + L] - QQ[X + L][Y] + QQ[X][Y] - P[X][Y] - P[X][Y + L - 1] - P[X + L - 1][Y] - P[X + L - 1][Y + L - 1];
				long long Temp = Q1[X + L][Y + L] - Q1[X][Y + L] - Q1[X + L][Y] + Q1[X][Y];
				Temp -= (P[X][Y] + P[X][Y + L - 1]) * X + (P[X + L - 1][Y] + P[X + L - 1][Y + L - 1]) * (X + L - 1);
				if (Temp * 2 != (X + X + L - 1) * (Mass)) continue;
				Temp = Q2[X + L][Y + L] - Q2[X][Y + L] - Q2[X + L][Y] + Q2[X][Y];
				Temp -= (P[X][Y] + P[X + L - 1][Y]) * Y + (P[X][Y + L - 1] + P[X + L - 1][Y + L - 1]) * (Y + L - 1);
				if (Temp * 2 != (Y + Y + L - 1) * (Mass)) continue;
				if (L > Answer) Answer = L;
			}
		}
		printf("Case #%d: ", TT);
		if (Answer >= 3) printf("%d\n", Answer);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
