#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <string>
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

const int DX[] = {-1, 1, 0, 0, -1, 1};
const int DY[] = {0, 0, -1, 1, 1, -1};

int X[1 << 11];
int Y[1 << 11];
int X1[1 << 11];
int Y1[1 << 11];
int X2[1 << 11];
int Y2[1 << 11];
int A[1 << 11][1 << 11];
int B[1 << 11][1 << 11];

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);

	int i, j, k;
	int cntx = 0;
	int cnty = 0;
	FOR(i, 0, N)
	{
		int x, y, xx, yy;
		scanf("%d%d", &x, &y);
		scanf("%d%d", &xx, &yy);

		X1[i] = min(x, xx);
		Y1[i] = min(y, yy);
		X2[i] = max(x, xx) + 1;
		Y2[i] = max(y, yy) + 1;

		X[cntx] = X1[i];
		++cntx;
		Y[cnty] = Y1[i];
		++cnty;
		X[cntx] = X2[i];
		++cntx;
		Y[cnty] = Y2[i];
		++cnty;
	}

	sort(X, X + cntx);
	sort(Y, Y + cnty);

	cntx = unique(X, X + cntx) - X;
	cnty = unique(Y, Y + cnty) - Y;

	CLEAR(A, 0);

	FOR(i, 0, N)
	{
		int x = lower_bound(X, X + cntx, X1[i]) - X;	
		int y = lower_bound(Y, Y + cnty, Y1[i]) - Y;	
		int xx = lower_bound(X, X + cntx, X2[i]) - X;	
		int yy = lower_bound(Y, Y + cnty, Y2[i]) - Y;

		FOR(j, x, xx)
		{
			++A[j][y];
			--A[j][yy];
		}
	}

	FOR(i, 0, cntx)
		FOR(j, 1, cnty)
		{
			A[i][j] += A[i][j - 1];
//			if(A[i][j] < 0)
//				throw 0;
		}

	CLEAR(B, 0);
	int res = 0;
	FOR(i, 0, cntx - 1)
		FOR(j, 0, cnty - 1)
			if(B[i][j] == 0 && A[i][j] != 0)
			{
				int Min = X[i] + Y[j];
				int MaxX = X[i + 1];
				int MaxY = Y[j + 1];

				queue<PII> Q;
				Q.push(PII(i, j));
				B[i][j] = 1;
				while(!Q.empty())
				{
					int x = Q.front().first;
					int y = Q.front().second;
					Q.pop();

//					if(x == cntx - 1 || y == cnty - 1)
//						throw 0;

					Min = min(Min, X[x] + Y[y]);
					MaxX = max(MaxX, X[x + 1]);
					MaxY = max(MaxY, Y[y + 1]);

					FOR(k, 0, 6)
					{
						int xx = x + DX[k];
						int yy = y + DY[k];
						if(xx < 0 || xx >= cntx || yy < 0 || yy >= cnty || B[xx][yy] != 0 || A[xx][yy] == 0)
							continue;

						B[xx][yy] = 1;
						Q.push(PII(xx, yy));
					}
				}

				res = max(res, MaxX + MaxY - Min - 1);
			}

	printf("Case #%d: %d\n", test + 1, res);

	return 0;
}

int SolveTest2(int test)
{
	int N;
	scanf("%d", &N);

	CLEAR(A, 0);

	int i, j, k;
	FOR(i, 0, N)
	{
		int x, y, xx, yy;
		scanf("%d%d", &x, &y);
		scanf("%d%d", &xx, &yy);

		if(x > xx)
			swap(x, xx);
		if(y > yy)
			swap(y, yy);

		FOR(j, x, xx + 1)
			FOR(k, y, yy + 1)
				A[j][k] = 1;
	}

	FOR(i, 0, 128)
	{
		FOR(j, 0, 128)
			printf("%c", A[i][j] ? '*' : '.');
		printf("\n");
	}

	int res = 0;
	while(true)
	{
		int found = 0;
		FOR(i, 0, 128)
			FOR(j, 0, 128)
				if(A[i][j])
					found = 1;

		if(found == 0)
			break;

		++res;

		FOR(i, 0, 128)
			FOR(j, 0, 128)
			{
				B[i][j] = 0;
				if(i > 0 && j > 0 && A[i][j] + A[i - 1][j] + A[i][j - 1] > 1)
					B[i][j] = 1;
			}

		FOR(i, 0, 128)
			FOR(j, 0, 128)
				A[i][j] = B[i][j];
	}

	printf("Case #%d: %d\n", test + 1, res);
	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

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
