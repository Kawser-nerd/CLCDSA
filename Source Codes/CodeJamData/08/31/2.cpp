#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;

int main( void )
{
	int N;
	cin >> N;
	for( int C = 0; C < N; C ++ ){
		int P, K, L;
		cin >> P >> K >> L;
		vector<long long> F;
		for( int i = 0; i < L; i ++ ){
			int t;
			cin >> t;
			F.push_back( t );
		}
		sort( F.rbegin(), F.rend() );
		long long r = 0;
		for( int i = 0; i < L; i ++ ){
			r += F[i] * (i / K + 1);
		}
		printf( "Case #%d: %lld\n", C + 1, r );
	}
}
