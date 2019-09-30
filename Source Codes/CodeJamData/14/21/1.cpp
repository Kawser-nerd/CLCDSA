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
string s[100];
int p[100];
int l[100];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			p[i] = 0;
			l[i] = sz (s[i]);
		}	
		int ok = 1, ans = 0;
		while (p[0] < l[0]) {
			char c = s[0][p[0]];
			vi u;
			for (int i = 0; i < n; i++) {
				int j = 0;
				while (p[i] < l[i] && s[i][p[i]] == c) {
					p[i]++;
					j++;
				}
				u.pb (j);
			}
			sort (all (u));
			if (u[0] == 0) {
				ok = 0;
				break;
			} else {
				int mid = u[n / 2];
				for (int i = 0; i < n; i++) ans += abs (u[i] - mid);
			}
		}
		for (int i = 0; i < n; i++)
			if (p[i] < l[i])
				ok = 0;
		cout << "Case #" << it << ": ";
		if (!ok) cout << "Fegla Won"; else cout << ans;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}