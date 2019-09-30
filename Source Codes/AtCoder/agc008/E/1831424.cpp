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
typedef pair<long long, long long> PLL;


const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1000 * 100 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

int A[MAX];
int DEG[MAX];
int D[MAX];
int FOOT[MAX];
int C[MAX];
int U[MAX];
LL dp[MAX];
queue<int> q;

//#define DEBUG
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> A[i];
		A[i]--;
	}

	FOR(i, 0, n)
	{
		DEG[A[i]]++;
		D[A[i]]++;
	}

	FOR(i, 0, n)
	{
		if (D[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		
		int to = A[v];
		D[to]--;
		FOOT[to] = FOOT[v] + 1;
		if (D[to] == 0)
		{
			q.push(to);
		}
	}

	FOR(i, 0, n)
	{
		if (DEG[i] > 2 || (DEG[i] > 1 && D[i] == 0))
		{
			cout << 0 << endl;
			return 0;
		}
	}

#ifdef DEBUG
	cout << "D=";
	FOR(i, 0, n)
	{
		cout << D[i] << " ";
	}
	cout << endl;
#endif
	LL ans = 1;
	FOR(i, 0, n)
	{
		if (D[i] == 1 && !U[i])
		{
			bool isLoop = true;
			int v = i;
			int cnt = 0;
			while (!U[v])
			{
				U[v] = 1;
				cnt++;
				if (FOOT[v]) isLoop = false;
				v = A[v];
			}

			if (isLoop)
			{
				C[cnt]++;
				continue;
			}

			v = i;
			while (FOOT[v] == 0)
			{
				v = A[v];
			}

			LL tmp = 1;
			int l = 0;
			while (1)
			{
				l++;
				v = A[v];
				if (U[v] == 2) break;
				U[v] = 2;
				if (FOOT[v])
				{
					if (FOOT[v] < l) tmp = (tmp * 2) % MOD;
					if (FOOT[v] > l) tmp *= 0;
					l = 0;
				}
			}

			ans = (ans * tmp) % MOD;
		}
	}

#ifdef DEBUG
	cout << "loops" << endl;
	FOR(len, 1, n + 1)
	{
		cout << len << " " << C[len] << endl;
	}
#endif // DEBUG

	
	FOR(len, 1, n + 1)
	{
		if (C[len] == 0) continue;

		LL dob = (len % 2 == 0 || len == 1) ? 1 : 2;
		int cnt = C[len];
		dp[0] = 1;
		dp[1] = dob;

		FOR(i, 2, cnt + 1)
		{
			LL tmp = ((i - 1) * dp[i - 2]) % MOD;
			dp[i] = dp[i - 1] * dob + tmp * len;
			dp[i] %= MOD;
		}
#ifdef DEBUG
		cout << "len=" << len << endl;
		FOR(i, 0, cnt + 1)
		{
			cout << dp[i] << " ";
		}
		cout << endl;
#endif
		ans = (ans * dp[cnt]) % MOD;
	}

	cout << ans << endl;
}