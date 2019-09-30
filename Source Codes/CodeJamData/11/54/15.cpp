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
int m, q[40];
string s;
int x[300];

int check () {
	ll tmp = 0;
	for (int j = n - 1; j >= 0; j--) tmp = tmp * 2 + x[j];
	for (ll a = max ((ll)0, (ll)(sqrt (tmp + 0.0) - 10)); a * a <= tmp; a++)
		if (a * a == tmp)
			re 1;
	re 0;
}

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {

		cin >> s;	
		n = sz (s);
		m = 0;
		for (int i = 0; i < n; i++) 
			if (s[n - i - 1] == '?')
				q[m++] = i;
			else
				x[i] = s[n - i - 1] - '0';
		printf ("Case #%d: ", it);
		for (int i = 0; i < (1 << m); i++) {
			for (int j = 0; j < m; j++)
				x[q[j]] = (i >> j) & 1;
			if (check ()) {
				for (int i = n - 1; i >= 0; i--)
					printf ("%d", x[i]);
				printf ("\n");	
				break;
			}
		}
	}
	return 0;
}