#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;

vi v[1000];
string s;
int c1[34], c2[34];
int g[34][34];
int was[34];

int get (char c) {
	if (c == 'o') re 0;
	if (c == 'i') re 1;
	if (c == 'e') re 2;
	if (c == 'a') re 3;
	if (c == 's') re 4;
	if (c == 't') re 5;
	if (c == 'b') re 6;
	if (c == 'g') re 7;
	re -1;
}

int go (int x) {
	was[x] = 1;
	for (int i = 0; i < 34; i++)
		if ((g[x][i] || g[i][x]) && !was[i])
			go (i);
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

	        cin >> n >> s;
	        m = sz (s);
	        for (int i = 0; i < m; i++) {
	        	v[i].clear ();
	        	v[i].pb (s[i] - 'a');
	        	if (get (s[i]) != -1) v[i].pb (get (s[i]) + 26);
	        }
	        memset (c1, 0, sizeof (c1));
	        memset (c2, 0, sizeof (c2));
	        memset (g, 0, sizeof (g));

	        for (int i = 0; i + 1 < m; i++)
	        	for (int a = 0; a < sz (v[i]); a++)
	        		for (int b = 0; b < sz (v[i + 1]); b++) {
	        			g[v[i][a]][v[i + 1][b]] = 1;
//	        			c1[v[i][a]]++;
//	        			c2[v[i + 1][b]]++;
	        		}	
		for (int i = 0; i < 34; i++)
			for (int j = 0; j < 34; j++)
				if (g[i][j]) {
					c1[i]++;
					c2[j]++;
				}
		int ok = 0, s1 = 0, s2 = 0, ans = 0, cnt = 0;
		memset (was, 0, sizeof (was));
		for (int i = 0; i < 34; i++) {
			ans += max (c1[i], c2[i]);
			s1 += max (0, c1[i] - c2[i]);
			s2 += max (0, c2[i] - c1[i]);
			if (c1[i] != c2[i] && !was[i]) {
				go (i);
				cnt = 1;
				ok = 1;
			}	
		}
		if (s1 != s2) cerr << "bad" << endl;

		for (int i = 0; i < 34; i++)
			if (!was[i] && c1[i] + c2[i] > 0) {
				cnt++;
				go (i);
			}
		if (cnt > 1) {
			ans += cnt - 1;
			ok = 1;
		}
		cout << "Case #" << it << ": " << ans + 1 - ok;

		cout << endl;
	}
	return 0;
}