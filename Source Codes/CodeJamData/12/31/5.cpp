#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;


vector<int>v[1000];

bool F(int N,int from)
{
	bool f[1000]={};
	queue<int>q;
	q.push(from);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(f[x]++)
			return true;
		for(int i=0; i<v[x].size(); ++i)
			q.push(v[x][i]);
	}
	return false;
}
int main()
{
	int T, caseNum;
	scanf("%d",&T);
	for(caseNum = 1; caseNum <= T; ++caseNum)
	{
		int N,M;
		scanf("%d",&N);
		int i,j,k;
		for(i=0; i<N; ++i)
		{
			v[i].clear();
			scanf("%d",&M);
			for(j=0; j<M; ++j)
			{
				scanf("%d",&k);
				v[i].push_back(k-1);
			}
		}

		bool f = false;
		for(i=0; i<N; ++i)
			f = f||F(N,i);

		printf("Case #%d: %s\n", caseNum, f?"Yes" : "No");
	}
	return 0;
}
/*

それぞれの頂点ごとについて、そこだけから伝達→ある頂点に、二回来てからYES,そうでなければNO
O(N^2),かしら


*/
