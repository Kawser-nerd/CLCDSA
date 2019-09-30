#include <myheading.h>

const int MAXN = 500000  ;
const int mod = 1000000007 ;

#define uint64 unsigned long long

int n; 

int a[ MAXN+1 ];

inline bool cmp( const int &t1, const int &t2 ) { return a[t1]<a[t2]; }

void readin()
{
	static int idx[ MAXN+1 ];

	int t[ 200 ] ;
	int m ;
	uint64 x, y, z ;
	
	cin>> n>>m>>x>>y>>z ;
	myfor( i, 0, m-1 ) cin>>t[i]; 

	myfor( i, 0, n-1 )
	{
		a[i+1] = t[ i%m ] ;
		idx[i+1] = i+1 ;

		t[i%m] = (int)( ( x * t[i%m] + y*(i+1) ) % z );
	}

	sort( idx+1, idx+1+n, cmp );

	int i , tmp ;
	for( m=0, i=1;  i<=n;  )
	{
		tmp = a[ idx[i] ] , ++m ;
		do a[ idx[i++] ] = m;  while( i<=n && a[ idx[i] ]==tmp );
	}
}

uint64 f[ MAXN+1 ];

inline int lowbit(int x) { return x&(x^(x-1)); } 
uint64 sum[ MAXN+1  ];

void insert( int i, uint64 x )
{
	for( int p=i; p<=n; p += lowbit(p) )
		sum[p] = ( sum[p] + x ) % mod ;
}

uint64 getsum( int i )
{
	if( i<=0 ) return 0;

	uint64 re = 0;
	for( int p=i; p>0; p-=lowbit(p) )
		re = ( re + sum[p] ) % mod ;

	return re;
}


void work()
{
	memset( f, 0, sizeof(f) ) ;
	memset( sum, 0, sizeof(sum) );

	myfor( i, 1, n )
	{
		f[i] = 1 ;
		f[i] = ( f[i] + getsum(a[i]-1) ) % mod ;
		insert( a[i], f[i] ) ;		
	}

	uint64 ans = 0;
	myfor( i, 1, n )
		ans = ( ans + f[i] ) % mod ;

	cout<<ans<<endl;
}


int main()
{
	freopen( "C-large.in", "r", stdin );
	freopen( "C-large.out", "w", stdout );
	//freopen( "C-small-attempt0.in", "r", stdin );
	//freopen( "C-small-attempt1.out", "w", stdout );
	//freopen( "in.txt", "r", stdin );
	//freopen( "out.txt", "w", stdout );

	int test ; cin>>test ;

	myfor( i, 1, test )
	{ 
		cout<<"Case #"<<i<<": ";

		readin() ;
		work() ;
		//cout<<ans<<endl;

	}

	if( !seekeof( cin ) ) cout<<("wrong")<<endl;

	fclose( stdin ); fclose( stdout );
	return 0;
}
