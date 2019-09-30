#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime> //clock()
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>

using namespace std;

#pragma comment(linker, "/STACK:33554432")

#ifdef __GNUC__
typedef long long int64;
#else //MS Visual Studio
typedef __int64 int64;
#endif

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define it iterator
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()

const long double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const long double PI = 2 * acos(.0);

char s[1100][1100], c[1100][1100];
int z[1100][1100];

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		int n;
		scanf("%d", &n);

		gets(s[0]);
		forn(i, n)
			gets(s[i]);

		int m;
		scanf("%d", &m);
		gets(c[0]);
		forn(i, m)
			gets(c[i]);

		memset(z, 0, sizeof(z));
		int prev = 0;
		for (int i = 1; i <= m; i++) {
			forn(j, n) {
				if (!strcmp(s[j], c[i - 1])) {
					z[i][j] = INF;
					continue;
				}

				z[i][j] = min(z[i - 1][j], 1 + prev);
			}

			prev = INF;
			forn(j, n)
				prev = min(prev, z[i][j]);
		}

		printf("Case #%d: %d\n", tt + 1, prev);
	}
	
	return 0;
}