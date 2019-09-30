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
int was[1 << 20];
double res[1 << 20];
int ct;
string s;

double go (int mask) {
	if (mask == 0) re 0;
	if (was[mask] == ct) re res[mask];
	was[mask] = ct;
	for (int i = 0; i < n; i++)
		if ((mask >> i) & 1) {
			int x = i, y = n;
			double cur = 0;
			for (int j = 0; j < n; j++) {
				if ((mask >> ((i + j) % n)) & 1) {
					x = (i + j) % n;
					y = n;
				} else y--;
				cur += go (mask - (1 << x)) + y;
			}
			re res[mask] = cur / n;
			break;
		}
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		ct++;
		cin >> s;
		reverse (all (s));
		n = sz (s);
		int mask = 0;
		for (int i = 0; i < n; i++) mask += int (s[i] == '.') << i;
		
		cout << "Case #" << it << ": ";

		printf ("%.10f", go (mask));

		cout << endl;

		cerr << it << " / " << tt << " " << clock () << endl;
	}
	return 0;
}