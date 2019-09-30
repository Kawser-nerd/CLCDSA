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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n;
int a[100][100];

void swap1 (int i, int j)
{
	forn (k, n)
		swap (a[i][k], a[j][k]);
}

bool ok (int i, int j)
{
	for (int k = j+1; k < n; k ++)
		if (a[i][k])
			return 0;
	return 1;
}

int main ()
{
	int tt;
	scanf ("%d", &tt);
	forn (ii, tt)
	{
		printf ("Case #%d: ", ii+1);
		scanf ("%d", &n);
		forn (i, n)
			forn (j, n)
			{
				char ch;
				scanf (" %c", &ch);
				a[i][j] = ch - '0';
			}
		int res = 0;
		forn (i, n)
		{
			int p = i;
			while (not ok (p, i))
				p ++;
			res += p - i;
			for (int k = p; k > i; k --)
				swap1 (k, k-1);
		}
		printf ("%d\n", res);
	}
	return 0;
}
