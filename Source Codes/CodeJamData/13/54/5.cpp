#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, mask;
double d[1<<20], ans;

int main() {

//	freopen("x.in", "r", stdin);

	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-attempt1.out", "w", stdout);

//	freopen("X-large.in", "r", stdin);
//	freopen("X-large.out", "w", stdout);

	int tt, tn; cin >> tn;

    string s;
	F1(tt,tn) {
        cin >> s;
        mask = 0;
        n = SZ(s);
        F0(i,n) mask = 2 * mask + (s[i] == '.');

        d[0] = 0.0;
        for (i = 1; i <= mask; i++)
        {
            double t = 0.0;
            for (j = 0; j < n; j++)
            {
                int g = n;
                k = j;
                while (!(i&(1<<k)))
                {
                    k = (k+n-1) % n;
                    g--;
                }
                t += d[i^(1<<k)] + g;
            }
            d[i] = t / n;
        }

		printf("Case #%d: ", tt);
        printf("%.10lf\n", d[mask]);
	}
	
	return 0;
}
