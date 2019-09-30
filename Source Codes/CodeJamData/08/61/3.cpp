#include<stdio.h>
#include<set>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main( void )
{
	int C;
	cin >> C;
	for( int CC = 0; CC < C; CC ++ ){
		int N, M;
		cin >> N;
		set<int> nbW, nbH;
		set<int> bW, bH;
		set< pair<int,int> > b, nb;
		for( int i = 0; i < N; i ++ ){
			int H, W;
			string str;
			cin >> H >> W >> str;
			if( str == "NOT" ){
				cin >> str;
				nbW.insert( W );
				nbH.insert( H );
				nb.insert( pair<int,int>(H,W) );
			}
			else{
				bW.insert( W );
				bH.insert( H );
				b.insert( pair<int,int>(H,W) );
			}
		}

		int inf = 1000000;
		int W0 = inf, W1 = 0, H0 = inf, H1 = 0;
		for( set<int>::iterator it = bW.begin(), ite = bW.end(); it != ite; ++ it )
			W0 = min(W0, *it), W1 = max(W1, *it);
		for( set<int>::iterator it = bH.begin(), ite = bH.end(); it != ite; ++ it )
			H0 = min(H0, *it), H1 = max(H1, *it);

		printf( "Case #%d:\n", CC + 1 );
		cin >> M;
		for( int i = 0; i < M; i ++ ){
			int H, W;
			cin >> H >> W;
			pair<int,int> HW(H,W);

			int res;

			if( b.size() == 0 ){
				if( nb.find(HW) != nb.end() ){
					res = 1;
				}
				else{
					res = 2;
				}
			}
			else{
				int w0 = min(W,W0), w1 = max(W,W1),
					h0 = min(H,H0), h1 = max(H,H1);

				bool can_bird = true;
				for( set<pair<int,int> >::iterator it = nb.begin(), ite = nb.end(); it != ite; ++ it ){
					if( h0 <= it->first && it->first <= h1 && w0 <= it->second && it->second <= w1 )
						can_bird = false;
				}

				bool can_nonbird = true;
				if( W0 <= W && W <= W1 && H0 <= H && H <= H1 )
					can_nonbird = false;

				if( can_bird ){
					if( can_nonbird )
						res = 2;
					else
						res = 0;
				}
				else{
					res = 1;
				}
			}

			if( res == 0 ) printf( "BIRD\n" );
			if( res == 1 ) printf( "NOT BIRD\n" );
			if( res == 2 ) printf( "UNKNOWN\n" );
		}
	}
}

