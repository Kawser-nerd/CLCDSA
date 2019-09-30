#define _CRT_SECURE_NO_WARNINGS
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
#define CL(a,x) memset(x, a, sizeof(x))
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
int dx[]={-1,0,1,0};
int dy[]={1,0,-1,0};
int i, j, k, m, n, l, ans;
char ss[1000002];

int a[100005][4], last[100005][4], dp[100005][5][5];

int main() {
//	freopen("d.in", "r", stdin);

	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);

//	freopen("D-large.in", "r", stdin);
//	freopen("D-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        cerr << tt << endl;
		printf("Case #%d: ", tt);

		cin >> n >> m >> k;
		F0(i,n)
		{
			F1(j,m) cin >> a[i][j];
		}
		F0(i,n) F1(j,m)
		{
			last[i][j] = i;
			if (i > 0)
			{
				F1(k,m) if (a[i-1][k] == a[i][j])
					last[i][j] = last[i-1][k];
			}
		}
		CL(-1, dp);

		F0(i,n) F1(j,m)
		{
			dp[i][j][0] = 1;
			if (last[i][j] != i)
			{
				F1(k,m) if (a[i-1][k] == a[i][j]) break;
				if (k > m) throw 9;
				for (int l = 0; l < 5; l++)
					if (dp[i-1][k][l] != -1)
					{
						dp[i][j][l] = dp[i-1][k][l] + 1;
					}
			}
			if (last[i][j] > 0)
			{
				int l = last[i][j] - 1;
				F1(k,4) 
				{
					// no more
					if (dp[l][k][0] != -1)
						dp[i][j][k] = max(dp[i][j][k], dp[l][k][0] + i-l);
					// more in past
					if (last[l][k] > 0)
					{
						int l2 = last[l][k] - 1;
						for (int k2 = 1; k2 <= 4; k2++)
							if (a[l2][k2] == a[i][j])
							{
								if (dp[l][k][k2] != -1)
									dp[i][j][k] = max(dp[i][j][k], dp[l][k][k2] + i-l);
							}
					}
				}
					
			}
		}

		int best = 0, bl = -1, br = -1;

		F0(i,n) F1(j,m) F0(k,5)
			if (dp[i][j][k] > best)
			{
				best = dp[i][j][k];
				bl = i-best + 1;
				br = i;
			}
		
		cout << bl << " " << br << endl;
	}
    cerr << "Press any key to continue" << endl;
    while (1);

	return 0;
}
