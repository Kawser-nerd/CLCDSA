#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define R_MAX 500
#define C_MAX 500

char field[R_MAX+2][C_MAX+3];
int r_series[R_MAX+2][C_MAX+2];
int c_series[R_MAX+2][C_MAX+2];

int min(int a, int b)
{
	if(a<b) return a;
	return b;
}

int main(void)
{
	int R, C, K;
	int i, j, x, y;
	int ans, is_valid;


	while(scanf("%d%d%d", &R, &C, &K)==3)
	{
		memset(field, 'x', sizeof(field));
		memset(r_series, 0, sizeof(r_series));
		memset(c_series, 0, sizeof(c_series));
		for(y=1;y<=R;y++)
		{
			scanf("%s", field[y]+1);
		}
		for(y=1;y<=R;y++)
		{
			for(x=1;x<=C;x++)
			{
				if(field[y][x]=='o')
				{
					for(i=x+1;i<=C && field[y][i]=='o';i++)
						;

					for(j=x;j<i;j++)
					{
						r_series[y][j]=min(abs(j-x+1), abs(j-i));
					}
					x=i;
				}
			}
		}
		for(x=1;x<=C;x++)
		{
			for(y=1;y<=R;y++)
			{
				if(field[y][x]=='o')
				{
					for(i=y+1;i<=R && field[i][x]=='o';i++)
						;

					for(j=y;j<i;j++)
					{
						c_series[j][x]=min(abs(j-y+1), abs(j-i));
//						c_series[j][x]=min(c_series[j][x], r_series[j][x]);
					}
					y=i;
				}
			}
		}

		ans=0;
		for(y=1;y<=R;y++)
		{
			for(x=1;x<=C;x++)
			{
				if(r_series[y][x]>=K && c_series[y][x]>=K)
				{
					is_valid=1;
					for(i=-K+1;i<K;i++)
					{
						if(r_series[y+i][x]<K-abs(i))
						{
//							printf("y+i=%d   x=%d K-|i|=%d\n", y+i, x, K-abs(i));
							is_valid=0;
						}
						if(c_series[y][x+i]<K-abs(i))
						{
//							printf("  y=%d x+i=%d K-|i|=%d\n", y, x+i, K-abs(i));
							is_valid=0;
						}
					}
					if(is_valid)
					{
//						printf("(%d,%d)\n", x, y);
						ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
/*
		printf("---- field ----\n");
		for(y=1;y<=R;y++)
		{
			printf("%.*s\n", C, field[y]+1);
		}
		printf("---- r_series ----\n");
		for(y=1;y<=R;y++)
		{
			for(x=1;x<=C;x++) printf("%d", r_series[y][x]);
			printf("\n");
		}

		printf("---- c_series ----\n");
		for(y=1;y<=R;y++)
		{
			for(x=1;x<=C;x++) printf("%d", c_series[y][x]);
			printf("\n");
		}
*/
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s", field[y]+1);
    ^