#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

#define F first
#define S second
typedef pair< int, int > pii;

map< int, int > exist[2000];
vector< int > room[2000];
vector< pii > edge[2000];
map< pii, int > found;
int out[2100];
int u[2100];
int v[2100];
int color;
int top;

void dfs( int index, int r ){
	int uu = u[index];
	int vv = v[index];
	int a = exist[r][uu];
	int b = exist[r][vv];
	int n = room[r].size();
	int m = 2;
	int c = 0;
	int i;
//	cout << "dfs: " << index << " " << uu << " " << vv << " " << r << " " << a << " " << b << endl;
	
	if ( a > b )	swap( a, b );
	if ( a == 0 && b == n - 1 ){ a = n - 1; b = n; }
	for ( i = b + 1; i < n + a; i ++ ){
		if ( m ++ < color ){
			while ( c == out[uu] || c == out[vv] ){
				c ++;
				if ( c >= color )
					c -= color;
			}
			out[ room[r][i%n] ] = c ++;
		}
		else
			out[ room[r][i%n] ] = c ++;
		if ( c >= color )
			c -= color;
	}
	if ( out[ room[r][(i-1)%n] ] == out[ room[r][a] ] ){
		out[ room[r][(i-1)%n] ] ++;
		if ( out[ room[r][(i-1)%n] ] >= color )
			out[ room[r][(i-1)%n] ] -= color;
	}
	for ( i = 0; i < edge[r].size(); i ++ )
		if ( edge[r][i].F != index )
			dfs( edge[r][i].F, edge[r][i].S );
}

main(){
	int t, tt = 0;
	int n, m, i, j, k;
	int a, b;
	
	freopen( "CL.in", "r", stdin );
	freopen( "CL.out", "w", stdout );
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d", &n, &m );
		for ( i = 0; i < m; i ++ )
			scanf ( "%d", u + i );
		for ( i = 0; i < m; i ++ )
			scanf ( "%d", v + i );
		top = 1;
		for ( i = 0; i < n; i ++ ){
			room[i].resize(0);
			edge[i].resize(0);
			exist[i].clear();
		}
		for ( i = 1; i <= n; i ++ ){
			room[0].push_back( i );
			exist[0][i] = i - 1;
		}
		
		for ( i = 0; i < m; i ++ ){
			if ( u[i] > v[i] )
				swap( u[i], v[i] );
			for ( j = 0; j < top; j ++ ){
				if ( exist[j].find( u[i] ) == exist[j].end() || exist[j].find( v[i] ) == exist[j].end() )
					continue;
				a = exist[j][ u[i] ];
				b = exist[j][ v[i] ];
				room[top].push_back( u[i] );
				for ( k = a + 1; k < b; k ++ )
					room[top].push_back( room[j][k] );
				room[top].push_back( v[i] );
				for ( k = 0; k < room[top].size(); k ++ )
					exist[top][ room[top][k] ] = k;
				for ( k = a + 1; k < b; k ++ )
					room[j].erase( room[j].begin() + a + 1 );
				exist[j].clear();
				for ( k = 0; k < room[j].size(); k ++ )
					exist[j][ room[j][k] ] = k;
				top ++;
				break;
			}
		}
		found.clear();
		for ( i = 0; i < m; i ++ )
			for ( j = 0; j < top; j ++ ){
				if ( exist[j].find( u[i] ) == exist[j].end() || exist[j].find( v[i] ) == exist[j].end() )
					continue;
				if ( found.find( make_pair( u[i], v[i] ) ) == found.end() )
					found[ make_pair( u[i], v[i] ) ] = j;
				else{
					edge[ found[ make_pair( u[i], v[i] ) ] ].push_back( make_pair( i, j ) );
					edge[ j ].push_back( make_pair( i, found[ make_pair( u[i], v[i] ) ] ) );
					break;
				}
			}
		/*
		for ( i = 0; i < top; i ++ ){
			for ( j = 0; j < room[i].size(); j ++ )
				cout << room[i][j] << "-" << exist[i][room[i][j]] << " ";
			cout << "--- ";
			for ( j = 0; j < edge[i].size(); j ++ )
				cout << edge[i][j].F << "-" << edge[i][j].S << " ";
			cout << endl;
		}
		*/
		m = n;
		for ( i = 0; i < top; i ++ )
			m = min( m, ( int )room[i].size() );
		memset ( out, -1, sizeof ( out ) );
		for ( i = 0; i < room[0].size(); i ++ )
			out[room[0][i]] = i % m;
		if ( room[0].size() % m == 1 )
			out[room[0][i-1]] ++;
		color = m;
		for ( i = 0; i < edge[0].size(); i ++ )
			dfs( edge[0][i].F, edge[0][i].S );
		
		printf( "Case #%d: %d\n", ++ tt, color );
		for ( i = 1; i <= n; i ++ )
			if ( i < n )
				printf( "%d ", out[i] + 1 );
			else
				printf( "%d", out[i] + 1 );
		printf( "\n" );
		/*
		int vst[2100];
		for ( i = 0; i < top; i ++ ){
			memset( vst, 0, sizeof ( vst ) );
			for ( j = 0; j < room[i].size(); j ++ ){
				vst[ out[ room[i][j] ] ] = 1;
				if ( out[ room[i][j] ] >= color )
					cout << "ERROR" << endl;
			}
			for ( j = 0; j < m; j ++ )
				if ( vst[j] == 0 )
					cout << "ERROR" << endl;
		}
		*/
	}
	
	return 0;
}
