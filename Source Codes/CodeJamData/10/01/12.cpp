#include <cstdio>

int main() {
	int cases;
	int a , b;
	int i = 0;

	scanf ( "%d" , &cases );
	while ( cases -- ) {
		scanf ( "%d%d" , &a , &b );
		
		b %= (1 << a);
		
		printf ( "Case #%d: " , ++ i );
		
		if ( (b + 1) == (1 << a) )
			printf ( "ON\n" );
		else
			printf ( "OFF\n" );
	}
	
	return 0;
}
