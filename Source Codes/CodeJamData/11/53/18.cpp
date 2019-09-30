#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const string tp = "|/-\\|/-\\";
const int MOD = 1000003;

pair<int, int> g[110][110][2];
string s[110];
bitset<11000> a[11000];

void solve() {
	int n, m;

	cin >> n >> m;
	forn(i, n)
		cin >> s[i];
/*
	n = m = 100;
	forn(i, n) {
		s[i] = "";
		forn(j, m)
			s[i] += tp[rand() % 4];
	}
*/
	forn(i, n)
		forn(j, m) {
			int sz = 0;
			forn(dir, 8)
				if (tp[dir] == s[i][j])
					g[i][j][sz++] = mp((i + dx[dir] + n) % n, (j + dy[dir] + m) % m);

			if (sz != 2)
				throw;
		}

	int nm = n * m;
	forn(i, nm)
		a[i].reset();

	forn(i, n)
		forn(j, m) {
			a[i * m + j].flip(nm);
			{
				int ti = g[i][j][0].fs;
				int tj = g[i][j][0].sc;

				a[ti * m + tj].flip(i * m + j);
			}
			{
				int ti = g[i][j][1].fs;
				int tj = g[i][j][1].sc;

				a[ti * m + tj].flip(i * m + j);
				a[ti * m + tj].flip(nm);
			}
		}

	int row = 0;
	forn(col, nm) {
		if (a[row][col] == 0) {
			int sel = -1;
			fore(j, row + 1, nm)
				if (a[j][col]) {
					sel = j;
					break;
				}

			if (sel == -1)
				continue;

			swap(a[row], a[sel]);
		}

		fore(j, row + 1, nm)
			if (a[j][col])
				a[j] ^= a[row];

		row++;
	}

	fore(i, row, nm)
		if (a[i][nm]) {
			puts("0");
			return;
		}

	int res = 1;
	forn(i, nm - row)
		res = res * 2 % MOD;

	cout << res << endl;
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	
	
	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		cerr << ii << ' ' << clock() << endl;
		printf("Case #%d: ", ii + 1);

		solve();
	}

	cerr << clock() << endl;
	
	return 0;
}