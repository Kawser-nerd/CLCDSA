#pragma comment( linker, "/stack:128000000" )
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>

void prepare( )
{
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
}

#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <sstream>
#include <iostream>
#include <deque>

using namespace std;

#define fo(a,b,c) for(a =(b);a<(c);++a)
#define fr(a,b) fo(a,0,(b))
#define fi(a) fr(i,(a))
#define fj(a) fr(j,(a))
#define fk(a) fr(k,(a))
#define all(a) (a).begin(),(a).end()
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define _(a,b) memset((a),(b),sizeof(a))
#define __(a) _((a),0)

typedef long long lint;

const int MAXN = 256;

int n, m;
int a[MAXN];
int b[MAXN];

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	string s, s1;
	cin >> tn;
	fr( t, tn )
	{
		printf( "Case #%d: ", t + 1 );
		cin >> s;
		s1 = s;
		sort( all( s1 ) );
		n = unique( all( s1 ) ) - s1.begin( );
		n = max( n, 2 );
		int cnt = 0;
		_( a, -1 );
		fi( sz( s ) )
		{
			if ( a[s[i]] < 0 )
			{
				a[s[i]] = cnt++;
				if ( a[s[i]] == 0 )
					a[s[i]] = 1;
				else
				if ( a[s[i]] == 1 )
					a[s[i]] = 0;
			}
			b[i] = a[s[i]];								
		}
		lint ans = 0;
		lint st = 1;
		for ( i = sz( s ) - 1; i >= 0; -- i )
		{
			ans += st * (lint)b[i]; 
			st *= n;
		}
		cout << ans << "\n";
	}
	return 0;
}