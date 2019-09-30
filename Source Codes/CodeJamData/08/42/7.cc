#include <cstdio>
#include <cstring>
#include <cmath>

const	int		limitSize	= 20000;

int			n;
int			list	[limitSize];
double			score	[limitSize][3];

double			f	[limitSize];

void	init()
{
	int		i , j;
	for(i = 0; i < n; i ++)
		for(j = 0; j < 3; j ++)
			scanf("%lf" , &score[i][j]);
	for(i = 0; i < n; i ++)
	{
		scanf("%d" , list + i);
		list[i] --;
	}
}

void	solve()
{
	int		i , stat , p;

	f[0] = score[ list[0] ][0] + score[ list[0] ][1] + score[ list[0] ][2];
	
	for(i = 1; i < n; i ++)
	{
		f[i] = -1;
		
		for(stat = 0; stat < 8; stat ++)
		{
			double	curt = 0;
			for(p = 0; p < 3; p ++)
				if( stat & (1<<p) ) curt += score[ list[i] ][p];
			if( curt < f[i - 1] || ( fabs(curt - f[i-1]) < 1e-6 && list[i - 1] < list[i]) )
				if( curt > f[i] ) f[i] = curt;
		}
		
		if( f[i] < 0 )
		{
			puts("-1"); return;
		}
	}

	printf("%.2lf\n" , f[n - 1]);
}

int	main()
{
//	freopen("in.txt" , "r" , stdin);

	int		cntCase = 0;

	while( scanf("%d" , &n) , n )
	{
		printf("Case %d: " , ++ cntCase);

		init();
		solve();
	}

	return 0;
}
