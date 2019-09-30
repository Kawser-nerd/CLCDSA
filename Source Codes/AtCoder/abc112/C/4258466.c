#include<stdio.h>
#include<math.h>
struct point
{
	int x, y, h;
}p[110];
int main()
{
	int n;
	int i, j, k, pp;
	int H, flag, h;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].h);
	pp = 1;
	while (!p[pp].h)pp++;
	for (i = 0; i <= 100; i++)
	{
		for (j = 0; j <= 100; j++)
		{
			flag = 0;
			H = p[pp].h + fabs(p[pp].x - i) + fabs(p[pp].y - j);
			if (!H)H = 0;
			for (k = 1; k <= n; k++)
			{
				h = H - fabs(p[k].x - i) - fabs(p[k].y - j);
				if (h<0)h = 0;
				if (h != p[k].h)
				{
					flag = 1;
					break;
				}
			}
			if(!flag)
				printf("%d %d %d", i, j, H);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].h);
   ^