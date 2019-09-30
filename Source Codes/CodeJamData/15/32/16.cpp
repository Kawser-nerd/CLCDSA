#include <stdio.h>
#include <string>
#include <vector>
#include <memory.h>
#include <map>
#include <algorithm>
using namespace std;
int vs[105][105];
pair<int,double> dp[105][105];

char _Key[105]; string Key;
char _Log[105]; string Log;
int K,L,S;

int moves[105][105];

pair<int,double> memo(int chance, int state)
{
	if (vs[chance][state]) return dp[chance][state];
	vs[chance][state] = 1;
	pair<int,double>& ret = dp[chance][state];
	ret.first = 0;
	ret.second = 0;
	if (state == Log.size()) 
	{
		ret.first += 1;
		ret.second += 1;
	}
	if (chance == 0) return ret;
	int maxF = 0;
	for (int k=0;k<K;k++)
	{
		pair<int,double> sub = memo(chance - 1, moves[state][k]);
		maxF = max(maxF, sub.first);
		ret.second += sub.second / K;
	}
	ret.first += maxF;
	return ret;
}
int main()
{
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{

		scanf("%d %d %d",&K,&L,&S);
		scanf("%s",_Key);
		scanf("%s",_Log);

		Key = _Key;
		Log = _Log;

		memset(vs,0,sizeof(vs));
		memset(dp,0,sizeof(dp));

		for (int i=0;i<=Log.size();i++)
		{
			string cur = Log.substr(0,i);
			for (int k=0;k<K;k++)
			{
				string nx = cur + Key[k];
				while (nx.size() > Log.size() || Log.substr(0,nx.size()) != nx)
					nx = nx.substr(1);
				//printf("%s + %c => %s\n",cur.c_str(),Key[k],nx.c_str());
				moves[i][k] = nx.size();
			}
		}
		pair<int,double> solve = memo(S, 0);
		//printf("%d %.8lf\n",solve.first,solve.second);
		printf("Case #%d: %.8lf\n",kase,solve.first - solve.second);
	}
	return 0;
}