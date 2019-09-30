#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <memory.h>
#include<iomanip>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 2 * 1000 + 47;

string a, b;
int A[MAX];
int B[MAX];
vector<PII> P;
int L[MAX];
int R[MAX];
int n;

void ADD(int& key, int val)
{
	key += val;
	if (key < 0) key += n;
	if (key >= n) key -= n;
}

int solve(vector<PII>& P, int sh)
{
	sort(ALL(P));
	int ans = INF;
	int mx = 0;
	RFOR(i, SZ(P), 0)
	{
		int val = P[i].first + 2 * mx + abs(P[i].first - sh);
		ans = min(ans, val);
		mx = max(mx, P[i].second);
	}

	ans = min(ans, mx * 2 + sh);
	// cout << "sh=" << sh << endl;
	// FOR(i,0, SZ(P))
	// {
	//     cout << P[i].first << " " << P[i].second << endl;
	// }
	// cout<< "ans=" << ans << endl;
	if (ans == INF) ans = 0;
	return ans;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
	n = SZ(a);
	int cntA = 0, cntB = 0;
	FOR(i, 0, n)
	{
		A[i] = a[i] - '0';
		B[i] = b[i] - '0';

		cntA += A[i];
		cntB += B[i];
	}

	if (cntB == 0 && cntA)
	{
		cout << -1 << endl;
		return 0;
	}

	FOR(i, 0, n)
	{
		FOR(d, 0, n)
		{
			int x = 0;
			ADD(x, i - d);
			if (B[x] == 1)
			{
				L[i] = d;
				break;
			}
		}

		FOR(d, 0, n)
		{
			int x = 0;
			ADD(x, i + d);
			if (B[x] == 1)
			{
				R[i] = d;
				break;
			}
		}
	}

	// FOR(i,0,n)
	// {
	//     cout << L[i] << " " << R[i] << endl;
	// }
	int ans = INF;
	FOR(i, 0, n)
	{
		P.clear();
		int cnt = 0;
		FOR(j, 0, n)
		{
			int x = 0;
			ADD(x, j - i);

			cnt += B[x] != A[j];
			if (B[x] == 0 && A[j] == 1)
			{
				P.PB(MP(L[j], R[j]));
			}
		}

		ans = min(ans, solve(P, i) + cnt);
		FOR(j, 0, SZ(P))
		{
			swap(P[j].first, P[j].second);
		}

		ans = min(ans, solve(P, n - i) + cnt);
	}

	cout << ans << endl;
}