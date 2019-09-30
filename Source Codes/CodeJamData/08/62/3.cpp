#include <cstdio>
#include <cstring>

int		n , m , r , c;

int		mat	[51][51];

void	init()
{
	scanf("%d%d%d%d" , &m , &n , &c , &r);
	c -- , r --;

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			scanf("%d" , &mat[i][j]);
}

int		ans;
int		dx[] = {-1 , 0 , 0 , 1};
int		dy[] = {0 , -1 , 1 , 0};

inline	bool	valid(int x , int y)
{
	return	 0 <= x && x < n && 0 <= y && y < m;
}

void	makeSearch(int day , int mat[51][51])
{
	/*
	puts("--------------------------");
	printf("day = %d\n" , day);
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
			printf("%d " , mat[i][j]);
		putchar('\n');
	}
	*/

	if (mat[r][c] <= 0) return;
	if (ans < 0) return;
	if (ans >= 0 && day > ans) ans = day;
	

	int	d;

	for (d = 0; d < 4; d ++)
		if (valid(r + dx[d] , c + dy[d]) &&
			mat[r+dx[d]][c + dy[d]] > 0) break;
	if (d == 4)
	{
		ans = -1;
		return;
	}

	int	tmp[51][51];
	int	i , j;

	for (d = 0; d <= 4; d ++)
	{
		if (d < 4)
			if (! valid(r + dx[d], c + dy[d])
				|| mat[r+dx[d]][c+dy[d]] < 0 )
					continue;
		memcpy(tmp , mat , sizeof(tmp));
		for (i = 0; i < n; i ++)
			for (j = 0; j < m; j ++)
			{
				if (mat[i][j] <= 0) continue;
				if (i == r && j == c)
				{
					if (d == 4) continue;
					tmp[r+dx[d]][c+dy[d]] -= mat[r][c];
				}
				else
				{
					int	sg = -1;
					for (int p = 0; p < 4; p ++)
						if (valid(i+dx[p],j+dy[p])
							&& mat[i+dx[p]][j+dy[p]] > 0)
								if (sg < 0 || mat[i+dx[p]][j+dy[p]] > mat[i+dx[sg]][j+dy[sg]])
									sg = p;
					if (sg >= 0)
						tmp[i+dx[sg]][j+dy[sg]] -= mat[i][j];
				}
			}

		makeSearch(day + 1 , tmp);
	}
}

void	solve()
{
	ans = 0;

	makeSearch(0 , mat);

	if ( ans < 0 ) printf("forever\n");
	else printf("%d day(s)\n" , ans);
}

int	main()
{
//	freopen("in.txt" , "r" , stdin);
//	freopen("B-small-attempt0.in" , "r" , stdin); freopen("B-small-attempt0.out" , "w" , stdout);
//	freopen("B-small-attempt1.in" , "r" , stdin); freopen("B-small-attempt1.out" , "w" , stdout);
	freopen("B-large.in", "r" , stdin); freopen("B-large.out" , "w" , stdout);

	int	t , cntCase;
	scanf("%d" , &cntCase);
	for (t = 1; t <= cntCase; t ++)
	{
		init();
		printf("Case #%d: " , t);
		fprintf(stderr , "%d\n" , t);
		solve();
	}


	return 0;
}
