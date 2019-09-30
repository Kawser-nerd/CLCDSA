#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10005;
const int MAXN = 6005;

int s , m;
int q[MAX] , w[MAX];

int next;
int num[MAXN][MAXN];
char u[MAXN * MAXN];
char wh[MAXN * MAXN];
char ful[MAXN * MAXN];
int fat[MAXN * MAXN];

vector < int > a[MAXN * MAXN];
vector < int > cor;
vector < int > edge;

int firstBridge;
int e[8];

void read() {
	int i;
	
	scanf ( "%d%d" , &s , &m );
	for (i = 1; i <= m; i++) {
		scanf ( "%d%d" , &q[i] , &w[i] );
	}
}

inline int ok ( int x , int y ) {
	if ( abs ( x - y ) >= s ) return 0;
	if ( x >= 2 * s ) return 0;
	if ( y >= 2 * s ) return 0;
	if ( x < 1 || y < 1 ) return 0;
	
	return 1;
}

inline void add_edge ( int x , int y ) {
	a[x].push_back ( y );
	a[y].push_back ( x );
}

void dfs2 ( int x ) {
	u[x] = 1;
	int i;
	
	for (i = 0; i < (int)a[x].size(); i++) {
		if ( u[ a[x][i] ] == -1 ) {
			dfs2 ( a[x][i] );
		}
	}
}

void dfs3 ( int x ) {
	u[x] = 1;
	int i;
	
	if ( wh[x] ) {
		e[ wh[x] - 1 ] = 1;
	}
	
	for (i = 0; i < (int)a[x].size(); i++) {
		if ( u[ a[x][i] ] == -1 ) {
			dfs3 ( a[x][i] );
		}
	}
}

int haveRing ( int x ) {
	return x >= firstBridge;
}

int haveBridge ( int x ) {
	memset ( u , 0 , sizeof u );
	int i;
	
	for (i = 1; i <= x; i++) {
		u[ num[ q[i] ][ w[i] ] ] = -1;
	}
	
	for (i = 0; i < (int)cor.size(); i++) {
		if ( u[ cor[i] ] == 1 ) {
			return 1;
		}
		
		if ( u[ cor[i] ] == -1 ) {
			dfs2 ( cor[i] );
		}
	}
	
	return 0;
} 

int haveFork ( int x ) {
	memset ( u , 0 , sizeof u );
	int i , j , cnt;
	
	for (i = 1; i <= x; i++) {
		u[ num[ q[i] ][ w[i] ] ] = -1;
	}
	
	for (i = 0; i < (int)edge.size(); i++) {
		memset ( e , 0 , sizeof e );
		
		if ( u[ edge[i] ] == -1 ) {
			dfs3 ( edge[i] );
		}
		
		cnt = 0;
		for (j = 0; j < 6; j++) cnt += e[j];
		
		if ( cnt >= 3 ) {
			return 1;
		}
	}
	
	return 0;
}

int par ( int x ) {
	if ( x == fat[x] ) return x;
	return fat[x] = par ( fat[x] );
}

