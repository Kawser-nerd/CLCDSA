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
#define prev PREV
                         
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
string s;
int x[1000001];
int prev[1000001][10];
int res[1000001][200];
int last[10];
char h[1100000];

int stoi (string s) {
	int x = 0;
	for (int i = 0; i < sz (s); i++) x = x * 10 + s[i] - '0';
	re x;
}

int main (int argc, char **argv) {
	int NUM = stoi (string (argv[1]));
	int CNT = stoi (string (argv[2]));
	freopen (argv[3], "r", stdin);
	string output = "output." + string (argv[1]);
	freopen (output.c_str (), "w", stdout);
	int tt;
	cin >> tt;
	gets (h);
	for (int it = 1; it <= tt; it++) {
		gets (h);
		s = string (h);
		if ((it - 1) % CNT != NUM) continue;
		n = sz (s);
		for (int i = 0; i < 10; i++) last[i] = -1;
		for (int i = 0; i < n; i++) {
			x[i] = s[i] - '0';
			last[x[i]] = i;
			for (int j = 0; j < 10; j++) prev[i][j] = last[j];
		}
		int ans = 0;
		for (int k = 0; k < 200; k++) {
			for (int i = 0; i <= n; i++)
				if (k == 0)
					res[i][k] = i;
				else {
					res[i][k] = res[i][k - 1];
					if (res[i][k] == n) continue;
					for (int t = 1; t <= 9 && t <= k; t++) {
						int j = prev[res[i][k - t]][t];
						if (j >= i) res[i][k] = max (res[i][k], res[j + 1][k - t]);
					}
				}
			if (res[0][k] == n) {
				ans = k;
				break;
			}
		}	
		cout << "Case #" << it << ": " << ans << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}