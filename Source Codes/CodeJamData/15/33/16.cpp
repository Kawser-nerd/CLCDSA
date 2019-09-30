#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int T; scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int C,D,V;
		scanf("%d %d %d",&C,&D,&V);
		vector<int> coins;
		for (int q=0;q<D;++q)
		{
			int t;scanf("%d",&t);
			coins.push_back(t);
		}
		long long maxP = 0, ret = 0;
		while (maxP < V)
		{
			//maxP + 1
			while (true)
			{
				bool found = false;
				for (int q=0;q<D;++q)
				{
					if (coins[q] > 0 && coins[q] <= maxP + 1)
					{
						found = true;
						maxP += (long long)coins[q] * C;
						coins[q] = 0;
						break;
					}
				}
				if (found == false) break;
			}
			if (maxP < V)
			{
				//maxP + 1 coin publish
				ret++;
				maxP += (maxP + 1) * C;
			}
		}
		/*
		for (int v=1,i=0;v<=V;v++)
		{
			if (i<D && coins[i]==v)
			{
				maxP += v;
				i++;
			}
			else if (maxP < v)
			{
				//printf("need %d\n",v);
				maxP += v;
				ret++;
			}
		}
		*/
		printf("Case #%d: %lld\n",kase,ret);
	}

	return 0;
}