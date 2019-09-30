#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
//#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))

#define forn(i, x) for (int i = 0; i < int(x); i++)
#define fors(i, x) forn(i, sz(x))

template<typename T> T sqr(T x) { return x * x;            }
template<typename T> T abs(T x) { return (x > 0) ? x : -x; }

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nt;
	cin >> nt;
	forn(it, nt)
	{		
		ll n, a, b, c, d, x0, y0, m;
		cin >> n >> a >> b >> c >> d >> x0 >> y0 >> m;
		ll cnt[3][3];
		memset(cnt, 0, sizeof(cnt));
		ll cx = x0, cy = y0;
		cnt[cx % 3][cy % 3]++;
		forn(i, n - 1)
		{
			cx = (a * cx + b) % m;
			cy = (c * cy + d) % m;
			cnt[cx % 3][cy % 3]++;
		}
		ll ans = 0;
		forn(i1, 3) forn(j1, 3)
		forn(i2, 3) forn(j2, 3)
		forn(i3, 3) forn(j3, 3)
		{
			if ((i1 + i2 + i3) % 3) continue;
			if ((j1 + j2 + j3) % 3) continue;
			bool bad = false;
			ll cur = 1;
			if (!cnt[i1][j1]) bad = true;
			cur *= cnt[i1][j1];
			cnt[i1][j1]--;
			if (!cnt[i2][j2]) bad = true;
			cur *= cnt[i2][j2];
			cnt[i2][j2]--;
			if (!cnt[i3][j3]) bad = true;
			cur *= cnt[i3][j3];
			cnt[i3][j3]--;
			cnt[i1][j1]++;
			cnt[i2][j2]++;
			cnt[i3][j3]++;
			if (bad) continue;
			ans += cur;
		}
		cout << "Case #" << (it + 1) << ": " << (ans / 6) << "\n";
	}
	return 0;
}
