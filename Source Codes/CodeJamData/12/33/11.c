#include <stdio.h>
#include <stdlib.h>

int t, cas;
long long int box[110][2], toy[110][2], sum, ans, dup[110];
int n, m;
long long int dp[110][110];

int bt(int x, int k)
{
	int i, j, now=0;
	long long tot = 0, lose=0, pretype;
	if(x > m || k>=n)
	{
		if(k < n)
		{
			dup[k] = m;
			k++;
		}
		for(i=0; i<k; i++)
		{
			sum = 0;
			if(i>0 && pretype == box[i][1])
			{
				sum += lose;
				lose = 0;
			}
			for(j=now; j<dup[i]; j++)
			{
				if(box[i][1] == toy[j][1])
					sum += toy[j][0];
				pretype = box[i][1];
			}
			now = dup[i];
			if( sum > box[i][0] )
			{
				tot += box[i][0];
				lose = sum - box[i][0];
				if(dup[i] > 0 && lose > toy[dup[i]-1][0])
					lose = toy[dup[i]-1][0];
			}
			else
			{
				tot += sum;
				if(i>0 && now != dup[i-1])
					lose = 0;
			}
		}
		if( tot > ans )
			ans = tot;
		return 0;
	}
	dup[k] = x;
	bt(x, k+1);
	bt(x+1, k);
	return 0;
}


int main()
{
	int i;
	scanf("%d", &t);
	for(cas=1; cas<=t; cas++)
	{
		scanf("%d %d", &n, &m);
		for(i=0; i<n; i++)
			scanf("%lld %lld", &box[i][0], &box[i][1]);
		for(i=0; i<m; i++)
			scanf("%lld %lld", &toy[i][0], &toy[i][1]);
		ans = 0;
		bt(0, 0);
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}
