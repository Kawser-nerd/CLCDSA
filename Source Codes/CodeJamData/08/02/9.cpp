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

int ba[2000][2];

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		int dt, na, nb;
		scanf("%d%d%d", &dt, &na, &nb);

		memset(ba, 0, sizeof(ba));
		forn(i, na) {
			int a, b, c, d;
			scanf("%d:%d %d:%d", &a, &b, &c, &d);
			ba[a * 60 + b][0]--;
			ba[c * 60 + d + dt][1]++;
		}
		forn(i, nb) {
			int a, b, c, d;
			scanf("%d:%d %d:%d", &a, &b, &c, &d);
			ba[a * 60 + b][1]--;
			ba[c * 60 + d + dt][0]++;
		}

		vector<int> ans(2), bal(2);
		forn(i, 2000)
			forn(j, 2) {
				bal[j] += ba[i][j];
				if (bal[j] < 0) {
					ans[j] += -bal[j];
					bal[j] = 0;
				}
			}

		printf("Case #%d: %d %d\n", tt + 1, ans[0], ans[1]);
	}
	
	return 0;
}