#include<stdio.h>
#include<set>
#include<map>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int m_solve( int i, vector<int> &v2u, vector<int> &visited, vector< vector< int > > &edge )
{
	for( vector<int>::iterator e = edge[i].begin(); e != edge[i].end(); e ++ ){
		int j = *e;
		if( visited[j] )
			continue;
		visited[j] = 1;
		if( v2u[j] < 0 || m_solve( v2u[j], v2u, visited, edge ) == 0 ){
			v2u[j] = i;
			return 0;
		}
	}
	return -1;
}

int maxmatch( int u, int v, vector< vector< int > > &edge, vector<int> &v2u )
{
	for( int i = 0; i < v; ++ i )
		v2u[i] = -1;

	vector<int> u_used( u, 0 );
	vector<int> v_visited( v, 0 );
	int r = 0;
	while( 1 ){
		int modified = 0;
		for( int i = 0; i < u; i ++ ){
			if( u_used[i] == 0 ){
				if( m_solve( i, v2u, v_visited, edge ) == 0 ){
					u_used[i] = 1;
					modified = 1;
					r ++;
				}
				for( int j = 0; j < v; j ++ )
					v_visited[j] = 0;
			}
		}
		if( modified == 0 )
			break;
	}
	return r;
}

map< pair< pair<int,int>, pair<int,int> >, bool > DP;

bool po( const vector< vector<int> > &L, int i, int ip, 
		 const vector< vector<int> > &S, int j, int jp )
{
	pair< pair<int,int>, pair<int,int> > key( pair<int,int>(i,ip),  pair<int,int>(j,jp) );
	map< pair< pair<int,int>, pair<int,int> >, bool >::iterator it = DP.find( key );
	if( it != DP.end() ) return it->second;

	bool ret;

	vector< vector<int> > edge(L.size());
	for( vector<int>::const_iterator it = L[i].begin(), ite = L[i].end(); it != ite; ++ it ){
	for( vector<int>::const_iterator jt = S[j].begin(), jte = S[j].end(); jt != jte; ++ jt ){
		if( *it == ip || *jt == jp ) continue;
		if( po( L, *it, i, S, *jt, j ) )
			edge[*it].push_back(*jt);
	}}

	int Ssize = S[j].size();
	if( jp >= 0 ) Ssize --;

	vector<int> v2u(S.size());
	ret = ( maxmatch( L.size(), S.size(), edge, v2u ) == Ssize );

	DP[key] = ret;
	return ret;
}

int main( void )
{
	int C;
	cin >> C;
	for( int CC = 0; CC < C; CC ++ ){
		int N; cin >> N; vector< vector<int> > L(N); for( int i = 0; i < N - 1; i ++ ){ int a, b; cin >> a >> b; -- a, -- b; L[a].push_back(b); L[b].push_back(a); }
		int M; cin >> M; vector< vector<int> > S(M); for( int i = 0; i < M - 1; i ++ ){ int a, b; cin >> a >> b; -- a, -- b; S[a].push_back(b); S[b].push_back(a); }

		DP.clear();
		bool f_po = false;
		for( int i = 0; i < N; i ++ ){
			if( po( L, i, -1, S, 0, -1 ) ){
				f_po = true;
				break;
			}
		}

		printf( "Case #%d: %s\n", CC + 1, f_po ? "YES" : "NO" );
	}
}

