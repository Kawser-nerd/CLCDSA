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

int tests;
int n;
int C;
vector<int> g[100];
int used[2000];
vector<pair<int,int> > comps;
vector<int> comp;

pair<int,int> get_bal(vector<int> v)
{
	pair<int, int> res = make_pair(0, 0);

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < n)
			res.first++;
		else
			res.second++;
	}
	return res;
}

void dfs(int v)
{
	used[v] = 1;
	comp.push_back(v);
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
}

int F1, F2;

int dp[1 << 17][30][30];

pair<int, int> eval(int mask)
{
	pair<int, int> res = make_pair(0, 0);
	for (int i = 0; i < n; i++)
	{
		if (mask&(1 << i))
		{
			res.first += comps[i].first;
			res.second += comps[i].second;
		}
	}
	return res;
}

int ts = 0;

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
		++ts;
		cerr << ts << endl;
		cin >> n;
		for (int i = 0; i < n*2; i++)
		{
			g[i].clear();
		}

		C = 0;
		F1 = F2 = 0;

		for (int i = 0; i < n; i++)
		{
			string st;
			cin >> st;
			for (int j = 0; j < n; j++)
			{
				if (st[j] == '1')
				{
					++C;
					g[i].push_back(j + n);
					g[j + n].push_back(i);
				}
			}
		}

		for (int i = 0; i < n * 2; i++)
		{
			used[i] = 0;
		}

		comps.clear();

		int ohead = 0;

		for (int i = 0; i < n * 2; i++)
		{
			if (used[i])
				continue;
			comp.clear();
			dfs(i);
			pair<int,int> bal = get_bal(comp);
			if (bal.first==bal.second)
			{
				ohead += comp.size()*comp.size() / 4;
				continue;
			}
			if (comp.size() == 1)
			{
				if (comp[0] < n)
				{
					F1++;
				}
				else
					F2++;
				continue;
			}
			comps.push_back(bal);
		}

		n = comps.size();
		for (int i = 0; i < (1 << n); i++)
		{
			for (int j = 0; j <= F1; j++)
			{
				for (int q = 0; q <= F2; q++)
				{
					dp[i][j][q] = 1e9;
				}
			}
		}

		//cout << n << " " << F1 << " " << F2 <<" "<<C<<" "<<ohead<< endl;
		//if (comps.size())
			//cout << comps[0].first << " " << comps[0].second << endl;
			
		dp[0][F1][F2] = 0;

		for (int mask = 0; mask < (1 << n); mask++)
		{
			//cout << mask<<"%"<<n<<"@" << endl;
			for (int qf1 = F1; qf1>=0; qf1--)
			{
				for (int qf2 = F2; qf2 >=0; qf2--)
				{
					if (dp[mask][qf1][qf2]>1e8)
						continue;
					if (qf1&&qf2)
						dp[mask][qf1 - 1][qf2 - 1] = min(dp[mask][qf1 - 1][qf2 - 1], dp[mask][qf1][qf2] + 1);
					int rem_mask = (1 << n) - 1 - mask;
					int S = rem_mask;
					int need_f1, need_f2;

					while (rem_mask)
					{
						//cout << rem_mask<<" " << S << endl;

						pair<int, int> P = eval(rem_mask);
						//cout << P.first << "@" << P.second << endl;
						if (P.first < P.second)
						{
							need_f1 = P.second - P.first;
							need_f2 = 0;
						}
						else
						{
							need_f2 = P.first - P.second;
							need_f1 = 0;
						}
						if (need_f1 > qf1 || need_f2 > qf2)
						{
							rem_mask =((rem_mask-1)& S);
							continue;
						}
						int SZ = P.first + P.second + need_f1 + need_f2;
						SZ /= 2;
						dp[mask | rem_mask][qf1 - need_f1][qf2 - need_f2] = min(dp[mask | rem_mask][qf1 - need_f1][qf2 - need_f2],
							dp[mask][qf1][qf2] + SZ*SZ);
						rem_mask =((rem_mask-1)& S);
					}
				}
			}
		}

		cout << "Case #" << ts << ": " << dp[(1 << n) - 1][0][0] +ohead- C << endl;

	}

	cin.get(); cin.get();
	return 0;
}