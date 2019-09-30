#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


#define forn(i,n)  for (int i=0; i<int(n); ++i)
typedef long long int64;
const int INF = (int) 1E9;


const int MOD = 10007;

int n, m;
char a[20][20];
short d[4][4][456976];
int pw[20];

int get_d (int x, int y, int msk, int v[]) {
	if (x == n)  return 1;
	if (y == m)  return get_d (x+1, 0, msk, v);
	short & my = d[x][y][msk];
	if (my != -1)  return my;
	my = 0;

	int old = v[y];

	for (int cur=0; cur<26; ++cur) {
		bool ok = true;
		if (x)  ok &= cur >= old;
		if (y)  ok &= cur >= v[y-1];
		if (a[x][y] != '.')  ok &= cur == (a[x][y] - 'a');
		if (ok) {
			v[y] = cur;
			my += get_d (x, y+1, msk + pw[y] * (-old + cur), v);
			if (my > MOD)
				my -= MOD;
		}
	}

	v[y] = old;

	return my;
}

int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	
	forn(i,20)
		pw[i] = i ? (pw[i-1] * 26) : 1;

	int tests;
	cin >> tests;
	forn(test,tests) {
		
		cin >> n >> m;
		gets (a[0]);
		forn(i,n)
			gets (a[i]);

		memset (d, -1, sizeof d);
		int v[10] = { 0 };
		printf ("Case #%d: %d\n", test+1, get_d (0, 0, 0, v));

	}

}