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

const double eps = 1e-8;

struct C
{
	double x, y, z;
	double sqrDist( ) { return x * x + y * y + z * z ; }
	double dist( ) { return sqrt( sqrDist( ) ); }
	void read( ) { cin >> x >> y >> z; }
	C( ) { x = y = z = 0; }
	C( double _x, double _y, double _z ): x( _x ), y( _y ), z( _z ) { }
};

bool eq( const double &a, const double &b ) { return a - b < eps && b - a < eps; }
C operator-( const C &a, const C &b ) {	return C( a.x - b.x, a.y - b.y, a.z - b.z ); }
C operator+( const C &a, const C &b ) {	return C( a.x + b.x, a.y + b.y, a.z + b.z ); }
C operator*( const C &a, const double &b ) { return C( a.x * b, a.y * b, a.z * b ); }
C operator/( const C &a, const double &b ) { return C( a.x / b, a.y / b, a.z / b ); }
bool operator == ( const C &a, const C &b ) { return eq( a.x, b.x ) && eq( a.y, b.y ) && eq( a.z, b.z ); }

C vect( const C &a, const C &b )
{
	C res;
	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return res;
}

double mult( const C &a, const C &b )
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

const int MAXN = 505;

int n, m;
C a[MAXN];
C v[MAXN];
C sa, sv;

double test( double t )
{
	return ( sa + sv * t ).dist( );
}

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	cin >> tn;
	fr( t, tn )
	{
		printf( "Case #%d: ", t + 1 );
		scanf( "%d", &n );
		sa = C( );
		sv = C( );
		fi( n )
		{
			a[i].read( );
			sa = sa + a[i];
			v[i].read( );
			sv = sv + v[i];
		}
		sa = sa / n;
		sv = sv / n;
		double anst = 0;
		double ans = test( 0. );
		double l = 0, r = 1e+10, ml, mr;
		fi( 120 )
		{
			ml = ( l + l + r ) / 3.;
			mr = ( l + r + r ) / 3.;
			if ( test( ml ) < test( mr ) )
				r = mr;
			else
				l = ml;
		}
		double ct = test( l );
		if ( ct < ans )
		{
			ans = ct;
			anst = l;
		}
		printf( "%.12lf %.12lf\n", ans, anst );
	}
	return 0;
}