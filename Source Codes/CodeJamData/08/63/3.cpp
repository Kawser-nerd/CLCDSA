#include<stdio.h>
#include<set>
#include<map>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main( void )
{
	int C;
	cin >> C;
	vector< pair<long double,long double> > w2, w3;

	for( int CC = 0; CC < C; CC ++ ){
		int M, X;
		double P;
		cin >> M >> P >> X;

		vector< pair<long double,long double> > w;
		w.push_back( pair<long double,long double>(1000000.0, 1) );
		w.push_back( pair<long double,long double>(0.0, 0) );

		for( int t = 0; t < M; t ++ ){
			w2.clear();
			w2.push_back( pair<long double,long double>(0.0, 0) );
			w2.push_back( pair<long double,long double>(1000000.0, 1) );

			for( int i = 0; i < w.size(); i ++ ){
				w3.clear();
				int T = 0;
				double pmin = -1;
				for( int j = (int)w.size() - 1; j >= i; -- j ){
					long double dmin = (w[i].first + w[j].first) * 0.5;
					long double p    = (w[i].second * P + w[j].second * (1.0 - P));

					for(; T < w2.size() && w2[T].first < dmin; T ++ ){
						if( pmin < w2[T].second ){
							w3.push_back( w2[T] );
							pmin = w2[T].second;
						}
					}

					if( pmin < p ){
						if( T < w2.size() && w2[T].first == dmin ){
							if( w2[T].second < p ){
								w3.push_back( pair<long double,long double>(dmin, p) );
								pmin = p;
								T ++;
							}
							else{
								w3.push_back( w2[T] );
								pmin = w2[T].second;
								T ++;
							}
						}
						else{
							w3.push_back( pair<long double,long double>(dmin, p) );
							pmin = p;
						}
					}
				}

				for(; T < w2.size(); T ++ ){
					if( pmin < w2[T].second ){
						w3.push_back( w2[T] );
						pmin = w2[T].second;
					}
				}

				w2.swap(w3);
			}
			sort( w2.begin(), w2.end() );
			w.clear();
			w.push_back( pair<long double,long double>(0.0, 0) );
			long double p = 0;
			for( int i = 0; i < w2.size(); i ++ ){
				if( w2[i].second > p ){
					w.push_back( pair<long double,long double>(w2[i].first, w2[i].second) );
					p = w2[i].second;
				}
			}
			reverse( w.begin(), w.end() );
//			cerr << w.size() << endl;
		}

		double ret = 0;
		for( int i = 0; i < w.size(); i ++ ){
			if( X >= w[i].first )
				ret = max( ret, (double)w[i].second );
		}

		printf( "Case #%d: %.20lf\n", CC + 1, ret );
	}
}

