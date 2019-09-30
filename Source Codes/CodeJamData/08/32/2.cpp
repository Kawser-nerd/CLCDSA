#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;

long long DP[50][210][210][2];

long long solve( const string &s, int pos, int rem, int remlast, bool plus )
{
	if( pos >= s.size() ){
		if(
			(rem + remlast) % 2 == 0 ||
			(rem + remlast) % 3 == 0 ||
			(rem + remlast) % 5 == 0 ||
			(rem + remlast) % 7 == 0
		)
			return 1;
		else
			return 0;
	}
	long long &res = DP[pos][rem][remlast][plus?1:0];
	if( res >= 0 ) return res;
	res = 
		solve( s, pos + 1, rem, (plus ? (remlast * 10 + s[pos] - '0') : (remlast * 10 - (s[pos] - '0') + 210)) % 210, plus )
	+   solve( s, pos + 1, (rem + remlast) % 210, (s[pos] - '0'), true )
	+   solve( s, pos + 1, (rem + remlast) % 210, (210 - (s[pos] - '0')) % 210, false )
	;
	return res;
}

int main( void )
{
	int N;
	cin >> N;
	for( int C = 0; C < N; C ++ ){
		string s;
		cin >> s;
		memset( DP, 0xff, sizeof(DP) );
		printf( "Case #%d: %lld\n", C + 1, solve( s, 1, 0, s[0] - '0', true ) );
	}
}
