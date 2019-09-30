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

const int	maxN = 210;

typedef vector<int> vi;

map<vi, int>	can;
int		g[maxN][maxN], visit[maxN], ty[maxN];
vi		edgeList[maxN];
int		N, M, s, t;

vi	get(int u, int v, int s, int t)
{
	vi temp;
	temp.push_back(u);
	temp.push_back(v);
	temp.push_back(s);
	temp.push_back(t);
	return temp;
}

int	find(int u)
{
	for (int v = 0; v < t; ++v) if (g[u][v] && !visit[v])
	{
		visit[v] = 1;
		if (ty[v] < 0 || find(ty[v]))
		{
			ty[v] = u;
			return 1;
		}
	}
	return 0;
}

int	match(int u, int v, int x, int y)
{
	vector<int> data = get(u, v, x, y);
	if (can.count(data)) return can[data];

//	printf("%d %d %d %d\n", u, v, x, y);

	int & ret = can[data];

	s = 0; t = 0;


	for (int i = 0; i < edgeList[v].size(); ++i) if (edgeList[v][i] != u) ++s;
	for (int j = 0; j < edgeList[y].size(); ++j) if (edgeList[y][j] != x) ++t;

	int sts = s;
	int stt = t;

	int p, q;
	p = 0;

	for (int i = 0; i < edgeList[v].size(); ++i) if (edgeList[v][i] != u)
	{
		q = 0;
		for (int j = 0; j < edgeList[y].size(); ++j) if (edgeList[y][j] != x)
		{
			match(v, edgeList[v][i], y, edgeList[y][j]);
			++q;
		}
		++p;
	}

	memset(g, 0, sizeof(g));
	p = 0;
	for (int i = 0; i < edgeList[v].size(); ++i) if (edgeList[v][i] != u)
	{
		q = 0;
		for (int j = 0; j < edgeList[y].size(); ++j) if (edgeList[y][j] != x)
		{
			g[p][q] = match(v, edgeList[v][i], y, edgeList[y][j]);
			++q;
		}
		++p;
	}

	s = sts;
	t = stt;

	int cnt = 0;
	memset(ty, 255, sizeof(ty));
	for (int i = 0; i < s; ++i)
	{
		memset(visit, 0, sizeof(visit));
		if (find(i)) ++cnt;
	}
	ret = (t == cnt);
	/*
	if (v == 1 && u == 0 && y == 4 && x == 3)
	{
		cout << g[0][0] << ' ' << g[1][0] << endl;
		cout << s << ' ' << t << ' ' << ret << endl;
	}
	if (v == 0 && u == -1 && y == 3 && x == -1)
	{
		cout << g[0][0] << ' ' << g[1][0] << endl;
		cout << s << ' ' << t << ' ' << ret << endl;
	}
	*/
	return ret;
}

int	main()
{
	int nCase;
	scanf("%d", &nCase);
	for (int nowCase = 1; nowCase <= nCase; ++nowCase)
	{
		can.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) edgeList[i].clear();
		for (int i = 0; i < N - 1; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			edgeList[u].push_back(v);
			edgeList[v].push_back(u);
		}

		scanf("%d", &M);
		for (int i = 0; i < M; ++i) edgeList[N + i].clear();
		for (int i = 0; i < M - 1; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			edgeList[u + N].push_back(v + N);
			edgeList[v + N].push_back(u + N);
		}

		int fd = 0;
		for (int i = 0; !fd && i < N; ++i) if (match(-1, i, -1, N))
		{
//			cout << i << ' ' << N << endl;
			fd = 1;
		}

		printf("Case #%d: ", nowCase);
		if (fd)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
