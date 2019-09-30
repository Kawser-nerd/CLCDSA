#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int		n , m;

struct	Tdat
{
	int	H , W;
};

vector<Tdat>	isBird;
vector<Tdat>	notBird;

void	init()
{
	isBird.clear();
	notBird.clear();

	cin >> n;

	Tdat	t;
	string	buf;
	for (int i = 0; i < n; i ++)
	{
		cin >> t.H >> t.W;
		cin >> buf;

		if (buf == "BIRD")
			isBird.push_back ( t );
		else {
			cin >> buf;
			notBird.push_back ( t );
		}
	}
}

bool	check()
{
	if (isBird.size() == 0) return 1;

	int	lowH , uppH;
	int	lowW , uppW;

	lowH = uppH = isBird[0].H;
	lowW = uppW = isBird[0].W;

	for (int i = 0; i < isBird.size(); i ++)
	{
		if (isBird[i].H < lowH)
			lowH = isBird[i].H;
		if (isBird[i].H > uppH)
			uppH = isBird[i].H;
		if (isBird[i].W < lowW)
			lowW = isBird[i].W;
		if (isBird[i].W > uppW)
			uppW = isBird[i].W;
	}

	for (int i = 0; i < notBird.size(); i ++)
	{
		if (lowH <= notBird[i].H && notBird[i].H <= uppH
			&& lowW <= notBird[i].W && notBird[i].W <= uppW)
			return 0;
	}

	return 1;
}

void	solve()
{
	cin >> m;

	Tdat	curt;
	while (m --)
	{
		cin >> curt.H >> curt.W;
		
		int	flag = 3;

		isBird.push_back( curt );
		if (!check()) flag ^= 1;
		isBird.pop_back();

		notBird.push_back( curt );
		if (!check()) flag ^= 2;
		notBird.pop_back();

		//printf("flag = %d " , flag);

		if (flag == 1) puts("BIRD");
		else if (flag == 2) puts("NOT BIRD");
		else puts("UNKNOWN");
	}
}

int	main()
{
//	freopen("in.txt" , "r" , stdin);
//	freopen("A-small-attempt0.in" , "r" , stdin); freopen("A-small-attempt0.out" , "w" , stdout);
//	freopen("A-small-attempt1.in" , "r" , stdin); freopen("A-small-attempt1.out" , "w" , stdout);
	freopen("A-large.in", "r" , stdin); freopen("A-large.out" , "w" , stdout);

	int	t , cntCase;
	cin >> cntCase;

	for (t = 1; t<= cntCase; t ++)
	{
		printf("Case #%d:\n" , t);

		init();
		solve();
	}

	return 0;
}
