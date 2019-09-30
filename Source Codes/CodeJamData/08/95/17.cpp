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
int N, M;
char Map[15][15];
int P[16][16][32768];

int bit(int V, int I)
{
	return (V >> I) & 1;
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		cin >> N >> M;
		for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++) cin >> Map[X][Y];
		memset(P, -1, sizeof(P));
		for (int Y = 0; Y <= M; Y++) P[0][Y][0] = 0;
		for (int X = 1; X <= N; X++)
		{
			for (int Flag = 0; Flag < (1 << M); Flag++) P[X][0][Flag] = P[X - 1][M][Flag];
			for (int Y = 1; Y <= M; Y++) for (int F = 0; F < (1 << M); F++)
			{
				if (Map[X - 1][Y - 1] == '.' && bit(F, Y - 1) == 1) continue;
				if (Map[X - 1][Y - 1] == '#' && bit(F, Y - 1) == 0) continue;
				for (int I = 0; I < 2; I++)
				{
					int FF = F & ~(1 << (Y - 1));
					FF |= (I << (Y - 1));
					int Temp = P[X][Y - 1][FF];
					if (Temp < 0) continue;
					if (bit(F, Y - 1))
					{
						Temp += 4;
						if (Y > 1 && bit(F, Y - 2)) Temp -= 2;
						if (I == 1) Temp -= 2;
					}
					if (P[X][Y][F] < 0 || Temp > P[X][Y][F]) P[X][Y][F] = Temp;
				}
			}
		}
		int Result = 0;
		for (int F = 0; F < (1 << M); F++)
			if (P[N][M][F] >= 0 && P[N][M][F] > Result) Result = P[N][M][F];
		printf("Case #%d: %d\n", TT, Result);
	}
	return 0;
}