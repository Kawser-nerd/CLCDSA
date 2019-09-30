#include <assert.h> 
#include <ctype.h> 
#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <string> 
#include <stdlib.h> 
#include <time.h> 
#include <algorithm> 
#include <numeric> 
#include <functional> 
#include <utility> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <sstream> 
#include <iostream> 
#include <memory.h>

using namespace std; 

#define rep(i,n) for(int i=0;i<(n);++i)
#define clr(a,b) memset(a,b,sizeof(a)); 
#define all(c) (c).begin(), (c).end() 
#define inf 1000000000 

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<int> vi;

vector<string> dict;

int maskChar[10000][30];
int maskPresent[10000];

int bestIndex = -1;
int bestErrors;

void dfs(string& a, int pos, int totalError, vector<int>& dictIndex)
{
	if (dictIndex.size() == 0)
		return;

	if (dictIndex.size() == 1)
	{
		int i = dictIndex[0];
		if (totalError > bestErrors || totalError == bestErrors && i < bestIndex)
		{
			bestIndex = i;
			bestErrors = totalError;
		}
		return;
	}
	int c = a[pos] - 'a';

	int charChoose = 0;
	for (int i = 0; i < dictIndex.size(); i++)
	{
		charChoose |= maskPresent[dictIndex[i]];
	}

	if ((charChoose & (1 << c)) == 0)
	{
		dfs(a, pos + 1, totalError, dictIndex);
	}
	else
	{
		map<int, vector<int> > mapByMask;

		for (int i = 0; i < dictIndex.size(); i++)
		{
			mapByMask[maskChar[dictIndex[i]][c]].push_back(dictIndex[i]);
		}

		for (map<int, vector<int> >::iterator i = mapByMask.begin(); i != mapByMask.end(); i++)
		{
			dfs(a, pos + 1, totalError + (i->first == 0 ? 1 : 0), i->second);
		}
	}

}

vector<int> dictLength[11];

string solve2(string a)
{
	bestIndex = -1;
	bestErrors = -1;

	for (int i = 1; i <= 10; i++)
	{
		dfs(a, 0, 0, dictLength[i]);
	}

	return dict[bestIndex];
}

int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);

	for (int nTest = 1; nTest <= T; nTest++)
	{		
		int N, M;
		cin >> N >> M;

		clr(maskChar, 0);
		clr(maskPresent, 0);

		dict.resize(N);
		for (int i = 0; i <= 10; i++)
			dictLength[i].clear();
		rep(i, N)
		{
			cin >> dict[i];

			for (int j = 0; j< dict[i].size(); j++)
			{
				char c = dict[i][j];
				maskChar[i][c - 'a'] |= 1 << j;
				maskPresent[i] |= 1 << (c - 'a');
			}
			dictLength[dict[i].size()].push_back(i);
		}

		string ans;

		rep(i, M)
		{
			string a;
			cin >> a;

			ans = ans + ' ' + solve2(a);
		}

		printf("Case #%d: %s\n", nTest, ans.c_str());
		fflush(stdout);
	} 


	return 0;
}


