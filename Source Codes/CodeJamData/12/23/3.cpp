#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int CNT = 7000000;

int qq;
int n;
i64 a[1024];
int b[CNT + 1][512 / 32];
i64 s[CNT + 1];
int u[512 / 32];
int ind[CNT + 1];

bool cmp(int p1, int p2)
{
	return s[p1] < s[p2];
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	srand(4567247);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d:\n", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);

		scanf("%d", &n);
		forn(i, n)
		{
			scanf("%I64d", &a[i]);
		}
		forn(i, CNT)
		{
			s[i] = 0;
			clr(u);
			int z = 60 + rand() % 10;
			forn(tt, z)
			{
				int x;
				do
				{
					x = rand() % n;
				}
				while (u[x >> 5] & (1 << x));
				u[x >> 5] |= 1 << x;
				s[i] += a[x];
			}
			memcpy(b[i], u, sizeof(u));
			ind[i] = i;
		}
		sort(ind, ind + CNT, cmp);
		forn(i, CNT - 1)
		{
			if (s[ind[i]] == s[ind[i + 1]])
			{
				bool zz = false;
				int nn = (n + 31) / 32;
				forn(j, nn)
				{
					zz = zz || b[ind[i]][j] != b[ind[i + 1]][j];
				}
				if (zz)
				{
					bool f = true;
					forn(j, n)
					{
						if (b[ind[i]][j >> 5] & (1 << j))
						{
							if (!f) putchar(' ');
							f = false;
							printf("%I64d", a[j]);
						}
					}
					puts("");
					f = true;
					forn(j, n)
					{
						if (b[ind[i + 1]][j >> 5] & (1 << j))
						{
							if (!f) putchar(' ');
							f = false;
							printf("%I64d", a[j]);
						}
					}
					puts("");
					break;
				}
			}
		}
		
		fflush(stdout);
	}

	return 0;
}
