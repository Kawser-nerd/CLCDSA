/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int tests, n, k;
int ts;
double p[N];
double ans;

double dp[500][500];

int cb(int x)
{
	if (x == 0)
		return 0;
	return cb(x / 2) + x % 2;
}

double solve(vector<double> v)
{
	int n = v.size();
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i + 1][j + 1] += dp[i][j] * v[i];
			dp[i + 1][j] += dp[i][j] * (1.0 - v[i]);
		}
	}
	return dp[n][n / 2];
}
int ans_mask;

void show(int mask)
{
	for (int i = 0; i < n; i++)
	{
		if (mask&(1 << i))
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;
}
int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	freopen("F:/in.txt", "r", stdin);
	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> tests;
	for (; tests; --tests)
	{
		cerr << ts << endl;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
			//p[i] = rand() % 100 * 1.0 / 100;
		}
		sort(p, p + n);

		++ts;
		ans = -1;
		cout << "Case #" << ts << ": ";
		
		vector<double> v;
		for (int pref = 0; pref <= k; pref++)
		{
			v.clear();
			for (int i = 0; i < pref; i++)
				v.push_back(p[i]);
			for (int i = n - 1; i >= n - (k-pref); i--)
				v.push_back(p[i]);
			ans = max(ans, solve(v));
		}
		cout.precision(10);
		cout << fixed << ans << endl;
		//show(ans_mask);
	}
	cin.get(); cin.get();
	return 0;
}