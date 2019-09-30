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

int A[MAX];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n) cin >> A[i];

	int t = 0;
	int ans = 0;
	FOR(i, 1, n)
	{
		if (t == 0)
		{
			if (A[i] == A[i - 1]) continue;
			if (A[i] > A[i - 1])
			{
				t = 1;
				continue;
			}

			t = -1;
			continue;
		}

		if (t == -1 && A[i] > A[i - 1])
		{
			ans++;
			t = 0;
			continue;
		}

		if (t == 1 && A[i] < A[i - 1])
		{
			ans++;
			t = 0;
		}
	}

	ans++;
	cout << ans << endl;
}