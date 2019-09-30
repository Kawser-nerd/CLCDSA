#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct		Tdat
{
	double	x[3];
	double	p;
};

const	int	limitSize	= 1000 + 10;

int		n;
Tdat		list	[limitSize];

void	init()
{
	scanf("%d" , &n);
	for (int i = 0; i < n; i ++)
		scanf("%lf%lf%lf%lf" , &list[i].x[0] , &list[i].x[1] , &list[i].x[2] , &list[i].p);
}

double		top	[9];

bool	judge(double v)
{
	int	i , stat , p;
	for (i = 0; i < 8; i ++)
		top[i] = 1e15;

	for (i = 0; i < n; i ++)
	{
		for (stat = 0; stat < 8; stat ++)
		{
			double	curt = list[i].p * v;
			for (p = 0; p < 3; p ++)
				if (stat & (1<<p))
					curt += list[i].x[p];
				else	curt -= list[i].x[p];
			if (curt < top[stat])
				top[stat] = curt;
		}
	}
	for (stat = 0; stat < 8; stat ++)
		if (top[stat] < - top[7 ^ stat] - 1e-8) return 0;
	return 1;
}

void	solve()
{
	double	low = 0;
	double	upp = 1e15;
	double	mid;

//	printf("%d\n" , judge(5));

	while ( (upp - low) > 1e-7 )
	{
		mid = (low + upp) / 2;
		if (judge(mid)) upp = mid;
		else low = mid;
	}

	printf("%.6lf\n" , (low + upp) / 2.0);
}

int	main()
{
	freopen("C-large.in" , "r" , stdin);
	freopen("Clarge.txt" , "w" , stdout);
	
	int	t , caseNo;

	scanf("%d" , &caseNo);
	for (t = 1; t <= caseNo; t ++)
	{
		printf("Case #%d: " , t);
		init();
		solve();
	}

	return 0;
}
