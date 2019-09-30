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

const int MAX = 200000 + 47;

int A[MAX];
int B[MAX];
int n;
int sz;
vector<PII> V;

bool ok(int a)
{
	FOR(i, 0, sz)
	{
		B[i] = A[i] <= a;
	}

	V.clear();

	int cnt = 1;
	FOR(i, 1, sz + 1)
	{
		if (B[i] != B[i - 1] || i == sz)
		{
			if (cnt >= 2)
			{
				int y;
				if (i - cnt <= n - 1 && n - 1 <= i - 1)
				{
					y = 0;
				}
				else
				{
					y = i - cnt > n - 1 ? i - cnt - n + 1 : n - i;
				}

				V.push_back(MP(y, B[i - 1]));
			}

			cnt = 1;
			continue;
		}

		cnt++;
	}

	if (SZ(V) == 0) return B[0];

	PII minn = MP(INF, INF);
	FOR(i, 0, SZ(V))
	{
		minn = min(minn, V[i]);
	}

	
	return minn.second;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	sz = 2 * n - 1;
	FOR(i, 0, sz)
	{
		cin >> A[i];
	}

	int l = 1, r = 2 * n - 2;
	while (r - l > 1)
	{
		int c = (r + l) / 2;
		if (ok(c))
		{
			r = c;
		}
		else
		{
			l = c;
		}
	}

	cout << r << "\n";
}