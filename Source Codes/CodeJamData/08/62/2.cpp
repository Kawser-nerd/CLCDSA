#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const int XOffs[4] = {-1, 0, 0, 1};
const int YOffs[4] = {0, -1, 1, 0};

typedef short map[50][50];
struct map_rec
{
	map Map;
};
int NN, TT;
int N, M, R, C;
map Map;
int Result;

void search(map& Map, int Day)
{
	if (Map[R][C] <= 0) return;
	if (Day > Result) Result = Day;
	map_rec* NewMap = new map_rec;
	map& NMap = NewMap->Map;
	for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++)
		NMap[X][Y] = Map[X][Y];
	for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++)
	{
		if (Map[X][Y] == 0) continue;
		if (X == R && Y == C) continue;
		int Dir = -1;
		int Temp = -1;
		for (int D = 0; D < 4; D++)
		{
			int XX = X + XOffs[D];
			int YY = Y + YOffs[D];
			if (XX >= 0 && XX < N && YY >= 0 && YY < M && Map[XX][YY] > Temp)
			{
				Temp = Map[XX][YY];
				Dir = D;
			}
		}
		NMap[X + XOffs[Dir]][Y + YOffs[Dir]] -= Map[X][Y];
	}
	for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++)
		if (NMap[X][Y] < 0) NMap[X][Y] = 0;
	bool Mark = false;
	for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++)
		if (Map[X][Y] != NMap[X][Y]) Mark = true;
	if (!Mark)
	{
		Result = 99999999;
		return;
	}
	if (NMap[R][C] > 0)
	for (int Dir = -1; Dir < 4; Dir++)
	{
		int Temp = -1;
		if (Dir >= 0)
		{
			int XX = R + XOffs[Dir];
			int YY = C + YOffs[Dir];
			if (!(XX >= 0 && XX < N && YY >= 0 && YY < M)) continue;
			Temp = NMap[XX][YY];
			NMap[XX][YY] -= Map[R][C];
			if (NMap[XX][YY] < 0) NMap[XX][YY] = 0;
		}
		search(NMap, Day + 1);
		if (Result >= 99999999) return;
		if (Dir >= 0)
		{
			int XX = R + XOffs[Dir];
			int YY = C + YOffs[Dir];
			NMap[XX][YY] = Temp;
		}
	}
	delete NewMap;
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		cin >> M >> N >> C >> R;
		R--; C--;
		for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++) cin >> Map[X][Y];
		Result = -1;
		search(Map, 1);
		printf("Case #%d: ", TT);
		if (Result >= 99999999) printf("forever\n");
		else printf("%d day(s)\n", Result - 1);
	}
	return 0;
}