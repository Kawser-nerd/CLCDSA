#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

const int DX[] = {1, 1, 0, -1, -1, 0};
const int DY[] = {0, 1, 1, 0, -1, -1};

int A[6 << 10][6 << 10];
int P[36 << 20];
int E[36 << 20];
int V[36 << 20];
int Z[8];
int C[8];

int Parent(int a)
{
	if(a == P[a])
		return a;

	return P[a] = Parent(P[a]);
}

int IsVertex(int x, int y, int z)
{
	if(x == 1 && y == 1)
		return 1;
	if(x == 1 && y == z)
		return 1;
	if(x == z && y == 1)
		return 1;
	if(x == z + z - 1 && y == z)
		return 1;
	if(x == z && y == z + z - 1)
		return 1;
	if(x == z + z - 1 && y == z + z - 1)
		return 1;

	return 0;
}


int IsEdge(int x, int y, int z)
{
	if(x == 1)
		return 1;
	if(x == z + z - 1)
		return 2;
	if(y == 1)
		return 4;
	if(y == z + z - 1)
		return 8;
	if(x - y == z - 1)
		return 16;
	if(y - x == z - 1)
		return 32;

	return 0;
}

int Count(int a){ return a == 0 ? 0 : Count(a >> 1) + (a & 1); }

int SolveTest(int test)
{
	int S, M;
	scanf("%d%d", &S, &M);

	CLEAR(A, -1);
	int i, j, k;
	FOR(i, 0, (S + S)*(S + S))
	{
		P[i] = i;
		E[i] = 0;
		V[i] = 0;
	}
	
	int ret = 0;
	FOR(i, 0, M)
	{
		int x, y;
		scanf("%d%d", &x, &y);

		int res = 0;
		CLEAR(Z, -1);
		FOR(j, 0, 6)
		{
			int xx = x + DX[j];
			int yy = y + DY[j];
			if(A[xx][yy] == -1)
				continue;

			Z[j] = Parent(xx*(S + S) + yy);
		}

		A[x][y] = 0;

		FOR(j, 0, 6)
			if(Z[j] != -1)
			{
				int cnt = 0;
				FOR(k, 0, 6)
					if(Z[k] == Z[j] && Z[(k + 1) % 6] != Z[j])
						++cnt;

				if(cnt > 1)
					res |= 1;
			}

		int cnt = 0;
		FOR(j, 0, 6)
			if(Z[j] != -1)
			{
				FOR(k, j + 1, 6)
					if(Z[k] == Z[j])
						break;

				if(k != 6)
					continue;

				C[cnt] = Z[j];
				++cnt;
			}

		if(cnt == 0)
		{
			C[cnt] = x*(S + S) + y;
			++cnt;
		}

		P[x*(S + S) + y] = C[0];

		FOR(j, 1, cnt)
		{
			V[ C[0] ] += V[ C[j] ];
			E[ C[0] ] |= E[ C[j] ];
			P[ C[j] ] = C[0];
		}

		if(IsVertex(x, y, S))
			++V[ C[0] ];
		else
			E[ C[0] ] |= IsEdge(x, y, S);

		if(V[ C[0] ] >= 2)
			res |= 2;
		if(Count(E[ C[0] ]) >= 3)
			res |= 4;

		if(res != 0)
		{
			ret = res;
			break;
		}
	}

	FOR(j, i + 1, M)
	{
		int x, y;
		scanf("%d%d", &x, &y);
	}

	printf("Case #%d: ", test + 1);
	string R[] = {"none", "ring", "bridge", "bridge-ring", "fork", "fork-ring", "bridge-fork", "bridge-fork-ring"};
	if(ret == 0)
		printf("%s\n", R[0].c_str());
	else
		printf("%s in move %d\n", R[ret].c_str(), i + 1);

	return 0;
}

int main()
{
//	freopen("b.in", "r", stdin);
//	freopen("b.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
