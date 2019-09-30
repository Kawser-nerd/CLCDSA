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

long long NN, TT;
long long W, H;
long long OX1, OY1, OX2, OY2;

bool check(long long X, long long Y)
{
	return X >= 0 && X < W && Y >= 0 && Y < H;
}

bool outof(long long X, long long Y)
{
	return X < -100 || X >= W + 100 || Y < -100 || Y >= H + 100;
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		if (TT == 18)
		{
			cout << "";
		}
		long long SX, SY;
		long long Total = 0;
		long long Len = 0;
		cin >> W >> H >> OX1 >> OY1 >> OX2 >> OY2 >> SX >> SY;
		long long X1, Y1, X2, Y2;
		if (OX1 * OY2 - OX2 * OY1 == 0)
		{
			vector<bool> XM(W, false);
			vector<bool> YM(H, false);
			vector<long long> Xs, Ys;
			Xs.push_back(SX);
			Ys.push_back(SY);
			XM[SX] = YM[SY] = true;
			for (long long I = 0; I < (long long)Xs.size(); I++)
			{
				long long X = Xs[I] + OX1;
				long long Y = Ys[I] + OY1;
				if (check(X, Y) && !(XM[X] && YM[Y]))
				{
					Xs.push_back(X);
					Ys.push_back(Y);
					XM[X] = YM[Y] = true;
				}
				X = Xs[I] + OX2;
				Y = Ys[I] + OY2;
				if (check(X, Y) && !(XM[X] && YM[Y]))
				{
					Xs.push_back(X);
					Ys.push_back(Y);
					XM[X] = YM[Y] = true;
				}
			}
			Total = Xs.size();
		}
		else
		{
			Len = 0;
			X1 = SX, Y1 = SY;
			X2 = SX, Y2 = SY;
			while (check(X2, Y2)) X2 += OX1, Y2 += OY1, Len++;
			Total = Len;
			for (;;)
			{
				X1 += OX2, Y1 += OY2;
				while (!check(X1, Y1) && !outof(X1, Y1)) X1 += OX1, Y1 += OY1, Len--;
				if (!check(X1, Y1) || Len <= 0) break;
				X2 += OX2, Y2 += OY2;
				while (!check(X2, Y2) && Len >= 0) X2 -= OX1, Y2 -= OY1, Len--;
				if (Len < 0)
				{
					X2 += OX1, Y2 += OY1, Len++;
					while (!check(X2, Y2) && !outof(X2, Y2)) X2 += OX1, Y2 += OY1, Len++;
					if (!check(X2, Y2)) break;
				}
				while (check(X2, Y2)) X2 += OX1, Y2 += OY1, Len++;
				if (Len < 0) break;
				Total += Len;
			}
		}
		//printf("Case #%d: %d\n", TT, Total);
		cout << "Case #" << TT << ": " << Total << endl;
	}
	return 0;
}