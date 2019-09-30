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

int i, j, k, m, n, l, ans, o[10], u[10], maxArea, best[10], x[10], y[10];

ll cw(int i1, int i2, int i3)
{
    return (x[i2]-x[i1]) * (y[i3]-y[i1]) - (x[i3]-x[i1]) * (y[i2]-y[i1]);
}

bool inter(int i1, int i2, int i3, int i4)
{
 //   cout << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
    if (min(x[i1], x[i2]) > max(x[i3], x[i4])) return false;
    if (min(y[i1], y[i2]) > max(y[i3], y[i4])) return false;
    if (min(x[i3], x[i4]) > max(x[i1], x[i2])) return false;
    if (min(y[i3], y[i4]) > max(y[i1], y[i2])) return false;
    if (cw(i1, i2, i4) * cw(i1, i2, i3) > 0) return false; 
    if (cw(i3, i4, i1) * cw(i3, i4, i2) > 0) return false;
    return true;
}

void go(int at)
{
    if (at == n)
    {
        int g = 1;
        for (int j = 1; j < n-2; j++)
            if (inter(o[j], o[j+1], o[n-1], o[0])) g = 0;
        if (g)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += x[o[j]] * y[o[(j+1)%n]];
                sum -= y[o[j]] * x[o[(j+1)%n]];
            }
            sum = abs(sum);
            //cout << sum << endl;
            if (sum > maxArea)
            {
                maxArea = sum;
                F0(i,n) best[i] = o[i];
            }
        }
        return;
    }
    for (int i = 1; i < n; i++)
        if (!u[i])
        {
            o[at] = i;
            u[i] = 1;
            
            int g = 1;
            for (int j = 0; j < at-2; j++)
                if (inter(o[j], o[j+1], o[at-1], o[at])) g = 0;
            if (g) 
                go(at + 1);
            u[i] = 0;
        }
}

int main() {
 //   freopen("x.in", "r", stdin);

	freopen("B-small-attempt1.in", "r", stdin);
 	freopen("B-small-attempt1.out", "w", stdout);

//	freopen("B-large.in", "r", stdin);
//	freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
        cin >> n;
        F0(i,n) cin >> x[i] >> y[i];
        F0(i,n) u[i] = 0;
        maxArea = 0;
  		go(1);
//        cout << maxArea << endl;

        printf("Case #%d:", tt);
        F0(i,n) cout << " " << best[i];
		printf("\n");
	}
	
	return 0;
}
