#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main ( )
{
	ll ntc;
	cin >> ntc;
	for ( ll test = 1; test <= ntc; ++test ) {

		ll ans1 = 0, ans2 = 0, n;
		cin >> n;
		vector<ll> a ( n );
		for ( ll i = 0; i < n; ++i )
			cin >> a[i];

		ll speed = 0;
		for ( ll i = 0; i+1 < n; ++i )
			if ( a[i] > a[i+1] ) {
				ans1 += a[i] - a[i+1];
				speed = max ( speed, a[i]-a[i+1] );
			}

		if ( speed ) {
			for ( ll i = 0; i+1 < n; ++i )
				ans2 += min ( speed, a[i] );
		}

		printf ( "Case #%lld: %lld %lld\n", test, ans1, ans2 );
	}

	return 0;
}
