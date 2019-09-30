#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int		n , m;
vector<int>	list	[2000 + 10];

void	init()
{
	scanf("%d%d" , &n , &m);
	for (int i = 0; i < m; i ++)
	{
		list[i].clear();
		int	t , a , b;
		for (scanf("%d" , &t); t > 0; t --)
		{
			scanf("%d%d" , &a , &b);
			if (b) a = -a;
			list[i].push_back(a);
		}
	}
}

int		color	[2010];

void	solve()
{
	memset(color , 0 , sizeof(color));

	int	i , p , k;

	bool	modify = 1;
	while (modify)
	{
		modify = 0;
		for (i = 0; i < m; i ++)
		{
			bool	can = 0;
			int	who = 0;
			for (p = 0; p < list[i].size(); p ++)
			{
				if (list[i][p] > 0 && color[ list[i][p] ] == 0 ) can = 1;
				if (list[i][p] < 0 && color[ - list[i][p] ] == 1 ) can = 1;
				if (list[i][p] < 0) who = - list[i][p];
			}
			if (! can && who && color[who] == 0)
				color[who] = 1 , modify = 1;
		}		
	}

	for (i = 0; i < m; i ++)
	{
		bool	can = 0;
		int	who = 0;
		for (p = 0; p < list[i].size(); p ++)
		{
			if (list[i][p] > 0 && color[ list[i][p] ] == 0 ) can = 1;
			if (list[i][p] < 0 && color[ - list[i][p] ] == 1 ) can = 1;
		}
		if (! can)
		{
			puts(" IMPOSSIBLE");  return;
		}
	}
	
	for (i = 1; i <= n; i ++)
		printf(" %d" , color[i]);
	putchar('\n');
}

int	main()
{
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);

	int	t , caseNo;
	scanf("%d" , &caseNo);

	for (t = 1; t <= caseNo; t ++)
	{
		init();
		printf("Case #%d:" , t);
		solve();
	}

	return 0;
}
