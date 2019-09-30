#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define NMAX 105
#define LMAX 1000005
#define ALP 26

const ll mod = 1000003;

char s[LMAX];
int cnt[ALP];

ll fact[LMAX];
ll rev[LMAX];

ll gcd(ll a, ll b, ll &x, ll &y)
{
	//ax + by = gcd(a, b)
	if (b == 0)
	{
		x = 1; y = 0; return a;
	}
	else
	{
		ll x0, y0;
		ll d = gcd(b, a % b, x0, y0);
		x = y0; y = x0 - (a / b) * y0; return d;
	}
}

ll get_rev(ll a)
{
	ll x, y;
	ll d = gcd(a, mod, x, y);
	assert(d == 1);

	return ((x % mod) + mod) % mod;
}

ll d[ALP + 1][NMAX], c[ALP + 1][NMAX];
ll a[NMAX];

ll cnk(ll n, ll k)
{
	if (n >= 0 && k >= 0 && k <= n) return (((fact[n] * rev[fact[k]]) % mod) * rev[fact[n - k]]) % mod;
	return 0;
}
void solve(int test)
{
    printf("Case #%d: ", test);

    gets(s);
    int len = strlen(s);

    int m = 1;

    forn(i, len - 1)
    {
    	if (s[i] != s[i + 1]) m++;	
    }

	memset(cnt, 0, sizeof(cnt));
    forn(i, len)
    {
    	cnt[s[i] - 'a']++;
    }

//	forn(i, ALP) cerr << cnt[i] << " ";

	forn(i, ALP)
	{
		for1(j, m)
		{
			if (j > cnt[i]) continue;
			c[i][j] = (((fact[cnt[i] - 1] * rev[fact[j - 1]]) % mod) * rev[fact[cnt[i] - j]]) % mod;
		}
	}

	memset(d, 0, sizeof(d));
	memset(a, 0, sizeof(a));

	d[0][0] = 1;

	forn(i, ALP)
	{
		forn(j, m + 1)
		{
			if (d[i][j] == 0) continue;

			if (cnt[i] == 0) 
			{
				d[i + 1][j] = (d[i + 1][j] + d[i][j]) % mod;
				continue;
			}

			for1(k, min(m, cnt[i]))
			{
				if (j + k > m) continue;
				d[i + 1][j + k] += (((d[i][j] * c[i][k]) % mod) * rev[fact[k]]) % mod;
				d[i + 1][j + k] %= mod;
			}
		}

	}

	for1(i, m)
	{
	 	a[i] = (d[ALP][i] * fact[i]) % mod;
//	 	cerr << a[i] << " ";
	}
//	cerr << endl;

	for1(i, m)
	{
		for1(j, i - 1)
		{
			a[i] -= (a[j] * cnk(len - j, i - j)) % mod;
			a[i] = (a[i] + mod) % mod;			
		}
//		cerr << a[i] << " ";
	}

//	cerr << endl;
	cout << a[m] << endl;
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    fact[0] = 1;
    for1(i, LMAX - 1)
    {
    	fact[i] = (i * fact[i - 1]) % mod;
    }

    for1(i, mod - 1) 
    {
    	rev[i] = get_rev(i);
    	assert(rev[i] > 0);
    }

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);

    return 0;
}