#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

const	int		limitSize	= 20000 * 2 + 10;
const	int		limitLog	= 17;
const	int		limitAnswer	= 100;

int			n;
char			S	[limitSize];

int			suffixArray	[limitSize];
int			countRank	[limitSize];
int			rank		[limitSize];
int			tmp		[limitSize];

int			height		[limitSize];
int			Log		[limitSize];
int			lcp		[limitLog][limitSize];

int			tot , hisCount , best;
int			A	[20];
vector<int>		start		[limitSize];

FILE			*fin , *fout , *fans;

void	score(int sc , char* msg)
{
	printf("%s\n%d\n" , msg , sc);
	exit(0);
}

void	init()
{
	fscanf(fin , "%d" , &n);

	if( fscanf(fout , "%d" , &hisCount) <= 0 )
		score(0 , "Output format error");
	fscanf(fout , "%s" , S + 1);
	if( strlen(S + 1) != n )
		score(0 , "String length not match");

	for(int i = 1; i <= n; i ++)
		if( S[i] != '0' && S[i] != '1' ) score(0 , "Output is not 01-string");
}

inline	int	max(int a , int b){ return a > b ? a : b; }
inline	int	min(int a , int b){ return a < b ? a : b; }

void	build()
{
	int		cnt[2];
	int		i , j , k , L;

	memset(countRank , 0 , sizeof(countRank));
	memset(suffixArray , 0 , sizeof(suffixArray));
	memset(rank , 0 , sizeof(rank));
	memset(tmp , 0 , sizeof(tmp));

	cnt[0] = cnt[1] = 0;
	for(i = 1; i <= n; i ++)
		cnt[ S[i] - '0' ] = 1;
	cnt[1] += cnt[0];
	for(i = 1; i <= n; i ++)
		rank[i] = cnt[ S[i] - '0' ];
 
	for(L = 1; L <= n; L *= 2)
	{
		memset(countRank , 0 , sizeof(int) * (n + 10));
		for(i = 1; i <= n; i ++)
			countRank[ rank[i + L] ] ++;
		for(i = 1; i <= n; i ++)
			countRank[ i ] += countRank[i - 1];
		for(i = n; i > 0; i --)
			tmp[ countRank[ rank[i + L] ] -- ] = i;

		memset(countRank , 0 , sizeof(int) * (n + 10));
		for(i = 1; i <= n; i ++)
			countRank[ rank[i] ] ++;
		for(i = 1; i <= n; i ++)
			countRank[ i ] += countRank[i - 1];
		for(i = n; i > 0; i --)
			suffixArray[ countRank[ rank[ tmp[i] ] ] -- ] = tmp[i];

		memcpy(tmp , rank , sizeof(int) * (n + 10));

		rank[ suffixArray[1] ] = k = 1;
		for(i = 2; i <= n; i ++)
		{
			if( tmp[ suffixArray[i] ] != tmp[ suffixArray[i - 1] ] || tmp[ suffixArray[i] + L ] != tmp[ suffixArray[i - 1] + L ] )
				k ++;
			rank[ suffixArray[i] ] = k;
		}

		if( k == n ) break;
	}

	k = 0;
	for(i = 1; i <= n; i ++)
	{
		if( rank[i] == n )
		{
			height[n] = k = 0; continue;
		}
		j = suffixArray[ rank[i] + 1 ];
		for(k = max(0 , k - 1); S[i + k] == S[j + k]; k ++){}
		height[ rank[i] ] = k;
	}

	Log[0] = Log[1] = 0;
	for(i = 2; i <= n; i ++)
		Log[i] = Log[i / 2] + 1;

	for(i = 1; i < n; i ++)
		lcp[0][i] = height[i];

	for(L = 0; (1 << L) < n; L ++)
		for(i = 1; i + (1<<L) < n; i ++)
			lcp[L + 1][i] = min(lcp[L][i] , lcp[L][i + (1<<L)]);

}

inline	void	swap(int& a , int& b)
{
	int		t;
	t = a; a = b;  b = t;
}

inline	int	get_lcp(int i , int j)
{
	i = rank[i]; j = rank[j];
	if( i > j ) swap(i , j);

	int		L = Log[j - i];
	return min( lcp[L][i] , lcp[L][j - (1<<L)] );
}

void	add(int p , int len)
{
	int		i , size = start[len].size();

	for(i = 0; i < size; i ++)
		if(get_lcp(start[len][i] , p) >= len) return;
	tot ++;
	start[len].push_back( p );
}

inline	void	renew( int p , int q , int len )
{
	if( p > q ) swap(p , q);
	if( len >= q - p ) add(p , q - p);
}

void	solve()
{
	int		i , j;
	int		curt;

	tot = 0;

	for(i = 1; i < n; i ++)
	{
		curt = height[i];

		for(j = i + 1; j <= n; j ++)
		{
			renew( suffixArray[i] , suffixArray[j] , curt );
			curt = min( curt , height[j] );
		}
	}

	if( tot != hisCount )
		score(0 , "Number of repeats not match");
}

void	judge()
{
	int		i;

	fscanf( fans , "%d" , &best );
	fscanf( fans , "%s" , S );
	for(i = 0; i < 9; i ++)
		fscanf( fans , "%d" , A + i );
	for(i = 0; i < 9; i ++)
		if( tot <= best + A[i] )
		{
			printf("Correct! Yours = %d\n" , tot);
			printf("%d\n" , 10 - i);
			return;
		}
	
	printf("Correct! Yours = %d\n" , tot);
	printf("%d\n" , 1);
}

int	main(int argc, char *argv[])
{
	fin = fopen(argv[1] , "r");
	fout = fopen(argv[2] , "r");
	fans = fopen(argv[3] , "r");

	if( fout == NULL ) score(0 , "No output file!");

	init();
	build();
	solve();
	judge();

	return 0;
}
