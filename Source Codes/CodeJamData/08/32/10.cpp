// Jacek Migdal 2008 Google code jam
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 41;

long long DP[2][3][5][7][MAX];
char S[MAX];

int mod( int what, int modulo ) {
	return (what%modulo + modulo)%modulo;
}

long long dp( int div2, int div3, int div5, int div7, int pos ) {
	//printf( "S[%d] = %c\n", pos, S[pos] );
	if( S[pos]==0 ) {
		if( div2==0 || div3==0 || div5==0 || div7==0 )
			return 1;
		else
			return 0;
	}
	long long& ret = DP[div2][div3][div5][div7][pos];
	if( ret!=-1 )
		return ret;
	ret = 0;
	int num2 = 0, num3 = 0, num5 = 0, num7 = 0;
	for( int size = 1 ; S[size+pos-1]!=0 ; size++ ) {
		int add = S[size+pos-1]-'0';
		num2 = (num2*10+add)%2;
		num3 = (num3*10+add)%3;
		num5 = (num5*10+add)%5;
		num7 = (num7*10+add)%7;
		ret += dp( (div2+num2)%2, (div3+num3)%3, (div5+num5)%5, (div7+num7)%7, size+pos );
		if( pos!=0 ) {
			ret += dp( mod((div2-num2),2) , mod((div3-num3), 3), mod( (div5-num5), 5), mod((div7-num7), 7), size+pos );
		}

	}
	

	//printf( "dp( %d, %d, %d, %d, %d ) = %d\n", div2, div3, div5, div7, pos, ret );
	return ret;
}

void doIt() {
	scanf( "%s", S);
	for( int i1 = 0 ; i1<2 ; i1++ ) {
		for( int i2 = 0 ; i2<3 ; i2++ ) {
			for( int i2a = 0 ; i2a<5 ; i2a++ ) {
				for( int i3 = 0 ; i3<7 ; i3++ ) {
					for( int i4 = 0 ; i4<MAX ; i4++ )
						DP[i1][i2][i2a][i3][i4] = -1;
				}
			}
		}
	}

	printf( "%lld\n", dp( 0, 0, 0, 0, 0 ) );
}

int main() {
	int nTests;
	scanf( "%d", &nTests);
	for( int i = 0 ; i<nTests ; i++ ) {
		printf("Case  #%d: ", i+1);
		doIt();
	}
	return 0;
}
