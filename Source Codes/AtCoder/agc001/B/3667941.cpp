#include <cstdio>

using namespace std ;
typedef int Read ; // Here to change reading type
inline Read Readin() {
	register Read K = 0 , F = 1 ; register char C = getchar() ;
	while( C < '0' or C > '9' ) F = C == '-' ? -1 : 1 , C = getchar() ;
	while( C >= '0' and C <= '9' ) K = ( K << 3 ) + ( K << 1 ) + C - '0' , C = getchar() ;
	return F * K ;
}
inline Read Min( Read A , Read B ) { return A < B ? A : B ; }
inline Read Max( Read A , Read B ) { return A > B ? A : B ; }
inline Read Abs( Read A ) { return A < 0 ? -A : A ; }
#define I(X) freopen(#X".in","r",stdin)
#define O(X) freopen(#X".out","w",stdout)
#define CLO fclose(stdin),fclose(stdout)
int main() {
	long long N , X , Ans ;
	scanf( "%lld%lld" , &N , &X ) ;
	Ans = N ;
	N = N - X ;
	while( 1 ) {
		Ans += ( N / X ) * X << 1 ;
		if( N % X ) {
			long long T = X ;
			X = N % X ;
			N = T ;
		}
		else {
			Ans -= X ;
			break ;
		}
	}
	printf( "%lld\n" , Ans ) ;
	return 0 ;
} ./Main.cpp:6:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        register Read K = 0 , F = 1 ; register char C = getchar() ;
        ^~~~~~~~~
./Main.cpp:6:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        register Read K = 0 , F = 1 ; register char C = getchar() ;
        ^~~~~~~~~
./Main.cpp:6:32: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        register Read K = 0 , F = 1 ; register char C = getchar() ;
                                      ^~~~~~~~~
3 warnings generated.