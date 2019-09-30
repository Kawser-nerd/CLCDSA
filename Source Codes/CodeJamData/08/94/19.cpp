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

const int XOffs[4] = {0, 1, 0, -1};
const int YOffs[4] = {1, 0, -1, 0};

int NN, TT;
int N, M;
char Map[30][30];
int ADis[30][30], BDis[30][30];
int Marks[30][30];

bool check(int X, int Y)
{
	return X >= 0 && X < N && Y >= 0 && Y < M && Map[X][Y] != '.';
}

void bfs(int SX, int SY, int Dis[30][30])
{
	int Xs[1000], Ys[1000];
	int Len;
	for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++) Dis[X][Y] = -1;
	Dis[SX][SY] = 0;
	Xs[0] = SX;
	Ys[0] = SY;
	Len = 1;
	for (int I = 0; I < Len; I++)
	{
		int X = Xs[I];
		int Y = Ys[I];
		for (int D = 0; D < 4; D++)
		{
			int XX = X + XOffs[D];
			int YY = Y + YOffs[D];
			if (check(XX, YY) && Dis[XX][YY] < 0)
			{
				Dis[XX][YY] = Dis[X][Y] + 1;
				Xs[Len] = XX;
				Ys[Len] = YY;
				Len++;
			}
		}
	}
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		int Total = 0;
		int FX = -1, FY = -1;
		cin >> N >> M;
		for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++)
		{
			cin >> Map[X][Y];
			if (Map[X][Y] == 'T' && (X > 0 || Y > 0)) FX = X, FY = Y;
		}
		bfs(0, 0, ADis);
		if (FX >= 0) bfs(FX, FY, BDis);
		memset(Marks, 0, sizeof(Marks));
		if (FX >= 0)
		{
			int X = 0;
			int Y = 0;
			int L = 0;
			while (X != FX || Y != FY)
			{
				int D, XX, YY;
				for (D = 0; D < 4; D++)
				{
					XX = X + XOffs[D];
					YY = Y + YOffs[D];
					if (check(XX, YY) && BDis[XX][YY] == BDis[X][Y] - 1) break;
				}
				X = XX;
				Y = YY;
				L++;
				Total += L;
				Marks[X][Y] = 1;
			}
		}
		Marks[0][0] = 1;
		for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++)
			if (check(X, Y) && Marks[X][Y] == 0)
			{
				int Temp = ADis[X][Y];
				if (FX >= 0 && BDis[X][Y] < Temp) Temp = BDis[X][Y];
				Total += Temp;
			}
		printf("Case #%d: %d\n", TT, Total);
	}
	return 0;
}