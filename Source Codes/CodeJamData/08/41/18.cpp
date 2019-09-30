#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define pb push_back
#define MP make_pair
#define For(a,b,c) for(typeof(b)a=(b); a<(c); ++a)
#define ALL(a) (a).begin(),(a).end()
#define DBG(a) cout << #a << ": " << a << endl
#define FORE(i, v) for(typeof(v.begin()) i = v.begin(); i != v.end(); ++i)

int M;
int memo[10011][2];
pair<int,int> node[10011];

int go(int v, int w)
{
	int& res = memo[v][w];
	if (res >= 0) { 
		return res;
	}
	
	res = 999999;
	if (node[v].first == 0 || node[v].second) //OR
	{
		if (w)
		{
			res <?= go(v*2, 0) + go(v*2+1, 1) + (node[v].first!=0);
			res <?= go(v*2, 1) + go(v*2+1, 0) + (node[v].first!=0);
			res <?= go(v*2, 1) + go(v*2+1, 1) + (node[v].first!=0);
		}
		else
			res <?= go(v*2, 0) + go(v*2+1, 0) + (node[v].first!=0);
	}
	if (node[v].first == 1 || node[v].second)
	{
		if (w)
			res <?= go(v*2, 1) + go(v*2+1, 1) + (node[v].first==0);
		else
		{
			res <?= go(v*2, 0) + go(v*2+1, 1) + (node[v].first==0);
			//cout << v << " " << w << " "<< res << endl;
			res <?= go(v*2, 1) + go(v*2+1, 0) + (node[v].first==0);
			//cout << v << " " << w << " "<< res << endl;
			res <?= go(v*2, 0) + go(v*2+1, 0) + (node[v].first==0);
			//cout << v << " " << w << " "<< res << endl;
		}
	}
	
	return res;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	int N;
	cin >> N;
	For (LOL, 1, N+1)
	{
		memset(memo, -1, sizeof(memo));
		
		int V;
		cin >> M >> V;
		For (i, 1, (M-1)/2+1)
			cin >> node[i].first >> node[i].second;					
		For (i, (M-1)/2+1, M+1)
		{
			cin >> node[i].first;
			memo[i][node[i].first] = 0;
			memo[i][!node[i].first] = 999999;
		}
		
		//For (i, 1, M+1) cout << node[i].first << "," << node[i].second << endl;
		
		printf("Case #%d: ", LOL);
		int g = go(1, V);
		if (g >= 999999)
			puts("IMPOSSIBLE");
		else
			printf("%d\n", g);
	}
}