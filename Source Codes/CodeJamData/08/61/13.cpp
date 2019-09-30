/*
	Author		:	Guo Huayang
	Date		:	2008/9/22
	Contest		:	Google Codejam 2008
 */

#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <bitset>
#include <sstream>
#include <algorithm>

using namespace std;

#define	FOR(p, v)		for (typeof((v).begin()) p = (v).begin(); p != (v).end(); ++p)
#define two(x)			(1<<(x))
#define twoL(x)			(((int64)(1))<<(x))
#define contain(s,x)		((s&two(x))>0)
#define containL(s,x)		((s&twoL(x))>0)

typedef	long long		int64;
typedef unsigned long long	uint64;
typedef pair<int,int>		ipair;
int countbit(int n)		{ return (n == 0) ? 0 : (1 + countbit( n & (n - 1))); }
int lowbit(int n)		{ return (n ^ (n - 1)) & n; }

const	double		PI = acos(-1.0);
const	double		eps = 1e-10;

template<class T>T sqr(T x)			{ return x * x; }
template<class T> void takemin(T &a, T b)	{ if (b < a) a = b; }
template<class T> void takemax(T &a, T b)	{ if (b > a) a = b; }

template<class T> void print(T *A, int n)
{
	for (int i = 0; i < n; ++i) cout << A[i] << ' ';
	cout << endl;
}

template<class T> void print(vector<T> A, int n)
{
	if (n < 0) n = A.size();
	for (int i = 0; i < n; ++i) cout << A[i] << ' ';
	cout << endl;
}

template<class T> string toString(T n)
{
	ostringstream sout;
	sout << n;
	return sout.str();
}

int toInt(string s)
{
	int v;
	istringstream sin(s);
	sin >> v;
	return v;
}

int toInt64(string s)
{
	int64 v;
	istringstream sin(s);
	sin >> v;
	return v;
}

const int	maxN = 10000;
const int	INF = 100000000;

int		N, M;
int		x[maxN], y[maxN];
char		cmd[maxN][10];

int	main()
{
	int nCase;
	scanf("%d", &nCase);
	for (int nowCase = 1; nowCase <= nCase; ++nowCase)
	{
		printf("Case #%d:\n", nowCase);
		scanf("%d", &N);
		int minx = INF, maxx = 0, miny = INF, maxy = 0;
		int flag = 0;
		char temp[100];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d%d%s", &x[i], &y[i], cmd[i]);
			if (cmd[i][0] == 'B')
			{
				flag = 1;
				minx <?= x[i];
				maxx >?= x[i];
				miny <?= y[i];
				maxy >?= y[i];
			}
			else
			{
				scanf("%s", temp);
			}
		}

		scanf("%d", &M);

		for (int i = 0; i < M; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			if (!flag)
			{
				printf("UNKNOWN\n");
				continue;
			}
			if (u <= maxx && u >= minx && v <= maxy && v >= miny)
			{
				printf("BIRD\n");
				continue;
			}
			int ok = 1;
			for (int j = 0; ok && j < N; ++j) if (cmd[j][0] == 'N')
			{
				if (x[j] > maxx && y[j] > maxy && u >= x[j] && v >= y[j]) ok = 0;
				if (x[j] > maxx && y[j] < miny && u >= x[j] && v <= y[j]) ok = 0;
				if (x[j] < minx && y[j] > maxy && u <= x[j] && v >= y[j]) ok = 0;
				if (x[j] < minx && y[j] < miny && u <= x[j] && v <= y[j]) ok = 0;
				if (x[j] >= minx && x[j] <= maxx)
				{
					if (y[j] > maxy && v >= y[j]) ok = 0;
					if (y[j] < miny && v <= y[j]) ok = 0;
				}
				if (y[j] >= miny && y[j] <= maxy)
				{
					if (x[j] > maxx && u >= x[j]) ok = 0;
					if (x[j] < minx && u <= x[j]) ok = 0;
				}
			}
			if (ok)
				printf("UNKNOWN\n");
			else
				printf("NOT BIRD\n");
		}
	}
	return 0;
}
