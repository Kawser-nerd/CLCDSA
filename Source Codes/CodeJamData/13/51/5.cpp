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
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
double ans;
ll B, x[37], x2[37], spent, bets, B2;

int main() {
//    freopen("x.in", "r", stdin);

//	freopen("A-small-attempt2.in", "r", stdin);
//	freopen("A-small-attempt2.out", "w", stdout);

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
        cin >> B >> n;
        F0(i,37) x[i] = 0;
        F0(i,n) cin >> x[i];
        n = 37;
        sort(x, x+n);

        ans = 0.0;
        for (i = 1; i < n; i++)
        {
            spent = 0;
            bets = 0;
            F0(j,i)
            {
                x2[j] = x[i-1];
                spent += x[i-1] - x[j];
                bets += x[i-1] - x[j];
            }
            for (j = i; j < n; j++)
            {
                if (x[j] == x[i-1])
                {
                    spent++;
                    x2[j] = x[i-1]+1;
                }
                else x2[j] = x[j];
            }
            if (spent > B) continue;
            B2 = B - spent;

            while (1)
            {
                j = i;
                while (j < n && x2[j] == x2[i]) j++;
                    
                ll delta = x2[i]-x2[i-1]-1;
                ll y = B2 / i;
                y = min(y, delta);
                if (y > 0)
                {
                    F0(k,i) x2[k] += y;
                    spent += y * i;
                    bets += y * i;
                    B2 -= y * i;
                }
                else if (j < n-1)
                {
                    delta = x2[j]-x2[j-1];
                    ll y = B2 / j;
                    y = min(y, delta);
                    if (y == 0) break;
                    F0(k,j) x2[k] += y;
                    spent += y * j;
                    bets += y * i;
                    B2 -= y * j;
                }
                else break;
           }
           ans = max(ans, 1.0*bets*(n-1) / i - spent);
        }

  		printf("Case #%d: ", tt);
        printf("%.10lf\n", ans);
	}
	
	return 0;
}
