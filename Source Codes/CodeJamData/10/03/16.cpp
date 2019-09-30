#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<list>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int csK, csN;
int N, next[1024], nState, visit[1024];
long long R, K, G[2048];
long long ans, sum[1024], state[1024];

int main()
{
	int i, j, k, m, t, s;
	scanf("%d", &csN);
	for(csK = 1; csK <= csN; ++csK)
	{
		scanf("%I64d %I64d %d", &R, &K, &N);
		for(i = 0; i < N; ++i)
		{
			scanf("%I64d", &G[i]);
			G[i+N] = G[i];
		}
		ans = 0;
		sum[0] = 0;
		for(j = 0; j < N && sum[0]+G[j] <= K; ++j)
			sum[0] += G[j];
		next[0] = j % N;
		for(i = 1; i < N; ++i)
		{
			sum[i] = sum[i-1] - G[i-1];
			for(; j < i+N && sum[i]+G[j] <= K; ++j)
				sum[i] += G[j];
			next[i] = j % N;
		}

//		for(i = 0; i < N; ++i)
//			fprintf(stderr, "%d, %I64d, %I64d, %d\n", i, G[i], sum[i], next[i]);
		nState = 0;
		state[nState] = 0;
		s = 0;
		memset(visit, 0, sizeof(visit));
		do
		{
			state[nState+1] = sum[s] + state[nState];
			++nState;
			visit[s] = nState;
			s = next[s];
		}while(!visit[s]);
		if(R <= nState) ans = state[R];
		else
		{
			t = visit[s] - 1;
			R -= t;
			m = nState - t;
			ans = state[t] + (R/m)*(state[nState]-state[t])
				+ (state[R%m+t]-state[t]);
		}

		printf("Case #%d: %I64d\n", csK, ans);
	}
}


