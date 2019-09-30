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

int n, b, res;
vector <string> q;
vector <int> a;

string tostring (int x)
{
	string res = "";
	while (x > 0)
	{
		res += char('0' + x % b);
		x /= b;
	}
	return res;
}

void check ()
{
	res ++;
}

void go (int n)
{
	if (n == 0)
	{
		check ();
		return;
	}
	if (I a.size() >= b)
		return;
	for (int i = 1; i <= n; i ++)
		if (a.empty() || i < a.back())
		{
			string tmp = tostring (i);
			q.pb (tmp);
			bool ok = 1;
			forn (j, q[last(q)].length())
				forn (k, q.size())
					if (last(q) != k && q[k].length() >= q[last(q)].length() && q[last(q)][j] == q[k][j])
						ok = 0;
			a.pb (i);
			if (ok)
				go (n - i);
			q.pop_back();
			a.pop_back();	
		}
}

void calc ()
{
	cin >> n >> b;
	q.clear ();
	a.clear ();
	res = 0;
	go (n);
	cout << res << endl;
}

int main ()
{
	int tt;
	scanf ("%d", &tt);
	forn (ii, tt)
	{
		printf ("Case #%d: ", ii+1);
		calc ();
	}
	return 0;
}
