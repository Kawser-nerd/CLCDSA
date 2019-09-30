#include <cstdio>
#include <cstring>

int	n , m;

bool	A[10][10];
bool	B[10][10];

void	init()
{
	int	a , b;

	memset(A , 0 , sizeof(A));
	scanf("%d" , &n);

	for (int i = 1; i < n; i ++)
	{
		scanf("%d%d" , &a , &b);
		a -- , b --;
		A[a][b] = A[b][a] = 1;
	}

	memset(B , 0 , sizeof(B));
	scanf("%d" , &m);
	for (int i = 1; i < m; i ++)
	{
		scanf("%d%d" , &a , &b);
		a -- , b --;
		B[a][b] = B[b][a] = 1;
	}
}

int	f	[10];
bool	used	[10];

bool	makeSearch(int p)
{
	if (p == m)
	{
		int	i , j;
		for (i = 0; i < m; i ++)
			for(j = 0; j < m; j ++)
				if (B[i][j] != A[f[i]][f[j]]) return 0;
		/*
		for (i = 0; i < m; i ++)
			printf("%d " , f[i]);
		printf("%d %d\n" , B[0][2] , A[f[0]][f[2]]);
		puts("done");
		*/
		return 1;
	}

	for (f[p] = 0; f[p] < n; f[p] ++)
	{
		if (used[f[p]]) continue;
		used[f[p]] = 1;
		if (makeSearch(p + 1)) return 1;
		used[f[p]] = 0;
	}
	return 0;
}

void	solve()
{
	memset(used , 0 , sizeof(used));
	if( makeSearch( 0 ) ) puts("YES");
	else puts("NO");
}

int	main()
{
//	freopen("in.txt" , "r" , stdin);
	freopen("D-small-attempt0.in" , "r" , stdin); freopen("D-small-attempt0.out" , "w" , stdout);
//	freopen("D-small-attempt1.in" , "r" , stdin); freopen("D-small-attempt1.out" , "w" , stdout);
//	freopen("D-large.in", "r" , stdin); freopen("D-large.out" , "w" , stdout);

	int	caseNo , t;
	scanf("%d" , &caseNo);

	for (t = 1; t <= caseNo; t ++)
	{
		init();
		printf("Case #%d: " , t);
		solve();
	}

	return 0;
}
