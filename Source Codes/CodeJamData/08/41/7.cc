#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const	int	limitSize	= 800 + 10;

int		n;
int		A	[limitSize];
int		B	[limitSize];
long long	C	[limitSize][limitSize];

long long	lx	[limitSize];
long long	ly	[limitSize];
int		cx	[limitSize];
int		cy	[limitSize];

bool		mx	[limitSize];
bool		my	[limitSize];

void	init()
{
	scanf("%d" , &n);

	int	i , j;
	for (i = 0; i < n; i ++)
		scanf("%d" , A + i);
	for (i = 0; i < n; i ++)
		scanf("%d" , B + i);

	for (i = 0; i < n; i ++)
		for (j = 0; j < n; j ++)
			C[i][j] =  - (long long)A[i] * B[j];
}

bool Path(int u)
{
	mx[u] = 1;
	for(int i = 0; i < n; i ++)
		if(! my[i] && lx[u] + ly[i] == C[u][i])
		{
			my[i] = 1;
			if(cy[i] < 0 || Path(cy[i]))
			{
				cx[u] = i; cy[i] = u; return 1;
			}
		}
	return 0;
}

void Modify()
{
	int i , j;
	long long alpha = 1000000;

	for(i = 0; i < n; i ++)
		for(j = 0; j < n; j ++)
			if(mx[i] && !my[j])
				alpha = min(alpha , lx[i] + ly[j] - C[i][j]);	
	for(i = 0; i < n; i ++)
		if(mx[i]) lx[i] -= alpha;
	for(i = 0; i < n; i ++)
		if(my[i]) ly[i] += alpha;
}

void Solve()
{
	int i , j;

	memset(lx , 0 , sizeof(lx));
	memset(ly , 0 , sizeof(ly));

	for(i = 0; i < n; i ++)
		for(j = 0; j < n; j ++)
			lx[i] = max(C[i][j] , lx[i]);

	memset(cx , 0xff , sizeof(cx));
	memset(cy , 0xff , sizeof(cy));

	for(i = 0; i < n; i ++)
	{
		if(cx[i] < 0)
		{
			memset(mx , 0 , sizeof(mx));
			memset(my , 0 , sizeof(my));

			while(! Path(i))
			{
				Modify();
				memset(mx , 0 , sizeof(mx));
				memset(my , 0 , sizeof(my));
			}
		}
	}

	long long	ans = 0;
	for (i = 0; i < n; i ++)
		ans += lx[i] + ly[i];

	cout << - ans << endl;
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

		cout << "Case #" << t << ": ";

		cerr << t << endl;

		Solve();
	}

	return 0;
}
