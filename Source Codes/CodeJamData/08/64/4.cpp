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

int NN, TT;
int N, M;
int ADegs[200], BDegs[200];
int ALinks[200][200], BLinks[200][200];

vector<vector<int> > Graph;
bool Marks[200];
int RIndexes[200];

bool dfs(int A)
{
	if (A < 0) return true;
	if (Marks[A]) return false;
	Marks[A] = true;
	for (int I = 0; I < (int)Graph[A].size(); I++)
	{
		int B = Graph[A][I];
		if (dfs(RIndexes[B]))
		{
			RIndexes[B] = A;
			return true;
		}
	}
	return false;
}

int max_match(int AN, int BN, const vector<vector<int> >& Graph)
{
	::Graph = Graph;
	for (int I = 0; I < BN; I++) RIndexes[I] = -1;
	int Count = 0;
	for (int I = 0; I < AN; I++)
	{
		for (int J = 0; J < AN; J++) Marks[J] = false;
		if (dfs(I)) Count++;
		if (Count >= BN) return Count;
	}
	return Count;
}

bool contains(int A, int AP, int B, int BP)
{
	int AN, BN;
	vector<int> AList(ADegs[A]), BList(BDegs[B]);
	AN = 0;
	for (int I = 0; I < ADegs[A]; I++)
		if (ALinks[A][I] != AP) AList[AN++] = ALinks[A][I];
	BN = 0;
	for (int I = 0; I < BDegs[B]; I++)
		if (BLinks[B][I] != BP) BList[BN++] = BLinks[B][I];
	if (AN < BN) return false;
	if (BN == 0) return true;
	vector<vector<int> > Matches(AN);
	for (int J = 0; J < BN; J++)
	{
		bool Mark = false;
		for (int I = 0; I < AN; I++)
		{
			if (contains(AList[I], A, BList[J], B))
			{
				Matches[I].push_back(J);
				Mark = true;
			}
		}
		if (!Mark) return false;
	}
	return max_match(AN, BN, Matches) >= BN;
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		int X, Y;
		cin >> N;
		for (int I = 0; I < N; I++) ADegs[I] = 0;
		for (int I = 0; I < N - 1; I++)
		{
			cin >> X >> Y;
			X--;
			Y--;
			ALinks[X][ADegs[X]++] = Y;
			ALinks[Y][ADegs[Y]++] = X;
		}
		cin >> M;
		for (int I = 0; I < M; I++) BDegs[I] = 0;
		for (int I = 0; I < M - 1; I++)
		{
			cin >> X >> Y;
			X--;
			Y--;
			BLinks[X][BDegs[X]++] = Y;
			BLinks[Y][BDegs[Y]++] = X;
		}
		bool Ok = false;
		for (int I = 0; I < N; I++)
			if (contains(I, -1, 0, -1))
			{
				Ok = true;
				break;
			}
		printf("Case #%d: ", TT);
		if (Ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}