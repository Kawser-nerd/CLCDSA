#include<stdio.h>

int main()
{
	int box, num, x, y, ball[2][100000]= {{1, }, {}}, i;

	scanf("%d%d", &box, &num);

	for(i= 0; i< box; i++)
		ball[1][i]= 1;

	for(i= 0; i< num; i++)
	{
		scanf("%d%d", &x, &y);
		ball[1][x- 1]--;
		ball[1][y- 1]++;

		if(ball[0][x- 1])
		{
			ball[0][y- 1]++;
			if(!ball[1][x- 1])
				ball[0][x- 1]= 0;
		}
	}

	x= 0;
	for(i= 0; i< box; i++)
		if(ball[0][i])
			x++;

	printf("%d\n", x);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &box, &num);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x, &y);
   ^