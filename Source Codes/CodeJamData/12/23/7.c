#include <stdio.h>
#include <string.h>
#define MAXN 500

int sum;
int nums[MAXN];
int N;
int flag[MAXN + 1];

int search( int deepth, int left, int mid, int right)
{
	if ( left && right && left == right)
	{
		memset( flag + deepth, 0, sizeof( int) * ( N - deepth));
//		printf("find %d %d %d\n", deepth, left, right);
		return 1;
	}
	else
	{
		if ( deepth != N && sum - mid >= ( right << 1) && sum - mid >= ( left << 1))
		{
			flag[deepth] = 1;
			if ( search( deepth + 1, left + nums[deepth], mid, right))
			{
				return 1;
			}
			flag[deepth] = 0;
			if ( search( deepth + 1, left, mid + nums[deepth], right))
			{
				return 1;
			}
			flag[deepth] = -1;
			if ( search( deepth + 1, left, mid, right + nums[deepth]))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		scanf("%d", &N);
		int i;
		sum = 0;
		for ( i = 0; i < N; i++)
		{
			scanf("%d", nums + i);
			sum += nums[i];
		}

		printf("Case #%d:\n", cases+1);
		if ( search( 0, 0, 0, 0))
		{
			for ( i = 0; i < N; i++)
			{
				if ( flag[i] == 1)
				{
					printf("%d ", nums[i]);
				}
			}
			printf("\n");

			for ( i = 0; i < N; i++)
			{
				//printf("%d ", flag[i]);
				if ( flag[i] == -1)
				{
					printf("%d ", nums[i]);
				}
			}
			printf("\n");
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}
