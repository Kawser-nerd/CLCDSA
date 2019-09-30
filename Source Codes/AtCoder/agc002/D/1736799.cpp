#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
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
#include <iterator>
#include <bitset>
#include <ctime>
#include<complex>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1000 * 100 + 47;

struct Array
{
	vector<PII> T[MAX];
	void set(int time,int ind, int val)
	{
		T[ind].push_back(MP(time, val));
	}

	int get(int time, int ind)
	{
		int i = upper_bound(ALL(T[ind]), MP(time, INF)) - T[ind].begin();
		return T[ind][i - 1].second;
	}

	void print(int a)
	{
		FOR(i, 0, SZ(T[a]))
		{
			cout << T[a][i].first << "," << T[a][i].second << " ";
		}

		cout << endl;
	}
};

struct DSU
{
	Array P;
	Array S;
	void init(int n)
	{
		FOR(i, 0, n)
		{
			P.set(-1, i, i);
			S.set(-1, i, 1);
		}
	}

	int getParent(int time, int v)
	{
		int p = P.get(time, v);
		if (p == v) return v;
		p = getParent(time, p);
		P.set(time, v, p);
		return p;
	}

	int getParent1(int time, int v)
	{
		int p = P.get(time, v);
		if (p == v) return v;
		return getParent1(time, p);
	}

	void unionSet(int time, int a, int b)
	{
		//cout <<"!!" << time << " " << a  << " " << b  << endl;
		a = getParent(time, a);
		b = getParent(time, b);
		if (a == b) return; 
		if (S.get(time, a) > S.get(time, b))
		{
			swap(a, b);
		}
		//cout << "??" << time << " " << a  << " " << b << endl;

		P.set(time, a, b);
		//P.print(a);
		int i = upper_bound(ALL(P.T[a]), MP(time, INF)) - P.T[a].begin();

		//cout << "**" << i << endl;
		//cout << "*" << P.get(time, a) << endl;
		int newS = S.get(time, b) + S.get(time, a);
		//cout << "*" << newS << endl;
		S.set(time, b, newS);
	}

	int getS(int time, int a, int b)
	{
		a = getParent1(time, a);
		b = getParent1(time, b);
		if (a == b) return S.get(time, a);
		//cout << a << " " << b << " " << S.get(time, a) << " " << S.get(time, b) << endl;
		//FOR(i, 0, SZ(S.T[a])) cout << S.T[a][i].first << " " << S.T[a][i].second<< endl;
		//cout << endl;
		return S.get(time, a) + S.get(time, b);
	}
} dsu;

int A[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	dsu.init(n);
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		dsu.unionSet(i, a, b);
	}

	//FOR(i, 0, n)
	//{
	//	cout << i << ":" << endl;
	//	FOR(j, 0, SZ(dsu.P.T[i]))
	//	{
	//		cout << dsu.P.T[i][j].first << " " << dsu.P.T[i][j].second + 1 << endl;;
	//	}
	//	
	//}

	int q;
	cin >> q;
	FOR(i, 0, q)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		int l = -1, r = m - 1;
		while (r - l > 1)
		{
			int c = (r + l) / 2;
			if (dsu.getS(c, x, y) >= z)
			{
				r = c;
			}
			else
			{
				l = c;
			}
		}

		cout << r + 1 << endl;
	}
}