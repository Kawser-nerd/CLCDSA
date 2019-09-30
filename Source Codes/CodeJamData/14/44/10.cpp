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

map < string, int > toID;
int n, m, z;

int getID(string s)
{
	if(toID.count(s) == false)
	{
		z ++;
		toID[s] = z;
	}
	return toID[s];
}

vector <int> son[100001];
int bs[100001];
long long C[101][101];
long long mod = 1000000007;
int have[100001];

int dfs(int cur, int bound)
{
	int ret = 0;
	for(int i = 0; i < son[cur].size(); i++)
	{
		ret += dfs(son[cur][i], bound);
	}
	ret += have[cur];
	ret = min(ret, bound);
	bs[cur] = ret;
	return ret;
}

long long calc(int k, vector <int> ks, int haveMe)
{
	long long ret = 0;
	for(int i = k; i >= 1; i--)
	{
		long long thisCase = C[k][i];
		if((k-i) % 2 != 0) thisCase *= -1;
		for(int j = 0; j < ks.size(); j++)
		{
			thisCase *= C[i][ks[j]];
			thisCase %= mod;
		}
		ret += thisCase;
		ret %= mod;
	}
	ret %= mod;
	ret += mod;
	ret %= mod;

	if(haveMe) ret += calc(k-1, ks, false);
	if(haveMe) ret *= k;
	ret %= mod;
	ret += mod;
	ret %= mod;
	return ret;
}

void solve()
{
	cin >> m >> n;
	memset(have, 0, sizeof(have));
	for(int i = 1; i <= 100000; i++)
		son[i].clear();
	toID.clear();
	z = 0;
	for(int i = 1; i <= m; i++)
	{
		string s;
		cin >> s;
		string t;
		int prev = getID(t);
		for(int j = 0; j < s.length(); j++)
		{
			t += s[j];
			int prevz = z;
			int now = getID(t);
			if(now > prevz)
			{
				son[prev].push_back(now);
			}
			prev = now;
		}
		have[getID(s)] = 1;
	}
	dfs(1, n);
	int ret = 0;
	long long ans = 1;
	for(int i = 1; i <= z; i++)
	{
		ret += min(n, bs[i]);
		vector <int> ts;
		for(int j = 0; j < son[i].size(); j++)
		{
			int t = son[i][j];
			ts.push_back(bs[t]);
		}
		ans *= calc(bs[i], ts, have[i]);
		ans %= mod;
	}
	cout << ret << " " << ans << endl;
}

int MAIN()
{
	memset(C, 0, sizeof(C));
	for(int i = 0; i <= 100; i++)
	{
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}

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
