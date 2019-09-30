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
int Tots[50][50];
int P[50][50];
int Result;
int MidCount;

bool check(int X, int Y)
{
	return X >= 0 && X < N && Y >= 0 && Y < M;
}

bool valid(int X, int Y)
{
	if (X < 0 || X >= N || Y < 0 || Y >= M) return true;
	int Count = 0;
	for (int XX = X - 1; XX <= X + 1; XX++)
		for (int YY = Y - 1; YY <= Y + 1; YY++)
			if (check(XX, YY)) Count += P[XX][YY];
	return Count == Tots[X][Y];
}

void dfs(int X, int Y)
{
	if (Y == M) return dfs(X + 1, 0);
	if (X >= N)
	{
		if (MidCount > Result) Result = MidCount;
		return;
	}
	if (X == N / 2 + 1 && Y == 0)
	{
		MidCount = 0;
		for (int I = 0; I < M; I++) MidCount += P[N / 2][I];
	}
	if (X > N / 2 && MidCount <= Result) return;
	for (P[X][Y] = 0; P[X][Y] < 2; P[X][Y]++)
	{
		if (!valid(X - 1, Y - 1)) continue;
		if (Y == M - 1 && !valid(X - 1, Y)) continue;
		if (X == N - 1 && !valid(X, Y - 1)) continue;
		if (X == N - 1 && Y == M - 1 && !valid(X, Y)) continue;
		dfs(X, Y + 1);
	}
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		cin >> N >> M;
		for (int X = 0; X < N; X++) for (int Y = 0; Y < M; Y++)
			cin >> Tots[X][Y];
		Result = 0;
		dfs(0, 0);
		printf("Case #%d: %d\n", TT, Result);
	}
	return 0;
}