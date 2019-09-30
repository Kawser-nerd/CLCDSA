#include <myheading.h>

const int MAXN = 1000 ;

int a[ MAXN+1 ];
int n , m , k ;
int64 ans ;

void readin()
{
	cin >> k >> m >> n ;
	myfor( i, 1, n ) cin>>a[i] ;
	sort( a+1, a+n+1 ) ;
}

void work()
{
	ans = 0;

	int i = 1 , p = 0 , l = 1 ;
	for( i=n; i>=1; --i )
	{
		++ p ;
		if( p>m ) p = 1 , ++l ;

		ans += a[i] * l ;
		
	}
}


int main()
{
	freopen( "A-large.in", "r", stdin );
	freopen( "A-large.out", "w", stdout );
	//freopen( "A-small-attempt0.in", "r", stdin );
	//freopen( "A-small-attempt0.out", "w", stdout );
	//freopen( "in.txt", "r", stdin );
	//freopen( "out.txt", "w", stdout );

	int test ; cin>>test ;

	myfor( i, 1, test )
	{
		cout<<"Case #"<<i<<": ";

		readin() ;
		work() ;
		cout<<ans<<endl;

	}

	if( !seekeof( cin ) ) cout<<("wrong")<<endl;

	fclose( stdin ); fclose( stdout );
	return 0;
}
