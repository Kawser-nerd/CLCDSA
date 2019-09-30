#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main ( )
{
	int ntc;
	cin >> ntc;
	for ( int test = 1; test <= ntc; ++test ) {

		int n;
		ll kth;
		cin >> n >> kth;
		vector<ll> a ( n );
		for ( int i = 0; i < n; ++i )
			cin >> a[i];

		ll lo = 1, hi = LLONG_MAX/10LL, mi;

		while ( lo < hi ) {
			mi = ( lo + hi ) / 2;
			ll started = 0, starting = 0;
			for ( int i = 0; i < n; ++i ) {
				started += ( (mi-1LL) + a[i] - 1LL ) / a[i];
				if ( (mi-1) % a[i] == 0 ) starting++;
			}
			if ( started < kth && kth <= started + starting ) {
				//at second mi, the kth starts
				lo = hi = mi;
				break;
			}

			if ( started + starting < kth ) lo = mi+1;
			else hi = mi;
		}
		mi = lo;

		ll started = 0;
		for ( int i = 0; i < n; ++i )
			started += ( mi-1LL + a[i] - 1LL ) / a[i];
		kth -= started;

		int ans = -1;
		for ( int i = 0; i < n; ++i )
			if ( (lo-1)%a[i] == 0 ) {
				if ( kth == 1 )
					ans = i+1;
				kth--;
			}

		printf ( "Case #%d: %d\n", test, ans );
	}

	return 0;
}
