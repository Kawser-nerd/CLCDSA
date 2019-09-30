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
int N, M;
vector<int> Links[400];
bool Marks[400][400];
int Tab[400][400];

void bfs(int Sour, int P[])
{
	vector<int> Queue;
	Queue.push_back(Sour);
	for (int I = 0; I < N; I++) P[I] = -1;
	P[Sour] = 0;
	for (int Cursor = 0; Cursor < (int)Queue.size(); Cursor++)
	{
		int A = Queue[Cursor];
		for (int I = 0; I < (int)Links[A].size(); I++)
		{
			int B = Links[A][I];
			if (P[B] >= 0) continue;
			P[B] = P[A] + 1;
			Queue.push_back(B);
		}
	}
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		cin >> N >> M;
		memset(Marks, 0, sizeof(Marks));
		for (int I = 0; I < N; I++) Links[I].clear();
		while (M-- > 0)
		{
			int A, B;
			char Ch;
			cin >> A >> Ch >> B;
			Links[A].push_back(B);
			Links[B].push_back(A);
			Marks[A][B] = Marks[B][A] = true;
		}
		int P1[400], P2[400];
		bfs(0, P1);
		bfs(1, P2);
		vector<pair<int, int> > List;
		for (int I = 0; I < N; I++)
			if (P1[I] >= 0 && P2[I] >= 0 && P1[I] + P2[I] == P2[0])
				List.push_back(make_pair(P1[I], I));
		sort(List.begin(), List.end());
		memset(Tab, -1, sizeof(Tab));
		Tab[0][0] = Links[0].size();
		int Answer = 0;
		if (P2[0] == 1) Answer = Links[0].size();
		for (int I = 1; I < (int)List.size() - 1; I++)
		{
			int A = List[I].second;
			for (int J = 0; J < (int)Links[A].size(); J++)
			{
				int B = Links[A][J];
				if (!(P1[B] == P1[A] - 1 && P2[B] == P2[A] + 1)) continue;
				for (int K = -1; K < (int)Links[B].size(); K++)
				{
					int C = K < 0 ? B : Links[B][K];
					if (Tab[C][B] < 0) continue;
					int Temp = Tab[C][B] - 1;
					for (int L = 0; L < (int)Links[A].size(); L++)
					{
						int D = Links[A][L];
						if (D != B && D != C && !Marks[B][D] && !Marks[C][D]) Temp++;
					}
					if (Temp > Tab[B][A]) Tab[B][A] = Temp;
				}
				if (P2[A] == 1 && Tab[B][A] > Answer) Answer = Tab[B][A];
			}
		}
		printf("Case #%d: %d %d\n", TT, P2[0] - 1, Answer);
	}
	return 0;
}
