#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase ++)
	{
		int n,s,p;
		int ans = 0;
		scanf("%d%d%d",&n,&s,&p);
		for(int i = 0;i < n; i ++)
		{
			int score;
			scanf("%d",&score);

			if((score / 3) + (score % 3 != 0 ? 1 : 0) >= p)
			{
				ans ++;
			}
			else if(s > 0 && score >= 2 && score <= 28)
			{
				if((score - 2) / 3 + 2 >= p)
				{
					ans ++;
					s --;
				}
			}
		}
		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}