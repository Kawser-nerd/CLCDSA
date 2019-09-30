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

int n, total;
vector <int> xs;
int F[10001][10001];

int f(int L, int R)
{
	if(L > R) return 0;
	if(L == R) return 1;
	int &ret = F[L][R];
	if(ret != -1) return ret;
	ret = 100000;
	ret = min(ret, 1 + f(L+1, R));
	ret = min(ret, 1 + f(L, R-1));
	if(xs[L] + xs[R] <= total)
		ret = min(ret, 1 + f(L+1, R-1));
	return ret;
}

void solve()
{
	
	cin >> n >> total;
	int ans = 0;
	xs.clear();	
	for(int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		xs.push_back(t);
	}
	sort(xs.begin(), xs.end());
	memset(F, 0xff, sizeof(F));
	cout << f(0, n-1) << endl;
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