void solve() {
	int i , j;
	int l , r , mid;
	int prnt = 0;
	
	fprintf ( stderr , "here\n" );
	
	firstBridge = m + 1;
	cor.clear();
	edge.clear();
	next = 0;
	for (i = 1; i <= 2 * s - 1; i ++) {
		for (j = 1; j <= 2 * s - 1; j ++) {
			if ( ok ( i , j ) ) {
// 				printf ( "%d   %d %d\n" , next , i , j );
				num[i][j] = ++ next;
				ful[ num[i][j] ] = 0;
				fat[ num[i][j] ] = num[i][j];
				wh[next] = 0;
				a[next].clear();
			}
		}
	}
	
	fprintf ( stderr , "here\n" );
	
	for (i = 1; i <= 2 * s - 1; i ++) {
		for (j = 1; j <= 2 * s - 1; j ++) {
// 			printf ( "%d %d\n" , i , j );
			
			if ( ok ( i , j ) ) {
				if ( ok ( i + 1 , j + 1 ) ) {
					add_edge ( num[i][j] , num[i + 1][j + 1] );
				}
				
				if ( ok ( i + 1 , j ) ) {
					add_edge ( num[i][j] , num[i + 1][j] );
				}
				
				if ( ok ( i , j + 1 ) ) {
					add_edge ( num[i][j] , num[i][j + 1] );
				}
				
				if ( !ok ( i + 1 , j + 1 ) || !ok ( i + 1 , j ) || !ok ( i , j + 1 ) || i == 1 || j == 1 ) {
					if ( i == 1 && j == 1 ) continue;
					if ( i == 1 && j == s ) continue;
					if ( i == s && j == 1 ) continue;
					if ( i == s && j == 2 * s - 1 ) continue;
					if ( i == 2 * s - 1 && j == s ) continue;
					if ( i == 2 * s - 1 && j == 2 * s - 1 ) continue;
		
					if ( i == 1 ) {
						wh[ num[i][j] ] = 1;
					}
					if ( j == 1 ) {
						wh[ num[i][j] ] = 2;
					}
					if ( i == 2 * s - 1 ) {
						wh[ num[i][j] ] = 3;
					}
					if ( j == 2 * s - 1 ) {
						wh[ num[i][j] ] = 4;
					}
					if ( i - j == s - 1 ) {
						wh[ num[i][j] ] = 5;
					}
					if ( j - i == s - 1 ) {
						wh[ num[i][j] ] = 6;
					}
		
					edge.push_back ( num[i][j] );
				}
			}
		}
	}
	
	cor.push_back ( num[1][1] );
	cor.push_back ( num[1][s] );
	cor.push_back ( num[s][1] );
	cor.push_back ( num[s][2 * s - 1] );
	cor.push_back ( num[2 * s - 1][s] );
	cor.push_back ( num[2 * s - 1][2 * s - 1] );
	
	fprintf ( stderr , "here\n" );
	
	for (i = 1; i <= m; i++) {
		ful[ num[ q[i] ][ w[i] ] ] = 1;
	}
	for (i = 0; i < (int)edge.size(); i++) {
		fat[ edge[i] ] = 1;
	}
	for (i = 0; i < (int)cor.size(); i++) {
		fat[ cor[i] ] = 1;
	}
	
	for (i = 1; i <= next; i++) {
		for (j = 0; j < (int)a[i].size(); j++) {
			if ( ful[i] == 0 && ful[ a[i][j] ] == 0 ) {
				fat[ par ( i ) ] = fat[ par ( a[i][j] ) ] = min ( par ( i ) , par ( a[i][j] ) );
			}
		}
	}
	
	fprintf ( stderr , "here\n" );
	
	for (i = m; i >= 1; i--) {
		int e = num[ q[i] ][ w[i] ];
		ful[e] = 0;
		
		for (j = 0; j < (int)a[e].size(); j++) {
			if ( ful[ a[e][j] ] == 0 ) {
				fat[e] = min ( fat[e] , par ( a[e][j] ) );
			}
		}
		
		for (j = 0; j < (int)a[e].size(); j++) {
			if ( ful[ a[e][j] ] == 0 ) {
				if ( par ( a[e][j] ) != fat[e] ) {
					if ( fat[e] == 1 ) {
						firstBridge = i;
					}
					
					fat[ par ( a[e][j] ) ] = fat[e];
				}
			}
		}
	}
	
	fprintf ( stderr , "here\n" );
	
	l = 1;
	r = m + 1;
	
	while ( l < r ) {
		mid = l + (r - l) / 2;
		
// 		printf ( "%d %d      %d\n" , l , r , mid );
		
		if ( !(haveBridge ( mid ) || haveRing ( mid ) || haveFork ( mid )) ) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	
	if ( l == m + 1 ) {
		printf ( "none\n" );
		return ;
	}
	
	if ( haveBridge ( l ) ) {
		printf ( "bridge" );
		prnt = 1;
	}
	
	if ( haveFork ( l ) ) {
		if ( prnt ) printf ( "-" );
		printf ( "fork" );
		prnt = 1;
	}
	
	if ( haveRing ( l ) ) {
		if ( prnt ) printf ( "-" );
		printf ( "ring" );
	}
	
	printf ( " in move %d\n" , l );
}

int main() {
	int i , cases;
	
	scanf ( "%d" , &cases );
	for (i = 1; i <= cases; i++) {
		read();
		printf ( "Case #%d: " , i );
		solve();
		
		fflush ( stdout );
	}
	
	return 0;
}
