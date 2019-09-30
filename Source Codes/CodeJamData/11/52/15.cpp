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
int x[1000], cnt[10002], v[1000];

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {

		scanf ("%d", &n);	
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		memset (cnt, 0, sizeof (cnt));
		for (int i = 0; i < n; i++) cnt[x[i]]++;
		int ans = 10001 * int (n > 0), r = 0;
		for (int i = 1; i <= 10001; i++) {
			if (cnt[i] >= r) {
				for (int j = r; j < cnt[i]; j++) v[j] = 0;
				for (int j = 0; j < cnt[i]; j++) v[j]++;
				r = cnt[i];
			} else {
				sort (v, v + r);
				for (int j = 0; j < cnt[i]; j++) v[j]++;
				for (int j = cnt[i]; j < r; j++) ans = min (ans, v[j]);
				r = cnt[i];
			}	
		}

		printf ("Case #%d: %d\n", it, ans);
	}
	return 0;
}