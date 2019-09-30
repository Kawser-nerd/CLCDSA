#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

string s;
int t[7000][7000][2];

int go (int l, int r, int tp)
{
	if (l > r)
		return 0;
	if (t[l][r][tp] != -1)
		return t[l][r][tp];
	int add;
	if (tp == 0)
		add = 1;
	else
		add = 0;
	int res = inf;
	res = go (l+1, r, 0) + 1;
	for (int i = l+1; i <= r; i ++)
		if (s[i] == s[l])
		{
			int tmp = go (l+1, i-1, 0);
			if (tmp < res || 1)
			{
				tmp += go (i, r, 1);
				if (tmp < res)
					res = tmp;
			}
		}
	return t[l][r][tp] = res + add;
}

void goggogogog ()
{
	cin >> s;
	int len = s.length();
	int p = 0;
	while (p+1 < I s.length())
		if (s[p] == s[p+1])
			s.erase (p, 1);
		else
			p ++;
	seta (t, 255);
	cout << go (0, s.length() - 1, 0) + len;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
	int tt;            
	scanf ("%d", &tt);
	forn (ii, tt)
	{
		printf ("Case #%d: ", ii+1);
		goggogogog ();
		printf ("\n");
	}
	return 0;
}
