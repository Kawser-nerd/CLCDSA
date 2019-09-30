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

const int mod = 10007;

int n;
int m;
int x[102];
int res[102][102][102];
int bad[102][102];
int f[10002];

int main () {
	f[0] = 1;
	for (int i = 1; i <= 10000; i++) f[i] = (f[i - 1] * i) % mod;
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d", &n);
		memset (res, 0, sizeof (res));
		for (int i = 1; i <= n; i++) scanf ("%d", &x[i]);
		x[0] = 10001;
		x[n + 1] = 0;
		for (int i = 0; i <= n; i++)   
			for (int j = i + 1; j <= n + 1; j++) {
				int tmp = 0;
				for (int k = i + 1; k < j; k++)
					if (x[k] > x[i] || x[k] < x[j])
						tmp++;
				bad[i][j] = tmp;
//				printf ("%d %d = %d\n", i, j, tmp);
			}
        res[0][0][0] = 1;
        for (int i = 0; i <= n; i++)
        	for (int j = 0; j <= n; j++)
        		for (int k = 0; k <= n; k++)
        			for (int t = i + 1; t <= n + 1; t++)
        				if (x[t] <= x[i])
        					(res[t][j + (t - i - 1)][k + bad[i][t]] += res[i][j][k]) %= mod;
		
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++) {
				int tmp = res[n + 1][i][j];
//				printf ("%d %d %d\n", i, j, tmp);
				if (i > 0) {
					tmp = (tmp * j) % mod;
					tmp = (tmp * f[i - 1]) % mod;
				}	
				ans = (ans + tmp) % mod;
			}
		
		cout << "Case #" << it << ": " << ans;
        
		cout << endl;

		cerr << it << " / " << tt << " " << clock () << endl;
	}
	return 0;
}