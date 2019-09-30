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

struct point
{
	int X, Y;
};

int NN, TT;
int N, M, N1, N2;
point Birds[10000], NBirds[10000];
int X1, Y1, X2, Y2, X, Y;

bool check(int X, int Y)
{
	for (int I = 0; I < N2; I++)
	{
		if (NBirds[I].X <= X2 && NBirds[I].Y <= Y2)
		{
			if (X <= NBirds[I].X && Y <= NBirds[I].Y) return true;
		}
		if (NBirds[I].X >= X1 && NBirds[I].Y <= Y2)
		{
			if (X >= NBirds[I].X && Y <= NBirds[I].Y) return true;
		}
		if (NBirds[I].X <= X2 && NBirds[I].Y >= Y1)
		{
			if (X <= NBirds[I].X && Y >= NBirds[I].Y) return true;
		}
		if (NBirds[I].X >= X1 && NBirds[I].Y >= Y1)
			if (X >= NBirds[I].X && Y >= NBirds[I].Y) return true;
	}
	return false;
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		cin >> N;
		N1 = N2 = 0;
		X1 = Y1 = 99999999;
		X2 = Y2 = -1;
		for (int I = 0; I < N; I++) 
		{
			string S;
			cin >> X >> Y >> S;
			if (S == "BIRD")
			{
				Birds[N1].X = X;
				Birds[N1++].Y = Y;
				if (X < X1) X1 = X;
				if (X > X2) X2 = X;
				if (Y < Y1) Y1 = Y;
				if (Y > Y2) Y2 = Y;
			}
			else
			{
				cin >> S;
				NBirds[N2].X = X;
				NBirds[N2++].Y = Y;
			}
		}
		cin >> M;
		printf("Case #%d:\n", TT);
		for (int I = 0; I < M; I++)
		{
			cin >> X >> Y;
			if (X >= X1 && X <= X2 && Y >= Y1 && Y <= Y2)
			{
				printf("BIRD\n");
			}
			else
			{
				if (check(X, Y)) printf("NOT BIRD\n");
				else printf("UNKNOWN\n");
			}
		}	
	}
	return 0;
}