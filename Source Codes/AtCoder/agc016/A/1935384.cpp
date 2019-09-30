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

const int MAX = 100 * 1000 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;
bool check(const string& s, char ch, int k)
{
	FOR(i, 0, n - k - 1)
	{
		if (s[i] != ch)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	string t = s;
	n = SZ(s);
	int ans = INF;
	if (check(s, s[0], -1))
	{
		ans = 0;
	}

	FOR(ch, 0, 26)
	{
		s = t;
		int steps = 0;
		FOR(k, 0, n)
		{
			FOR(i, 0, n - k - 1)
			{
				if (s[i] == ch + 'a' || s[i + 1] == ch + 'a')
				{
					s[i] = ch + 'a';
				}
			}

			if (check(s, ch + 'a', k))
			{
				ans = min(k + 1, ans);
				break;
			}
		}
	}

	cout << ans << endl;
}