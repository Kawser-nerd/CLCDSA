#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double SQR = sqrt ( 5. );

int lo[1 << 20] , hi[1 << 20];
int A1 , A2 , B1 , B2;

void read() {
	scanf ( "%d%d%d%d" , &A1 , &A2 , &B1 , &B2 );
}

void solve() {
	long long ans = 0;
	int i;
	int l , r;
	
	for (i = A1; i <= A2; i++) {
		l = B1;
		r = B2;
		
		if ( lo[i] > l ) l = lo[i];
		if ( hi[i] < r ) r = hi[i];
		
		if ( l <= r )
			ans += (long long)(r - l + 1);
	}
	
	printf ( "%lld\n" , (long long)(A2 - A1 + 1) * (long long)(B2 - B1 + 1) - ans );
}

int main() {
	int i , cases;
	
	lo[1] = 1;
	for (i = 2; i < (1 << 20); i++)
		lo[i] = i + 1 - lo[ lo[i - 1] ];
	
	for (i = 1; i < (1 << 20); i++)
		hi[i] = (int)((double)i * (SQR + 1.) / 2.);
	
	scanf ( "%d" , &cases );
	for (i = 1; i <= cases; i++) {
		printf ( "Case #%d: " , i );
		
		read();
		solve();
	}
	
	return 0;
}
