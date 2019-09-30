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

char ch[1000000];
int n, m;
set <string> S;

int insert (string s)
{
	int res = 0;
	s += "/";
	forn (i, s.length())
		if (i > 0)
			if (s[i] == '/')
			{
				if (!S.count (s.substr (0, i)))
					res ++;
				S.insert (s.substr (0, i));
			}
	return res;	
}

void calc ()
{
	scanf ("%d%d", &n, &m);
	gets (ch);
	S.clear ();
	int res = 0;
	forn (i, n)
	{
		gets (ch);
		string s = ch;
		res += insert (s);
	}
	res = 0;
        forn (i, m)
        {
        	gets (ch);
        	string s = ch;
        	res += insert (s);
        }
        printf ("%d\n", res);
}

int main ()
{
	int tt;
	scanf ("%d", &tt);
	gets (ch);
	forn (ii, tt)
	{
	        printf ("Case #%d: ", ii+1);
		calc ();
	}
	return 0;
}
