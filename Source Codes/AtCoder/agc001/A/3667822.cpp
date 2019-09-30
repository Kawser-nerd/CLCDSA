#include <cstdio>
#include <algorithm>
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
const int MaxN = 200 + 5 ;
int N , L[MaxN] ;
int main() {
	N = Readin() ; N <<= 1 ; 
	for(register int i = 0 ; ++i <= N ; L[i] = Readin() ) ;
	sort( L + 1 , L + 1 + N ) ;
	for(register int i = 0 ; i <= N ; ++i )
		L[0] += L[i<<1|1] ;
	printf( "%d\n" , L[0] ) ;
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
./Main.cpp:21:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(register int i = 0 ; ++i <= N ; L[i] = Readin() ) ;
            ^~~~~~~~~
./Main.cpp:23:6: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        for(regis...