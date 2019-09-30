#include <stdio.h>

int main(void)
{
	int n, i, row, col, col2;
	int card [4][4] = {0};
	int card2[4][4] = {0};
	scanf("%d", &n);
	

	for(i=0; i<n; i++)
	{
		int ans1, ans2, cnt=0;
		int record = 0;


		scanf("%d", &ans1);
		for(row=0; row<4; row++)
		{
			scanf("%d %d %d %d", &card[row][0], &card[row][1], &card[row][2], &card[row][3]);
		}


		scanf("%d", &ans2);

		for(row=0; row<4; row++)
		{
			scanf("%d %d %d %d", &card2[row][0], &card2[row][1], &card2[row][2], &card2[row][3]);
		}

#if 0
		printf("--------------\n");
		printf("%d\n", ans1);
		for(row=0; row<4; row++)
			printf("%d %d %d %d\n", card[row][0], card[row][1], card[row][2], card[row][3]);
		printf("%d\n", ans2);
		for(row=0; row<4; row++)
			printf("%d %d %d %d\n", card2[row][0], card2[row][1], card2[row][2], card2[row][3]);
		printf("--------------\n");
#endif		
		for(col=0; col<4; col++)
		{
			for(col2=0; col2<4; col2++)
			{
				if(card[ans1-1][col] == card2[ans2-1][col2])
				{
					cnt++;
					record = card[ans1-1][col];
				}
			}

		}
		//printf("cnt:%d\n", cnt);

		if(cnt == 1)
			printf("Case #%d: %d\n", i+1, record);
		else if(cnt >= 2)
			printf("Case #%d: Bad magician!\n", i+1);
		else if(cnt == 0)
			printf("Case #%d: Volunteer cheated!\n", i+1);
	}

	return 0;
}
