#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

struct building
{
	int X0, X1, Y0, Y1;
}B[1010];

int n;
int W, H;
int dist[1010][1010];

int calc(int L, int R, int l, int r)
{
	int ret = 100000001;
	if(L <= l && l <= R) return 0;
	if(L <= r && r <= R) return 0;
	if(l <= L && L <= r) return 0;
	if(l <= R && R <= r) return 0;
	ret = min(ret, abs(L - l));
	ret = min(ret, abs(L - r));
	ret = min(ret, abs(R - l));
	ret = min(ret, abs(R - r));
	return max(0, ret-1);
}

int d[1010];
int now, z, q[100000001];

void solve()
{
	cin >> W >> H >> n;
	n += 2;
	B[1].X0 = -1; B[1].Y0 = 0; B[1].X1 = -1; B[1].Y1 = H-1;
	B[2].X0 = W; B[2].Y0 = 0; B[2].X1 = W; B[2].Y1 = H-1;
	for(int i = 3; i <= n; i++)
		cin >> B[i].X0 >> B[i].Y0 >> B[i].X1 >> B[i].Y1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			dist[i][j] = max(calc(B[i].X0, B[i].X1, B[j].X0, B[j].X1), calc(B[i].Y0, B[i].Y1, B[j].Y0, B[j].Y1));
		}
	now = z = 0;
	memset(d, 0xe, sizeof(d));
	d[1] = 0;
	q[now] = 1;
	while(now <= z)
	{
		int x = q[now];
		for(int i = 1; i <= n; i++)
			if(d[i] > d[x] + dist[i][x])
			{
				d[i] = d[x] + dist[i][x];
				++ z;
				q[z] = i;
			}
		++ now;
	}
	cout << d[2] << endl;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
