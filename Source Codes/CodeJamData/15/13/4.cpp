#include <bits/stdc++.h>
using namespace std;

typedef long double lf;
typedef complex<lf> pt;

const lf PI = acosl ( -1 );
const lf EPS = 1e-10;

#define TAM				3002

pt pol[TAM];
lf arr[2*TAM];

int main ( )
{
	int ntc;
	cin >> ntc;
	for ( int test = 1; test <= ntc; ++test ) {

		printf ( "Case #%d:\n", test );

		int n;
		cin >> n;
		for ( int i = 0; i < n; ++i ) {
			double a, b;
			cin >> a >> b;
			pol[i] = pt ( a, b );
		}

		for ( int s = 0; s < n; ++s ) {
			int ans = 0, sz = 0;
			for ( int i = 0; i < n; ++i )
				if ( i != s )
					arr[sz++] = arg(pol[i]-pol[s]);

			sort ( arr, arr+sz );
			for ( int i = 0; i < sz; ++i )
				arr[i+sz] = arr[i] + lf(2)*PI;

			for ( int i = 0, j = 0; j < 2*sz; ++j ) {
				while ( arr[i] + PI + EPS < arr[j] ) i++;
				ans = max ( ans, j-i+1 );
			}

			printf ( "%d\n", n-1-ans );
		}
	}

	return 0;
}
