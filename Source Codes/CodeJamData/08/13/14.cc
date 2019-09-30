#include <cstdio>
#include <cstring>

int		n;

void	init()
{
	scanf("%d" , &n);
}

struct	Tdat
{
	int	a , b;
};

Tdat	operator * (const Tdat& A , const Tdat& B)
{
	Tdat	ret;
	ret.a = (A.a * B.a + A.b * B.b * 5) % 1000;
	ret.b = (A.a * B.b + A.b * B.a) % 1000;
	return	ret;
}

void	solve()
{
	Tdat	ret;
	Tdat	w;

	ret.a = 1; ret.b = 0;
	w.a = 3; w.b = 1;

	while (n)
	{
		if (n & 1)
		{
			ret = ret * w;
		}
		n /= 2;
		w = w * w;
	}

	printf("%.3d\n" , (ret.a * 2 - 1 + 1000) % 1000);
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
		printf("Case #%d: " , t);
		solve();
	}

	return 0;
}
