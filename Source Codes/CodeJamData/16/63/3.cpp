#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
const double PI = acos(-1.0);
const ll TOP = 1e12;
const int MAXM = 1e6 + 10;

ifstream fin ("C.in");
ofstream fout ("C.out");

double hype (double x, double y) // hype
{
	return sqrt (x * x + y * y);
}

int N, M;
ll R, ans;
vector <int> pfac[MAXM];

int get (int x, int n)
{
	int tot = 0;
	int k = pfac[n].size();
	for (int i = 0; i < (1 << k); i++)
	{
		int mult = 1, cnt = 1;
		for (int j = 0; j < k; j++)
		{
			if (i & (1 << j))
			{
				mult *= pfac[n][j];
				cnt *= -1;
			}
		}
		tot += cnt * (x / mult);
	}
	
	//cout << x << " " << n << " " << tot << "\n";
	return tot;
}

int main()
{
	for (int i = 0; i < MAXM; i++)
		pfac[i].clear();
	for (int i = 2; i < MAXM; i++)
	{
		if (!pfac[i].size())
		{
			for (int j = i; j < MAXM; j += i)
				pfac[j].push_back (i);
		}
	}
	
	int ntest; fin >> ntest;
	for (int test = 0; test < ntest; test++)
	{
	
	fin >> N >> R;
	ans = 2;
	
	ll hi = min (MAXM, N - 1);
	for (int i = 1; i <= min (MAXM, N - 1); i++)
	{
		while (hi >= 0)
		{
			ll val = hi * hi + i * (ll) i;
			if (TOP / val < R * R)
				hi--;
			else if (val * R * R >= TOP)
				hi--;
			else
				break;
		}
		if (hi < 0) break;
		
		ans += get (hi, i);
	}
	
	fout << "Case #" << test + 1 << ": ";
	fout << ans << "\n";
	
	}
	
	return 0;
}
