#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
char w[200000];

set<string> all;

int go () {
	string s = "";
	for (int i = 1; ; i++)
		if (w[i] == '/' || w[i] == 0) {
			s += '/';
			all.insert (s);
			if (w[i] == 0) break;
		} else s += w[i];
}

int main() {
	int tt;
	scanf ("%d\n", &tt);
	for (int it = 0; it < tt; it++) {
		int n, m;
		scanf ("%d%d\n", &n, &m);
		all.clear ();
		for (int i = 0; i < n; i++) {
			gets (w);
			go ();
		}
		int cur = all.size ();
		for (int i = 0; i < m; i++) {
			gets (w);
			go ();
		}
		printf ("Case #%d: %d\n", it + 1, all.size () - cur);
	}
	
	return 0;
}