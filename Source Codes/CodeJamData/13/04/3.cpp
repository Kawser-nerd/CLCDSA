#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

int n;
vector <int> have[201];
int req[201];
int cnt[201];
int currentCnt[201];
bool valid[201];

bool graph[201][201];
bool v[201];
int q[1000001], now, z;

bool check()
{
	memset(graph, false, sizeof(graph));
	for(int i = 1; i <= n; i++)
		if(valid[i])
			for(int j = 0; j < have[i].size(); j++)
				graph[req[i]][have[i][j]] = true;
	memset(v, false, sizeof(v));
	now = 1;
	z = 0;
	for(int i = 1; i <= 200; i++)
		if(currentCnt[i] > 0)
		{
			v[i] = true;
			q[++z] = i;
		}

	while(now <= z)
	{
		int s = q[now];
		for(int i = 1; i <= 200; i++)
			if(graph[s][i])
				if(!v[i])
				{
					v[i] = true;
					q[++z] = i;
				}
		++ now;
	}
	
	for(int i = 1; i <= n; i++)
		if(valid[i])
			if(v[req[i]] == false)
				return false;
	return true;
}

void calc()
{
	for(int i = 1; i <= 200; i++)
		if(cnt[i] > 0)
		{
			cout << "IMPOSSIBLE" << endl;
			return;
		}

	if(!check())
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	for(int t = 1; t <= n; t++)
	{
		for(int i = 1; i <= n; i++)
			if(valid[i])
			{
				if(currentCnt[req[i]] == 0)
					continue;
				currentCnt[req[i]] --;
				for(int j = 0; j < have[i].size(); j++)
					currentCnt[have[i][j]] ++;
				valid[i] = false;
				if(check())
				{
					cout << i << (t == n ? "\n" : " ");
					 break;
				}
				currentCnt[req[i]] ++;
				for(int j = 0; j < have[i].size(); j++)
					currentCnt[have[i][j]] --;
				valid[i] = true;
			}
	}
}

void solve()
{
	int t;
	cin >> t >> n;

	memset(cnt, 0, sizeof(cnt));
	memset(currentCnt, 0, sizeof(currentCnt));
	memset(valid, true, sizeof(valid));

	for(int i = 1; i <= t; i++)
	{
		int x;
		cin >> x;
		currentCnt[x] ++;
		cnt[x] --;
	}
	for(int i = 1; i <= n; i++)
	{
		have[i].clear();
		int x;
		cin >> x;
		cnt[x] ++;
		req[i] = x;
		int amount;
		cin >> amount;
		for(int j = 1; j <= amount; j++)
		{
			cin >> x;
			cnt[x] --;
			have[i].push_back(x);
		}
	}
	calc();
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int CaseID = 1; CaseID <= TestCase; CaseID ++)
	{
		cout << "Case #" << CaseID << ": ";
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

