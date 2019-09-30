#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int	limit_size = 1000 + 10;

struct	Tpoint
{
	int	x, y;
};
bool	operator < (const Tpoint& A, const Tpoint& B)
{
	return A.x < B.x;
}

int		n;
Tpoint	list[limit_size];

int		cnt	[limit_size];
int		mat	[limit_size][10];

int		edge;

inline	void	addEdge(int a, int b)
{
	mat[a][cnt[a] ++] = b;
	mat[b][cnt[b] ++] = a;
	edge ++;
}

void	init()
{
	scanf("%d", &n);	
	for (int i = 0; i < n; i ++)
		scanf("%d%d", &list[i].x, &list[i].y);
	sort(list, list + n);

	memset(cnt, 0, sizeof(cnt));

	edge = 0;

	for (int i = 0; i < n; i ++)
	{
		for (int j = i + 1; j < n; j ++)
			if (list[j].y == list[i].y - 1)
			{
				addEdge(i, j);
				break;
			}
		for (int j = i + 1; j < n; j ++)
			if (list[j].y == list[i].y)
			{
				addEdge(i, j);
				break;
			}
		for (int j = i + 1; j < n; j ++)
			if (list[j].y == list[i].y + 1)
			{
				addEdge(i, j);
				break;
			}
	}

//	fprintf(stderr, "edge = %d\n", edge);
}

int		limit;
int		color	[limit_size];

bool	makeSearch(int x)
{
	if (x == n) 
		return 1;
	
	int min_choice = 100, u;
	int i, p, cnt_choice;
	bool choice[20];
	for (i = 0; i < n; i ++)
	{
		if (color[i] >= 0) continue;
		for (p = 0; p < limit; p ++)
			choice[p] = 1;
		for (p = 0; p < cnt[i]; p ++)
			if (color[mat[i][p]] >= 0) choice[color[mat[i][p]]] = 0;
		cnt_choice = 0;
		for (p = 0; p < limit; p ++)
			if (choice[p]) cnt_choice ++;
		if (cnt_choice == 0) return 0;
		if (cnt_choice < min_choice)
			min_choice = cnt_choice, u = i;
	}
	for (p = 0; p < limit; p ++)
		choice[p] = 1;
	for (p = 0; p < cnt[u]; p ++)
			if (color[mat[u][p]] >= 0) choice[color[mat[u][p]]] = 0;
	for (p = 0; p < limit; p ++)
		if (choice[p])
		{
			color[u] = p;
			if (makeSearch(x+1)) return 1;
			color[u] = -1;
		}
	return 0;
}

void	solve()
{
	for (limit = 1; ; limit ++)
	{
		memset(color, 0xff, sizeof(color));
		if (makeSearch(0))
		{
			printf("%d\n", limit);
			return;
		}
	}
}

int	main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int	cntCase;
	int	t;

	scanf("%d", &cntCase);
	for (t = 1; t <= cntCase; t ++)
	{
		printf("Case #%d: ", t);

		init();
		solve();
	}

	return 0;
}

