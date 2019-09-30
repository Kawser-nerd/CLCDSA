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
const ll inf = (ll)1e18;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

ll i, j, k, m, n, l, ans, p, path[2005], used[2005], x[2005], y[2005], a[2005], b[2005], z[2005], g[2005][2005];
ll badcost[2005], spent, best[2005], ref[2005];

bool good()
{
    int c = b[path[i]];
    for (int j = 0; j < m; j++)
        if (a[path[i]] == a[j] && j != path[i])
        {
            ref[j] = 1;
            int at = b[j];
            int cost = spent + y[j];
            for (int k = 1; k <= n; k++)
            {
                badcost[k] = min(badcost[k], g[at][k] + cost);
            }
        }
    for (int k = 1; k <= n; k++)
        best[k] = inf;
    best[c] = spent + x[path[i]];
    if (best[c] > badcost[c]) return false;

    int sg = 1;
    while (sg)
    {
        sg = 0;
        for(int j = 0; j < m; j++) if (!ref[j]) if (best[a[j]] + x[j] < best[b[j]] && best[a[j]] + x[j] <= badcost[b[j]])
        {
            best[b[j]] = best[a[j]] + x[j];
            sg = 1;
        }
    }
    return best[2] < inf;
}

int main() {
 //   freopen("x.in", "r", stdin);

//	freopen("C-small-attempt0.in", "r", stdin);
//	freopen("C-small-attempt-0.out", "w", stdout);

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
        cin >> n >> m >> p;
        F0(i,m)
        {
            cin >> a[i] >> b[i] >> x[i] >> y[i];
        }
        F1(i,n) F1(j,n) g[i][j] = inf * (i != j);
        F0(i,m) g[a[i]][b[i]] = y[i];
        F1(k,n) F1(i,n) F1(j,n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        
        F0(i,m) ref[i] = 0;
        F1(i,n) badcost[i]=inf;

        F0(i,p) 
        {
            cin >> path[i];
            path[i]--;
        }

        spent = 0;
 		printf("Case #%d: ", tt);
        for (i = 0; i < p; i++)
        {
            if (!good())
            {
                cout << path[i] + 1 << endl;
                break;
            }
            spent += x[path[i]];
        }
        if (i == p)
        {
            cout << "Looks Good To Me" << endl;
        }
	}
	
	return 0;
}
