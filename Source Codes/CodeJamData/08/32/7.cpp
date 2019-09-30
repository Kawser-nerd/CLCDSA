#include <myheading.h>

const int MAXN = 40 ;

string s ;
int n; 

int a[ MAXN+1 ];

void readin()
{
	cin >> s ;
	n = mysize(s) ;
	myfor( i, 1, n ) a[i] = s[i-1]-'0' ;
}

unsigned long long f[ MAXN+1 ][ 500 ] ;
const int mod = 210 ;

int getnum( int c, int d )
{
	int re = 0;
	myfor( p, c, d )
		re = ( re*10 + a[p] ) % mod ;

	return re ;
}

void work()
{
	memset( f, 0, sizeof(f) ) ;
	f[0][0] = 1 ;

	int i, j, k, x, t ;
	for( i=1; i<=n; ++i )
	{
		x = getnum( 1, i ) ;
		f[i][x] += 1 ;

		for( j=2; j<=i; ++j )
		{
			x = getnum( j, i ) ;

			for( k=0; k<mod; ++k )
			{
				t = ( k + x ) % mod ;
				f[i][t] += f[j-1][k] ;

				t = ( k - x + mod ) % mod ;
				f[i][t] += f[j-1][k] ;
			}
		}
	}

	unsigned long long ans = 0;
	myfor( i, 0, mod )
		if( i % 2==0 || i%3==0 || i%5==0 || i%7==0 ) ans += f[n][i] ;

	cout<<ans<<endl;
}


int main()
{
	freopen( "B-large.in", "r", stdin );
	freopen( "B-large.out", "w", stdout );
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
		//cout<<ans<<endl;

	}

	if( !seekeof( cin ) ) cout<<("wrong")<<endl;

	fclose( stdin ); fclose( stdout );
	return 0;
}
