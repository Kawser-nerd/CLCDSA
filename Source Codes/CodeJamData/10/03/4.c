#include <stdio.h>

int main()
{
	int i;
	int T, t;
	int N;
	long long int R, k, g[1000];
	long long int ans;
	int front;
	long long int fill;
	long long int all;
	int period;
	int transient;
	int used[1000];
	int last_used[1000];
	long long int small_table[1000];
	int complete_period, remainder;
	long long int total_in_one_period;

	scanf("%d", &T);
	for(t=1; t<=T; t++)
	{
		scanf("%lld %lld %d", &R, &k, &N);
		for(i=0; i<N; i++)
			scanf("%lld", &g[i]);
		all = 0;
		for(i=0; i<N; i++)
			all += g[i];
		if(all<=k)
			ans = R*all;
		else
		{
			for(i=0; i<N; i++)
				used[i] = 0;
			front = 0;
			for(i=0; i<=N; i++)
			{
				if(used[front])
				{
					period = i-last_used[front];
					transient = last_used[front];
					break;
				}
				else
				{
					used[front] = 1;
					last_used[front] = i;
					small_table[i] = 0;
					fill = 0;
					while(fill+g[front]<=k)
					{
						fill += g[front];
						small_table[i] += g[front];
						front = (front+1)%N;
					}
				}
			}
			ans = 0;
			if(R<=transient)
			{
				for(i=0; i<R; i++)
					ans += small_table[i];
				R = 0;
			}
			else
			{
				for(i=0; i<transient; i++)
					ans += small_table[i];
				R -= transient;
			}
			complete_period = R/period;
			remainder = R%period;
			total_in_one_period = 0;
			for(i=transient; i<transient+period; i++)
				total_in_one_period += small_table[i];
			ans += total_in_one_period*complete_period;
			for(i=0; i<remainder; i++)
				ans += small_table[transient+i];
		}
		printf("Case #%d: %lld\n", t, ans);
	}

	return 0;
}

