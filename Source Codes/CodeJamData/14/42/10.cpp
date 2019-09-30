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

struct data
{
	int x, index;
	int back, front;
	bool operator <(data that)const
	{
		return x < that.x;
	}
}D[1001];

int n;
int F[1001][1001];

int f(int a, int b)
{
	if(a + b == n) return 0;
	int &ret = F[a][b];
	if(ret != -1) return ret;
	ret = 10000000;
	int kth = a + b + 1;
	ret = min(ret, f(a+1, b) + D[kth].front);
	ret = min(ret, f(a, b+1) + D[kth].back);

	return ret;
}

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> D[i].x;
		D[i].index = i;
		D[i].back = 0;
		D[i].front = 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(D[j].x > D[i].x)
			{
				if(j < i)
					D[i].front ++;
				else
					D[i].back ++;
			}
	sort(D + 1, D + 1 + n);
	memset(F, 0xff, sizeof(F));
	cout << f(0, 0) << endl;
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
