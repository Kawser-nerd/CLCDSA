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
#include<unordered_set>
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
vector<int> g[MAX];
vector<PII> G[MAX];
int C[MAX];
bool can = true;

vector<int> A;
void dfs(int v, int c)
{
	if (C[v] != -1)
	{
		if (C[v] != c) can = false;
		return;
	}

	C[v] = c;
	A.push_back(v);
	FOR(i, 0, SZ(G[v]))
	{
		int to = G[v][i].first;
		int type = G[v][i].second;
		int c1 = c;
		if (type == 0) c1 = (c1 + 1) % 3;
		if (type == 1) c1 = (c1 + 2) % 3;
		
		dfs(to, c1);
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(MP(b, 0));
		G[b].push_back(MP(a, 1));
	}

	LL ans = 0;
	FILL(C, -1);
	FOR(k, 0, n)
	{
		if (C[k] == -1)
		{
			A.clear();
			can = true;
			dfs(k, 0);

			if (!can)
			{
				ans += SZ(A) * (LL)SZ(A);
				continue;
			}

			LL CNT[3] = { 0 };
			FOR(i, 0, SZ(A))
			{
				int v = A[i];
				CNT[C[v]]++;
			}

			if (CNT[0] == 0 || CNT[1] == 0 || CNT[2] == 0)
			{
				LL cnt = 0;
				FOR(i, 0, SZ(A))
				{
					int v = A[i];
					cnt += SZ(G[v]);
				}

				cnt /= 2;
				ans += cnt;
				continue;
			}

			FOR(i, 0, 3)
			{
				ans += CNT[i] * CNT[(i + 1) % 3];
			}
		}
	}

	cout << ans << endl;
}