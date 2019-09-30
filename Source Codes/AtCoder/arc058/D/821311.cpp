//#pragma comment(linker, "/STACK:102400000,102400000") 
#pragma warning(disable:4996)
#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
 
typedef long long ll;
#define eps 1e-10
#define LL_INF 0x33ffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
 
const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
 
int n, k;
bool dp[2002][10001];
bool good[2002][10001];
int vis[2002];
string s[2002];
vector <int> which;
vector <int> pos;
vector <int> next_which;
vector <int> next_pos;
 
char getBest()
{
	char ret = 'z';
	for (int i = 0; i < which.size(); i++)
	{
		ret = min(ret, s[which[i]][pos[i]]);
	}
	return ret;
}
 
void updateNext(char c, int remain)
{
	mem(vis, 0);
	next_which.clear();
	next_pos.clear();
	int firstFinish = n + 1;
	int rate = which.size() / 4000;
	rate = 0;
	int sz = which.size();
	for (int i = 0; i < sz; i += (rate + 1))
	{
		if (s[which[i]][pos[i]] == c)
		{
			if (pos[i] == s[which[i]].length() - 1)
			{
				firstFinish = min(firstFinish, which[i]);
			}
			else
			{
				vis[which[i]] = 1;
				next_which.push_back(which[i]);
				next_pos.push_back(pos[i] + 1);
			}
		}
	}
	for (int i = firstFinish + 1; i <= n; i++)
	{
		if (vis[i])continue;
		if (good[i][remain])
		{
			next_which.push_back(i);
			next_pos.push_back(0);
		}
	}
	which = next_which;
	pos = next_pos;
}
 
void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[n + 1][0] = true;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 0; j <= k; j++)
		{
			if (dp[i + 1][j] == true)
			{
				dp[i][j] = true;
			}
			if (j - (int)s[i].length() >= 0 && dp[i + 1][j - (int)s[i].length()])
			{
				dp[i][j] = true;
			}
		}
	}
	memset(good, false, sizeof(good));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (s[i].length() <= j && dp[i + 1][j - (int)s[i].length()])
			{
				good[i][j] = true;
			}
		}
	}
	int remain = k;
	for (int i = 1; i <= n; i++)
	{
		if (good[i][remain])
		{
			which.push_back(i);
			pos.push_back(0);
		}
	}
	string ret;
	for (int i = 1; i <= k; i++)
	{
		char c = getBest();
		remain--;
		updateNext(c, remain);
		ret += c;
	}
	cout << ret << endl;
}
 
int main()
{
	solve();
	return 0;
}